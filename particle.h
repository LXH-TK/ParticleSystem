#ifndef PARTICLE_H
#define PARTICLE_H

#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <QPainter>

using namespace std;

class Particle {
public:
    static QImage smallGlow;
    static QImage bigGlow;
    static QColor color;       // 粒子颜色
    static float gravity;      // 加速度
    static float easing;       // 发射速度

    // 默认构造函数是必须的
    Particle();
    Particle(float pos[], float target, float vel[], bool usePhysics);
    ~Particle();

    // 获取粒子私有成员变量
    float* getPos();
    float* getlastPos();
    int getGridX();
    int getGridY();
    bool getPhysics();

    // 更新粒子坐标等信息
    bool update();


private:
    float alpha;
    float fade;

    float pos[2];       // 粒子当前位置
    float lastPos[2];   // 粒子上一次的位置
    float vel[2];       // 粒子两个方向上的速度
    float target;       // 粒子目标Y位置
    bool usePhysics;    // 区分上升阶段和爆炸阶段

};

#endif // PARTICLE_H
