/*
 * Main.cpp
 *
 *  Created on: Sep 7, 2017
 *      Author: johan
 */

#include "Main.h"
#include "Mrf24j.h"
#include "Led.h"
#include "Button.h"
#include <iostream>       // std::cout
#include <thread>         // std::thread
#include "Message.h"
#include <string>
#include <memory>
std::shared_ptr<Message<int>> message1 = std::make_shared<Message<int>>();
std::shared_ptr<Message<int>> message2 = std::make_shared<Message<int>>();

void mrf24jThread(){
	Mrf24j mrf24j(message1, message2);
	mrf24j.start();

}
void ledThread(){
	Led led(message2, message1);
	led.start();

}
void buttonThread(){
	std::cout << __FUNCTION__ << std::endl;
}

int main(void){
	//Start program:

	//create mutexes here

	//Create mrf24j:
	std::thread mrf24j_thread(mrf24jThread);
	//Create led:
	std::thread led_thread(ledThread);
	//Create button:
	std::thread button_thread(buttonThread);

	mrf24j_thread.join();
	led_thread.join();
	button_thread.join();

}
