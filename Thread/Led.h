/*
 * Led.h
 *
 *  Created on: Sep 7, 2017
 *      Author: johan
 */

#ifndef LED_H_
#define LED_H_
#include "Message.h"
#include <memory>
#include "IThread.h"
#include "Mailbox.h"

class Led : public IThread {
private:
	std::shared_ptr<Mailbox> mInbox;
	std::shared_ptr<Mailbox> mOutboxMrf24j;
	std::shared_ptr<Mailbox> mOutboxButton;
public:
	Led();
	Led (
			std::shared_ptr<Mailbox> inbox,
			std::shared_ptr<Mailbox> outboxMrf24j,
			std::shared_ptr<Mailbox> outboxButton
		);
	virtual ~Led();

	virtual void start();
	virtual void stop();
	virtual bool isRunning();
};

#endif /* LED_H_ */
