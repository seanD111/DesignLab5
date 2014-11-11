/*
 * main.cpp
 *
 *  Created on: Oct 22, 2014
 *      Author: sddelong
 */
#include "seanfunctions.h"

int main(){

	//asking for the size of the registry queue
	int size=QUEUE_SIZE;
	cout<<"Enter the size of the queue as a non-zero, positive integer: ";
    cin >> size;
    while ((!cin)||(size<=0)) {
        cout << "\n ERROR, enter a non-zero, positive integer:" ;
        cin.clear();
        cin.ignore(256,'\n');
        cin >> size;
    }





	cout<<"\n\n\n\n\n";
	user program_menu(size);
	program_menu.main_menu();//kobe is not gonna make the playoffs :(
	return 0;

}
