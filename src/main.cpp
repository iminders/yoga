#include "yoga.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Yoga w;
    w.show();
    return a.exec();
}
