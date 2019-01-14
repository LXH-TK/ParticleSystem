#include "canvas.h"

// 静态变量需要进行初始化，否则编译通过连接错误
vector<Particle> Canvas::mParticle;

Canvas::Canvas(QWidget *parent) : QWidget(parent) {
    this->setStyleSheet("background-color:#0E0E0E");

    // 每隔一段时间刷新一次
    timer = new QTimer;
    // Qtimer的槽位处理刷新的update()函数
    // 当达到超时时间，则发射信号，执行指定的槽函数
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    timer->setInterval(30);
    // 开启定时器
    timer->start();
}

Canvas::~Canvas() {
    // 关闭定时器
    timer->stop();
}

void Canvas::paintEvent(QPaintEvent *) {
    QPainter painter(this);

    int length = mParticle.size();

    while (length--) {
        // []比at性能要好
        Particle &p = mParticle[length];
        Particle pp = mParticle[length];
        // 返回true则应该explosion
        if (p.update()) {
            pp = mParticle[length];
            // 删除最后一个
            mParticle.pop_back();
            // 返回false，safely explode it
            if (!p.getPhysics()) {
                if((rand()/float(RAND_MAX)) < 0.8)
                    Explosion::star(p);
                else
                    Explosion::circle(p);
            }
        }
        else
            pp = mParticle[length];

        // 绘制该粒子
        float *pos = pp.getPos();
        float *lastPos = pp.getlastPos();
        float x = round(*(pos+0));
        float y = round(*(pos+1));
        float xVel = (x - *(lastPos+0)) * -5;
        float yVel = (y - *(lastPos+1)) * -5;
        QPainterPath path;
        path.moveTo(*(pos+0), *(pos+1));
        path.lineTo(*(pos+0) + 1, *(pos+1));
        path.lineTo(*(pos+0) + xVel, *(pos+1) + yVel);
        path.lineTo(*(pos+0) - 1, *(pos+1));
        path.setFillRule(Qt::OddEvenFill);
        path.closeSubpath();    // 添加一条直线(当前到起始位置)关闭当前路径

        // 抗锯齿
        painter.setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform | QPainter::Qt4CompatiblePainting);
        painter.setPen(Particle::color);
        painter.setBrush(Particle::color);
        painter.drawPath(path);

        painter.drawImage(x-3, y-3, Particle::smallGlow);
    }
}

void Canvas::mousePressEvent(QMouseEvent *e) {

    float pos[2] = {-1, -1}, vel[2] = {-10000, -10000};
    createParticle(pos, -1, vel, false);
}

// 静态成员函数只需要在类中声明
void Canvas::createParticle(float pos[], float target, float vel[], bool usePhysics) {
    // 画布宽度的一半
    if (pos[0] < 0)
        pos[0] = 415;
    // 画布下方
    if (pos[1] < 0)
        pos[1] = 650;
    if (target == -1)
        target = 100 + (rand()/float(RAND_MAX)) * 100;
    if (vel[0] == -10000)
        vel[0] = (rand()/float(RAND_MAX)) * 3 - 1.5;
    if (vel[1] == -10000)
        vel[1] = 0;

    Particle p(pos, target, vel, usePhysics);
    mParticle.push_back(p);
}



