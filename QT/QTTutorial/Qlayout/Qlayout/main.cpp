#include "Qlayout.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Qlayout w;
    w.show();
    return a.exec();
}
