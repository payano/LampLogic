/*
 * Mailbox.h
 *
 *  Created on: Sep 10, 2017
 *      Author: johan
 */

#ifndef MESSAGE_MAILBOX_H_
#define MESSAGE_MAILBOX_H_
#include "Mail.h"
#include <memory>

constexpr int MAX_INBOX_COUNT = 100;

class Mailbox {
private:
	const std::shared_ptr<Mail> mMails[MAX_INBOX_COUNT];
	int mMailCount;
	int mFrom;
	int mTo;

public:
	Mailbox();
	virtual ~Mailbox();
	void putMail(const std::shared_ptr<Mail> recieve);
	void getMail(const std::shared_ptr<Mail> send);
};

#endif /* MESSAGE_MAILBOX_H_ */
