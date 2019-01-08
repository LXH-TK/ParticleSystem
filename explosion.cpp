#include "explosion.h"

const float PI = 3.14159265358979f;

Explosion::Explosion() {
    cout << "Explosion" << endl;
}

Explosion::~Explosion() {
}

/**
 * @brief 圆形
 */
void Explosion::circle(Particle particle) {
    int count = 100;
    float angle = (PI*2) / count;

    while (count--) {
        float tempVel = 4 + rand()*4;
        float tempAngle = count * angle;
        // 位置
        float *p = particle.getPos();
        float pos[2];
        for(int i=0; i<2; i++) {
            pos[i] = *(p+i);
        }
        // 更新速度变化
        float vel[2];
        vel[0] = cos(tempAngle) * tempVel;
        vel[1] = sin(tempAngle) * tempVel;
        // 新加入粒子
        Canvas::createParticle(pos,
                               -1.0,
                               vel,
                               particle.getColor(),
                               true);
    }
}

/**
 * @brief 星形
 */
void Explosion::star(Particle particle) {
    int points = 6 + round((rand()/RAND_MAX) * 15);
    int jump = 3 + round((rand()/RAND_MAX) * 7);
    int subdivisions = 10;
    int radius = 80;
    float tempVel = -((rand()/RAND_MAX) * 3 - 6);

    int start = 0, end = 0;
    float circle = 2 * PI;
    float adjustment = (rand()/RAND_MAX) * circle;

    do {
        start = end;
        end = (end + jump) % points;

        float sAngle = (start/points) * circle - adjustment;
        float eAngle = ((start+jump)/points) * circle - adjustment;

        // 起始、结束、变化
        float* p = particle.getPos();
        float sPos[2], ePos[2];
        sPos[0] = *(p+0) + cos(sAngle)*radius;
        sPos[1] = *(p+1) + sin(sAngle)*radius;
        ePos[0] = *(p+0) + cos(eAngle)*radius;
        ePos[1] = *(p+1) + sin(eAngle)*radius;

        float diffPos[3];
        diffPos[0] = ePos[0] - sPos[0];
        diffPos[1] = ePos[1] - sPos[1];
        diffPos[2] = eAngle - sAngle;

        // 线性差值
        for(int i=0; i<subdivisions; i++) {
            float sub = i / subdivisions;
            float subAngle = sAngle + (sub*diffPos[2]);

            float pos[2];
            pos[0] = sPos[0] + (sub*diffPos[0]);
            pos[1] = sPos[1] + (sub*diffPos[1]);
            float vel[2];
            vel[0] = cos(subAngle) * tempVel;
            vel[1] = sin(subAngle) * tempVel;

            Canvas::createParticle(pos,
                                   -1.0,
                                   vel,
                                   particle.getColor(),
                                   true);
        }
    }while(end != 0);
}
