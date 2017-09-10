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
Led::Led(std::shared_ptr<Message<int>> inbox,
		 std::shared_ptr<Message<int>> outboxMrf24j,
		 std::shared_ptr<Message<int>> outboxButton):
	mInbox(inbox),
	mOutboxMrf24j(outboxMrf24j),
	mOutboxButton(outboxButton){
}

Led::~Led() {
	// TODO Auto-generated destructor stub
}

void Led::start(){
	while(1){
		std::cout << "size: " << mInbox->size() << std::endl;
		if(!mInbox->empty() ){
			std::cout << "got message:" << mInbox->getMessage() << std::endl;
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(50));
	}
}

void Led::stop(){

}
bool Led::isRunning(){
	return true;
}
