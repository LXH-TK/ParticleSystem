#include "widget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    // 在这里初始化随即种子
    srand((unsigned)time(0));
    QApplication a(argc, argv);
    Widget w;
    w.show();

    return a.exec();
}
