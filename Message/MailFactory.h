/*
 * MailFactory.h
 *
 *  Created on: Sep 10, 2017
 *      Author: johan
 */

#ifndef MESSAGE_MAILFACTORY_H_
#define MESSAGE_MAILFACTORY_H_
#include <memory>
#include <list>
#include "Message.h"
//MAKE THIS SINGLETON ASWELL!
class MailFactory {
public:
	MailFactory();
	virtual ~MailFactory();
	static void createMail(int from, int to, std::list<std::shared_ptr<Message>> messages);
};

#endif /* MESSAGE_MAILFACTORY_H_ */
