#include "QTWidgets.h"
#include <QtWidgets/QApplication>
#include "CheckBox.h"
#include "ComboBox.h"
#include "CommandLinkButton.h"
#include "Date.h"
#include "TimeUI.h"
#include "DateTimeUI.h"
#include "DialUI.h"
#include "SpinBoxUI.h"
#include "PushButtonUI.h"
#include "Label_LCDNumberUI.h"
#include "LineEditUI.h"
#include "MenuUi.h"
#include "ProgressbarUI.h"
#include "RadioButtonUI.h"
#include "ScrollAreaUI.h"
#include "SizeGripUI.h"
#include "SliderUI.h"
#include "TabwidgetUI.h"
#include "ToolBarUI.h"
#include "WidgetUI.h"
#include "ToolBoxUI.h"
#include "ToolButton.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
   /* QTWidgets w;
    w.show();*/

    //CheckBox checkbox;
    //checkbox.show();

    //ComboBox combobox;
    //combobox.show();

    //CommandLinkButton commandlinkbutton;
    //commandlinkbutton.show();

    //Date date;
    //date.show();

    //TimeUI timeui;
    //timeui.show();

    //DateTimeUI datetimeui;
    //datetimeui.show();

    //DialUI dialui;
    //dialui.show();

    /*SpinBoxUI _SpinBoxUI;
    _SpinBoxUI.show();

    PushButtonUI _PushButtonUI;
    _PushButtonUI.show();

    Label_LCDNumberUI _Label_LCDNumberUI;
    _Label_LCDNumberUI.show();

    LineEditUI _LineEditUI;
    _LineEditUI.show();

    MenuUi _MenuUi;
    _MenuUi.show();

    ProgressbarUI _ProgressbarUI;
    _ProgressbarUI.show();

    RadioButtonUI _RadioButtonUI;
    _RadioButtonUI.show();

    ScrollAreaUI _ScrollAreaUI;
    _ScrollAreaUI.show();*/

   /* SizeGripUI _SizeGripUI;
    _SizeGripUI.resize(400, 300);
    SubWindow subWindow(&_SizeGripUI);
    subWindow.move(200, 180);
    _SizeGripUI.show();*/

    SliderUI _SliderUI;
    _SliderUI.show();

    TabwidgetUI _TabwidgetUI;
    _TabwidgetUI.show();

    ToolBarUI _ToolBarUI;
    _ToolBarUI.show();

    WidgetUI _WidgetUI;
    _WidgetUI.show();

    ToolBoxUI _ToolBoxUI;
    _ToolBoxUI.show();

    ToolButton _ToolButton;
    _ToolButton.show();
    return a.exec();
}
