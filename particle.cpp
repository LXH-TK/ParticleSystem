#include "particle.h"

// 相对路径好像不行，只好用绝对路径了
QImage Particle::smallGlow("/Users/lixinhao/Desktop/Particle_System/small-glow.png");
QImage Particle::bigGlow("/Users/lixinhao/Desktop/Particle_System/big-glow.png");
float Particle::gravity = 0.06;
float Particle::easing = 0.02;
QColor Particle::color = QColor(1, 160, 250);

Particle::Particle() {
}

Particle::Particle(float pos[], float target, float vel[], bool usePhysics) {

    this->alpha = 1;
    this->fade = rand()/float(RAND_MAX) * 0.1;

    // 初始化成员变量
    this->pos[0] = pos[0];
    this->pos[1] = pos[1];
    this->lastPos[0] = this->pos[0];
    this->lastPos[1] = this->pos[1];
    this->vel[0] = vel[0];
    this->vel[1] = vel[1];
    this->target = target;
    this->usePhysics = usePhysics;
}

Particle::~Particle() {
}

float* Particle::getPos() {
    return this->pos;
}

float* Particle::getlastPos() {
    return this->lastPos;
}

bool Particle::getPhysics() {
    return this->usePhysics;
}

/**
 * @brief 该粒子信息更新
 * @return alpha过小时不进行绘制
 */
bool Particle::update() {
    this->lastPos[0] = this->pos[0];
    this->lastPos[1] = this->pos[1];

    if (this->usePhysics) {
        // 粒子位置变化，亮度变化
        this->vel[1] += gravity;
        this->pos[1] += this->vel[1];
        this->alpha -= this->fade;
    }
    else {
        float dis = this->target - this->pos[1];
        // ease the position
        this->pos[1] += dis * (0.03 + easing);
        // cap to 1
        this->alpha = min(dis*dis*0.00005, (double)1);
    }

    this->pos[0] += this->vel[0];         // 横向位置变化
    return (this->alpha < 0.005);
}


