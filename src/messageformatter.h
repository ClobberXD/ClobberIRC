#pragma once

#include <IrcMessage>

#include <QString>

/*
 * The following are valid placeholders for the message format:
 *
 * %N - Name of sender
 * %M - Message contents
 * %T - (Optional) timestamp
 *
 * Calling MessageFormatter::formatMessage will fail if format
 * hasn't been set using MessageFormatter::setFormat first.
 */

class MessageFormatter
{
public:
	// TODO - Implement functions to format all message types
	static QString formatMessage(IrcPrivateMessage *msg)
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
	static QString formatMessage(IrcPrivateMessage *msg, const QString fmt)
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

	static const QString getFormat()
	{
		return s_format;
	}

	static bool setFormat(QString fmt)
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

private:
	// Make ctor private to disallow instantiation
	MessageFormatter() {}

	static QString s_format;

	// Cache positions of placeholders while setting format for better performance
	static int s_name_pos;
	static int s_msg_pos;
	static int s_timestamp_pos;
};

