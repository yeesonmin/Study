#include "Memo.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Memo w;
    w.show();
    return a.exec();
}
