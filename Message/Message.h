/*
 * Message.h
 *
 *  Created on: Sep 7, 2017
 *      Author: johan
 */

#ifndef MESSAGE_H_
#define MESSAGE_H_
#include <list>
#include <mutex>
#include "Message.h"

class Message {
private:
	//std::list<T> mMessage;
	std::mutex mLock;

public:
	//void putMessage(T message);
	//T getMessage();
	bool full();
	bool empty();
	int size();


};

#endif /* MESSAGE_H_ */
