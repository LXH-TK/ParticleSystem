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

void Widget::on_sendButton_clicked() {
    cout << "clicked" << endl;
}
