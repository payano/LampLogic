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
#include "Message.h"
#include <iostream>
constexpr int maxMessageLength = 100;


template <class T>
class Message {
private:
	std::list<T> mMessage;
	std::mutex mLock;

public:
	void putMessage(T message);
	T getMessage();
	bool full();
	bool empty();
	int size();


};


template <class T>
void Message<T>::putMessage(T message){
	if(mMessage.size() >= maxMessageLength){
		std::cout << "1hBm" << std::endl;
		throw std::invalid_argument("Can not add to list, the list is full.");
	}
	mLock.lock();
	mMessage.push_back(message);
	mLock.unlock();
}

template <class T>
T Message<T>::getMessage(){
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

template <class T>
bool Message<T>::empty(){
	if(mMessage.size() == 0){
		return true;
	}
	return false;
}

template <class T>
bool Message<T>::full(){
	if(mMessage.size() >= maxMessageLength){
		return true;
	}
	return false;
}

template <class T>
int Message<T>::size(){return mMessage.size();}

#endif /* MESSAGE_H_ */
