#include "appwindow.h"
#include "messageformatter.h"

#include <IrcConnection>
#include <IrcMessage>
#include <IrcCommandParser>

AppWindow::AppWindow(QWidget *parent) :
QMainWindow(parent)
{
	// Set up connection
	connection = new IrcConnection("irc.freenode.net", this);
	connection->setUserName("ClobberIRC");
	connection->setNickName("ClobberIRC");
	connection->setRealName("ClobberIRC (https://github.com/ClobberXD/ClobberIRC)");
	connection->sendCommand(IrcCommand::createJoin("#ClobberIRC"));
	connection->open();

	// Set up message format
	MessageFormatter::setFormat("[%T] <%N> %M");

	ui.setupUi(this);
	connectEventHandlers();
}

AppWindow::~AppWindow()
{
	connection->quit("Whoever just quit uses ClobberIRC. "
	"Check it out at https://github.com/ClobberXD/ClobberIRC now!");
}

void AppWindow::onReceivedMessage(IrcMessage *msg)
{
	ui.te_chat->append(MessageFormatter::formatMessage(
	static_cast<IrcPrivateMessage *>(msg)));
}

void AppWindow::connectEventHandlers()
{
	// Message handler
	connect(connection, SIGNAL(messageReceived(IrcMessage *)),
	this, SLOT(onReceivedMessage(IrcMessage *)));

	// UI event handlers
	// TODO
}




