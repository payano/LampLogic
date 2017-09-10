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
#include "Mailbox.h"

std::shared_ptr<Mailbox> mrf24jInbox 	= std::make_shared<Mailbox>();
std::shared_ptr<Mailbox> ledInbox		= std::make_shared<Mailbox>();
std::shared_ptr<Mailbox> buttonInbox	= std::make_shared<Mailbox>();

void mrf24jThread(){
	Mrf24j mrf24j(mrf24jInbox, ledInbox);
	mrf24j.start();

}
void ledThread(){
	Led led(ledInbox, mrf24jInbox, buttonInbox);
	led.start();

}
void buttonThread(){
	std::cout << __FUNCTION__ << std::endl;
}

int main(void){
	//Start program:

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
