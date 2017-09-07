/*
 * Led.cpp
 *
 *  Created on: Sep 7, 2017
 *      Author: johan
 */

#include "Led.h"
#include <iostream>
#include <chrono>
#include <thread>

Led::Led() {
	// TODO Auto-generated constructor stub

}
Led::Led(std::shared_ptr<Message> incoming, std::shared_ptr<Message> outgoing):
	mIncoming(incoming),
	mOutgoing(outgoing){
}

Led::~Led() {
	// TODO Auto-generated destructor stub
}

void Led::start(){
	while(1){
		if(!mIncoming->empty() ){
			std::cout << "got message:" << mIncoming->getMessage() << std::endl;
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
	}
}
void Led::stop(){

}
bool Led::isRunning(){
	return true;
}
