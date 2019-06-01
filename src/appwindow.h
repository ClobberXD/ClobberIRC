#pragma once

#include "ui_appwindow.h"

class IrcConnection;
class IrcCommandParser;
class IrcMessage;

class AppWindow : public QMainWindow
{
	Q_OBJECT

public:
	explicit AppWindow(QWidget *parent = nullptr);
	~AppWindow();

public slots:

private slots:
	void onReceivedMessage(IrcMessage *msg);

private:
	void connectEventHandlers();

	IrcConnection *connection;
	IrcCommandParser *parser;

	Ui::AppWindow ui;
};
