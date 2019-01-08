#ifndef WIDGET_H
#define WIDGET_H

#include "canvas.h"


namespace Ui {
class Widget;
}

class Widget : public QWidget {
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private slots:
    void on_sendButton_clicked();

private:
    Ui::Widget *ui;
    Canvas mCanvas;
};

#endif // WIDGET_H
