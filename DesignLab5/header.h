/*
 * header.h
 *
 *  Created on: Oct 22, 2014
 *      Author: sddelong
 */

#ifndef HEADER_H_
#define HEADER_H_
#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
#include <ctime>
#include <fstream>


#define QUEUE_SIZE 10 //default queue size is 10 elements

enum enum_Status{
	UNKNOWN,
	RELEASE,
	CHECKUP,
	ADMIT,
	LABOUR
};

using namespace std;
//Harrsans class//
class patient {
public:
	string first_name;
	string last_name;
	string healthcard_number;
};




//The registry (queue) class//
typedef patient element;
class registry{
private:
	//size and back are needed for queue; since the queue will be shifted each time
	//a patient is removed, a front isn't needed
	int size, back;
	element * queue;

public:
//Constructors//
	//default:
	registry();
	 //user-inputted size:
	registry(int);

//Destructor//
	~registry();

//Functions//
	//this adds an element to the queue, returns 1 if successful (0 if not)
	bool addToBack(element);

	//this takes the front element from the queue, returning the element at the front
	element takeFromFront();

	//this shows the elements in the queue
	void showQueue();

};

//The menu class//
class user{
private:
	string str_input;
	int int_input;
	registry patient_queue;
	element temp_ele;



public:
	//Constructor & Destructor//
		user();
		user(int);
		~user();

	//Functions//
		//help function; takes an int and gives a help message, according to what help is needed
		void help_prompt(int);
	//basic menu function; will ask for user's input
	void main_menu();



};


#endif /* HEADER_H_ */
