/*
 * Mrf24j.h
 *
 *  Created on: Sep 7, 2017
 *      Author: johan
 */

#ifndef MRF24J_H_
#define MRF24J_H_

#include "IThread.h"
#include "Message.h"
#include <memory>

class Mrf24j: public IThread {
private:
	std::shared_ptr<Message> mIncoming;
	std::shared_ptr<Message> mOutgoing;
public:
	Mrf24j();
	Mrf24j(std::shared_ptr<Message> incoming, std::shared_ptr<Message> outgoing);
	virtual ~Mrf24j();

	virtual void start();
	virtual void stop();
	virtual bool isRunning();
};

#endif /* MRF24J_H_ */
