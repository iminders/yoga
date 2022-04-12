#include "yoga.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    yoga w;
    w.show();
    return a.exec();
}
