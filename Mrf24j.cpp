/*
 * Mrf24j.cpp
 *
 *  Created on: Sep 7, 2017
 *      Author: johan
 */

#include "Mrf24j.h"
#include <iostream>
#include <chrono>
#include <thread>

Mrf24j::Mrf24j() {
	// TODO Auto-generated constructor stub

}
Mrf24j::Mrf24j(std::shared_ptr<Message> incoming, std::shared_ptr<Message> outgoing):
		mIncoming(incoming),
		mOutgoing(outgoing){

}

Mrf24j::~Mrf24j() {
	// TODO Auto-generated destructor stub
}

void Mrf24j::start(){
	while(1){
		if(!mOutgoing->full()){
			mOutgoing->putMessage(3);
			std::cout << "message put..."  << std::endl;
			//std::this_thread::sleep_for(std::chrono::milliseconds(1));
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
	}
}
void Mrf24j::stop(){

}
bool Mrf24j::isRunning(){
	return true;
}
