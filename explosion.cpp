#include <math.h>
#include <stdlib.h>
#include "explosion.h"

const float PI = 3.14159265358979f;
int Explosion::radius = 80;
int Explosion::subdivisions = 10;

Explosion::Explosion() {
    cout << "Explosion()" << endl;
}

Explosion::~Explosion() {
    cout << "~Explosion()" << endl;
}

/**
 * @brief Explosion::circle 圆形轨迹
 * @param particle 传入的粒子
 */
void Explosion::circle(Particle particle) {

    int count = 100;
    float angle = (PI*2) / count;

    while (count--) {
        float tempVel = 4 + (rand()/float(RAND_MAX))*4;
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
                               -1,
                               vel,
                               true);
    }
}

/**
 * @brief Explosion::star 星形轨迹
 * @param particle 传入的粒子
 */
void Explosion::star(Particle particle) {

    int points = 6 + round(rand()/float(RAND_MAX) * 15);
    int jump = 3 + round(rand()/float(RAND_MAX) * 7);
    float tempVel = -((rand()/float(RAND_MAX)) * 3 - 6);

    int start = 0, end = 0;
    float circle = 2 * PI;
    float adjustment = (rand()/float(RAND_MAX)) * circle;

    do {
        start = end;
        end = (end + jump) % points;
        // 注意格式的转化
        float sAngle = (start/float(points)) * circle - adjustment;
        float eAngle = ((start+jump)/float(points)) * circle - adjustment;

        // 起始、结束、变化
        float *p = particle.getPos();
        float sPos[2], ePos[2];
        // 三角函数中为弧度值不是角度
        sPos[0] = *(p+0) + (cos(sAngle)*radius);
        sPos[1] = *(p+1) + (sin(sAngle)*radius);
        ePos[0] = *(p+0) + (cos(eAngle)*radius);
        ePos[1] = *(p+1) + (sin(eAngle)*radius);

        float diffPos[3];
        diffPos[0] = ePos[0] - sPos[0];
        diffPos[1] = ePos[1] - sPos[1];
        diffPos[2] = eAngle - sAngle;

        // 线性插值
        for(int i=0; i<subdivisions; i++) {
            // 注意这里的格式转化
            float sub = i / float(subdivisions);
            float subAngle = sAngle + (sub*diffPos[2]);

            float pos[2];
            pos[0] = sPos[0] + (sub*diffPos[0]);
            pos[1] = sPos[1] + (sub*diffPos[1]);
            float vel[2];
            vel[0] = cos(subAngle) * tempVel;
            vel[1] = sin(subAngle) * tempVel;

            Canvas::createParticle(pos,
                                   -1,
                                   vel,
                                   true);
        }

    }while(end != 0);
}



