#ifndef EXPLOSION_H
#define EXPLOSION_H

#include "canvas.h"

// Particle爆炸的类，添加粒子
class Explosion {

public:
    Explosion();
    ~Explosion();

private:
    void circle(Particle particle);
    void star(Particle particle);
};

#endif // EXPLOSION_H
