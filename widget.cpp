#include "widget.h"
#include "ui_widget.h"


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget) {
    ui->setupUi(this);
    ui->layout->addWidget(&mCanvas);
}

Widget::~Widget() {
    delete ui;
}

// 交互部分
void Widget::on_resetButton_clicked() {
    float gravity = ui->gravitySpinBox->value();
    float send = ui->sendSpinBox->value();

    int R = ui->RspinBox->value();
    int G = ui->GspinBox->value();
    int B = ui->BspinBox->value();

    int size = ui->sizeSpinBox->value();
    int sub = ui->subSpinBox->value();

    Explosion::subdivisions = sub;
    Explosion::radius = size;
    Particle::gravity = gravity;
    Particle::easing = rand()/float(RAND_MAX) * send;
    Particle::color = QColor(R, G, B);
}
