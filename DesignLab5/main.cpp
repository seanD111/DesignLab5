/*
 * main.cpp
 *
 *  Created on: Oct 22, 2014
 *      Author: sddelong
 */
#include "seanfunctions.h"

int main(){
	int size=QUEUE_SIZE;
	cout<<"Enter the size of the queue as a positive integer: ";
	cin>>size;
	cout<<"\n\n\n\n\n";
	user program_menu(size);
	program_menu.main_menu();//kobe is not gonna make the playoffs :(
	return 0;
}
