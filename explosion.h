#ifndef EXPLOSION_H
#define EXPLOSION_H

#include "canvas.h"


/**
 * @brief The Explosion class
 * Particle爆炸的类，在这个类中可以添加不同的烟花效果
 */
class Explosion {

public:
    Explosion();
    ~Explosion();
    static int radius;      // 烟花大小
    static int subdivisions;// 烟花簇数

    static void circle(Particle particle);
    static void star(Particle particle);
};

#endif // EXPLOSION_H
