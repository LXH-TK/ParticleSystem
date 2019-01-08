#ifndef PARTICLE_H
#define PARTICLE_H

#include <iostream>
#include <stdlib.h>
#include <cmath>

using namespace std;


class Particle {

public:
    Particle();         // 默认构造函数
    Particle(float pos[], float target, float vel[], int marker, bool usePhysics);
    ~Particle();
    float* getPos();    // 获取粒子位置
    float getColor();   // 获取粒子颜色

private:
    float gravity;      // 加速度
    float alpha;
    float easing;
    float fade;
    int gridX;
    int gridY;
    float color;

    float pos[2];
    float lastPos[2];   // 粒子上一次的位置
    float vel[2];
    float target;
    bool usePhysics;

    bool update();
    void render();
};

#endif // PARTICLE_H
