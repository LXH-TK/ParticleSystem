#include "particle.h"

Particle::Particle() {
}

Particle::Particle(float pos[], float target, float vel[], int marker, bool usePhysics) {
    this->gravity = 0.06;
    this->alpha = 1;
    this->easing = rand()/float(RAND_MAX) * 0.02;
    this->fade = rand()/float(RAND_MAX) * 0.1;
    this->gridX = marker % 110;
    this->gridY = floor(marker/120) * 11;
    this->color = marker;

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

float Particle::getColor() {
    return this->color;
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
        this->vel[1] += this->gravity;
        this->pos[1] += this->vel[1];
        this->alpha -= this->fade;
    }
    else {
        float dis = this->target - this->pos[1];
        // ease the position
        this->pos[1] += dis * (0.03 + this->easing);
        // cap to 1
        this->alpha = min(dis*dis*0.00005, (double)1);
    }
    this->pos[0] += this->vel[0];         // 横向位置变化
    return (this->alpha < 0.005);
}

/**
 * @brief 绘制该粒子
 */
void Particle::render() {
    float x = round(this->pos[0]);
    float y = round(this->pos[1]);
    float xVel = (x-this->lastPos[0]) * (-5);
    float yVel = (y-this->lastPos[1]) * (-5);

    cout << xVel << yVel << endl;
}
