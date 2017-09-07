/*
 * Message.h
 *
 *  Created on: Sep 7, 2017
 *      Author: johan
 */

#ifndef MESSAGE_H_
#define MESSAGE_H_
#include <list>
#include <string>
#include <mutex>

class Message {
private:
	std::list<int> mMessage;
	std::mutex mLock;

public:
	Message();
	virtual ~Message();
	virtual void putMessage(int message);
	virtual int getMessage();
	virtual bool full();
	virtual bool empty();
	virtual int size();


};

#endif /* MESSAGE_H_ */
