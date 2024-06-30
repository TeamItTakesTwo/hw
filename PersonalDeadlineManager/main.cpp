#include "bubble.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Bubble w;
    w.show();
    return a.exec();
}
