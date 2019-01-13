#ifndef CANVAS_H
#define CANVAS_H

#include <QWidget>
#include <QPainter>
#include <QMouseEvent>
#include <vector>
#include <QTimer>
#include "particle.h"
#include "explosion.h"

using namespace std;

class Canvas : public QWidget {

public:
    explicit Canvas(QWidget *parent = 0);     // 避免隐式转化
    ~Canvas();
    static void createParticle(float pos[],
                               float target,
                               float vel[],
                               bool usePhysics);

private:
    QTimer *timer;
    static vector<Particle> mParticle;

protected:
    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *e);
};

#endif // CANVAS_H
