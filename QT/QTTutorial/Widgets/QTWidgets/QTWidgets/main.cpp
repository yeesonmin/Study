#include "QTWidgets.h"
#include <QtWidgets/QApplication>
#include "CheckBox.h"
#include "ComboBox.h"
#include "CommandLinkButton.h"
#include "Date.h"
#include "TimeUI.h"
#include "DateTimeUI.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
   /* QTWidgets w;
    w.show();*/

    CheckBox checkbox;
    checkbox.show();

    ComboBox combobox;
    combobox.show();

    CommandLinkButton commandlinkbutton;
    commandlinkbutton.show();

    Date date;
    date.show();

    TimeUI timeui;
    timeui.show();

    DateTimeUI datetimeui;
    datetimeui.show();
    return a.exec();
}
