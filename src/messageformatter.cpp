#include "messageformatter.h"

#include <IrcMessage>
#include <QString>

// TODO - Implement functions to format all message types
QString MessageFormatter::formatMessage(IrcPrivateMessage *msg)
{
	assert(!s_format.isEmpty());

	QString message = s_format;

	// Replace name placeholder
	message.replace(s_msg_pos, 2, msg->nick());

	// Replace message placeholder
	message.replace(s_name_pos, 2, msg->content());

	// Check if timestamp_pos is valid first, as it's an optional placeholder
	if (s_timestamp_pos != -1)
		message.replace(s_timestamp_pos, 2, msg->timeStamp().toString());

	return message;
}

// Convenience method that allows a format string to be passed with the message itself
QString MessageFormatter::formatMessage(IrcPrivateMessage *msg, const QString fmt)
{
	QString old_format = s_format;

	if (!setFormat(fmt)) {
		// TODO - log an error
	}

	QString message = formatMessage(msg);

	// Reset to original format again
	setFormat(old_format);

	return message;
}

const QString MessageFormatter::getFormat()
{
	return s_format;
}

bool MessageFormatter::setFormat(QString fmt)
{
	s_name_pos = fmt.indexOf("%N");
	if (s_name_pos == -1)
		return false;

	s_msg_pos = fmt.indexOf("%M");
	if (s_msg_pos == -1)
		return false;

	s_timestamp_pos = fmt.indexOf("%T");

	s_format = fmt;
	return true;
}
