/*
 * Message.cpp
 *
 *  Created on: Sep 7, 2017
 *      Author: johan
 */

#include "Message.h"
#include <iostream>
constexpr int maxMessageLength = 100;
Message::Message() {
	// TODO Auto-generated constructor stub

}

Message::~Message() {
	// TODO Auto-generated destructor stub
}

void Message::putMessage(int message){
	if(mMessage.size() >= maxMessageLength){
		std::cout << "1hBm" << std::endl;
		throw std::invalid_argument("Can not add to list, the list is full.");
	}
	mLock.lock();
	mMessage.push_back(message);
	mLock.unlock();
}

int Message::getMessage(){
	if(mMessage.size() == 0){
		std::cout << "2hAm" << std::endl;
		throw std::invalid_argument("Can not withdraw from list, the list is empty.");
	}
	mLock.lock();
	int returnValue = mMessage.front();
	mMessage.pop_front();
	mLock.unlock();
	return returnValue;
}
bool Message::empty(){
	if(mMessage.size() == 0){
		return true;
	}
	return false;
}
bool Message::full(){
	if(mMessage.size() >= maxMessageLength){
		return true;
	}
	return false;
}
int Message::size(){return mMessage.size();}
