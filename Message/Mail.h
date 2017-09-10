/*
 * Mail.h
 *
 *  Created on: Sep 10, 2017
 *      Author: johan
 */

#ifndef MESSAGE_MAIL_H_
#define MESSAGE_MAIL_H_

#include <list>
#include <memory>
#include "Message.h"
class Mail {
private:
	std::list<std::shared_ptr<Message>> mMessages;

public:
	Mail();
	virtual ~Mail();
	const std::list<std::shared_ptr<Message>> getAllMessages();
	const std::shared_ptr<Message> getMessage(int messageNumber);

};

#endif /* MESSAGE_MAIL_H_ */
