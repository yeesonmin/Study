#include "MDI.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MDI w;
    w.show();
    return a.exec();
}
