#ifndef COMMANDLINKBUTTON_H
#define COMMANDLINKBUTTON_H

#include <QCommandLinkButton>

class CommandLinkButton : public QWidget
{
	Q_OBJECT
public:
	CommandLinkButton(QWidget* parent = nullptr);
	~CommandLinkButton();

private:
	QCommandLinkButton* cmmBtn;

private slots:
	void clickFunc();

};
#endif // COMMANDLINKBUTTON_H