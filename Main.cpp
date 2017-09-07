/*
 * Main.cpp
 *
 *  Created on: Sep 7, 2017
 *      Author: johan
 */

#include "Main.h"

#include <iostream>       // std::cout
#include <thread>         // std::thread


void mrf24jThread(){
	std::cout << __FUNCTION__ << std::endl;
}
void ledThread(){
	std::cout << __FUNCTION__ << std::endl;
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
