#pragma once

class IrcPrivateMessage;
class QString;

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
	static QString formatMessage(IrcPrivateMessage *msg);

	// Convenience method that allows a format string to be passed with the message itself
	static QString formatMessage(IrcPrivateMessage *msg, const QString fmt);

	static const QString getFormat();

	static bool setFormat(QString fmt);

private:
	// Make ctor private to disallow instantiation
	MessageFormatter() {}

	static QString s_format;

	// Cache positions of placeholders while setting format for better performance
	static int s_name_pos;
	static int s_msg_pos;
	static int s_timestamp_pos;
};

