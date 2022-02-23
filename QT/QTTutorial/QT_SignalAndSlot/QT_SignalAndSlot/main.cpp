#include "QT_SignalAndSlot.h"
#include <QtWidgets/QApplication>
#include "Test.h"
#include "Test2.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QT_SignalAndSlot w;
    w.show();

    Test test;
    test.show();

    Test2 test2;
    test2.show();
    return a.exec();
}
