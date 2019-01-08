#include "canvas.h"

Canvas::Canvas(QWidget *parent) : QWidget(parent) {
    this->setStyleSheet("background-color:#0E0E0E");

}

Canvas::~Canvas() {
}

// 静态成员函数只需要在类中声明
void Canvas::createParticle(float pos[], float target, float vel[], float color, bool usePhysics) {
    // 画布宽度的一半
    if (pos[0] < 0)
        pos[0] = 415;
    // 画布下方
    if (pos[1] < 0)
        pos[1] = 650;
    if (target == -1)
        target = 150 + (rand()/RAND_MAX) * 100;
    if (color == -1)
        color = floor((rand()/RAND_MAX) * 100) * 11;
    Particle p = Particle(pos,
                          target,
                          vel,
                          color,
                          usePhysics);
    mParticle.push_back(p);
}

void Canvas::paintEvent(QPaintEvent *) {
    QPainter painter(this);

    // 反走样
    painter.setRenderHint(QPainter::Antialiasing, true);
    // 设置画笔颜色、宽度
    painter.setPen(QPen(QColor(0, 160, 230), 2));
    // 绘制椭圆
    painter.drawEllipse(QPointF(120, 60), 50, 20);
    // 设置画刷颜色
    painter.setBrush(QColor(255, 160, 90));
    // 绘制圆
    painter.drawEllipse(QPointF(120, 140), 40, 40);


}

void Canvas::mousePressEvent(QMouseEvent *e) {
    cout << e->x() << endl;
}
