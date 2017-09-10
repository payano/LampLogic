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

class Led : public IThread {
private:
	std::shared_ptr<Message<int>> mInbox;
	std::shared_ptr<Message<int>> mOutboxMrf24j;
	std::shared_ptr<Message<int>> mOutboxButton;
public:
	Led();
	Led (
			std::shared_ptr<Message<int>> inbox,
			std::shared_ptr<Message<int>> outboxMrf24j,
			std::shared_ptr<Message<int>> outboxButton
		);
	virtual ~Led();

	virtual void start();
	virtual void stop();
	virtual bool isRunning();
};

#endif /* LED_H_ */
