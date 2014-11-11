/*
 * header.h
 *
 *  Created on: Oct 22, 2014
 *      Author: sddelong
 */

#ifndef SEANFUNCTIONS_H_
#define SEANFUNCTIONS_H_
#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
#include <ctime>
#include <fstream>
#include <stdlib.h>



#define QUEUE_SIZE 10 //default queue size is 10 elements



using namespace std;

class patient;

typedef patient element;

//The registry (queue) class//
class registry{
private:
	//size and back are needed for queue; since the queue will be shifted each time
	//a patient is removed, a front isn't needed
	int size, back, largestDil;
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

	//this returns a patient, depending on the inputted index
	element findEle(int);

	//this returns the back index
	int backOfQueue();

	//this finds the patient with the highest cervical dilation
	void mostUrgent();

};

//The user class//
class user{
private:
	//str_input, int_input, and menu_select are user-inputted values
	string str_input;
	int int_input;
	int menu_select;
	//the user acesses an instance of the registry queue, where all patients are stored
	registry patient_queue;

	//a temporary patient is needed in this class to store patient-related info.
	element *temp_ele;



public:
	//Constructor & Destructor//
		user();
		user(int);
		~user();

	//Functions//
	//basic menu function; will ask for user's input
	void main_menu();



};


#endif /* HEADER_H_ */
