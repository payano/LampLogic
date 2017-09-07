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
	std::shared_ptr<Message> mIncoming;
	std::shared_ptr<Message> mOutgoing;
public:
	Led();
	Led(std::shared_ptr<Message> incoming, std::shared_ptr<Message> outgoing);
	virtual ~Led();

	virtual void start();
	virtual void stop();
	virtual bool isRunning();
};

#endif /* LED_H_ */
