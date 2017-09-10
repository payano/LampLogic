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
#include "Mailbox.h"

class Mrf24j: public IThread {
private:
	std::shared_ptr<Mailbox> mInbox;
	std::shared_ptr<Mailbox> mOutbox;
public:
	Mrf24j();
	Mrf24j(std::shared_ptr<Mailbox> inbox, std::shared_ptr<Mailbox> outbox);
	virtual ~Mrf24j();

	virtual void start();
	virtual void stop();
	virtual bool isRunning();
};

#endif /* MRF24J_H_ */
