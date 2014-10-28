/*
 * implements.cpp
 *
 *  Created on: Oct 22, 2014
 *      Author: sddelong & harrsan
 */

#include "header.h"

/**************REGISTRY IMPLMENTATION********************/
//Constructors//
	registry::registry(){
		size=QUEUE_SIZE;
		back=-1;
		queue=new element[size];
	}
	registry::registry(int a){
		size=a;
		back=-1;
		queue=new element[size];
	}
//Destructor//
	registry::~registry(){
		delete[] queue;
	}

//Functions//
	//add to queue function; needs to://
	//a)check if queue is full
		//if so, return false and don't add an element
	//b)increase the back counter
	//c)set the new element to index 'back'
	bool registry::addToBack(element eleToBack){
		bool valid=true;

		if (back>=(size-1))	{
			valid=false;
			cout<<"\nHospital Capacity is reached!\n\n";
		}
		else {
			back++;
			queue[back]=eleToBack;
		}
		return(valid);
	}

	//take from front function; needs to://
	//a)check if queue is empty
		//if so, don't take an element
	//b)move all the elements forward (doing so will overwrite/delete the first element)
	//c)decrement back
	//d)return the removed element

	element registry::takeFromFront(){
		element temp;
		if(back<0) {//"cant take an element!"
		}

		else {
		temp=queue[0];

			for(int i=0; i<back; i++){
				queue[i]=queue[i+1];
			}
		}
		back--;
		return(temp);

	}

	//show queue function; needs to://
	//a)show each element, their position in line, and their important information
	void registry::showQueue(){
		cout<<setw(20)<<"Position in Queue"<<setw(30)<<"Name(Last, First)"<<setw(25)<<"Condition\n";
		for(int i=0; i<76; i++) cout<<"-";
		cout<<"\n";
		for(int i=0; i<=back; i++){
			cout<<setw(20)<<i<<setw(30)<<queue[i].last_name<<", "<<queue[i].first_name<<setw(15);
			//queue[i].printstatus();
			cout<<"\n";
		}
	}


/****************MENU IMPLEMENTATION*************************/



	menu::menu(): str_input(""), int_input(0), patient_queue()
	{
	}

	menu::menu(int a): str_input(""), int_input(0), patient_queue(a)
	{
	}

	menu::~menu(){

	}

	void menu::main_menu(){
		do {
			stringstream strstr;
			cout<<"\n\n|============================== Main Menu ==============================|\nPlease enter the number of the task you wish to do:\n";
			cout<<"\t0: Exit Program\n\t1: Add a Patient to Queue\n\t2: Examine Next Patient\n\t3: Show Patient Queue\n\t4: Show specific Patient Information\n";
			cin>>int_input;
			switch(int_input){
				case 1:

					cout<<"\n\n|============================== Add Patient ==============================|\n";
					cout<<"Enter the patient's info, in form: [First Name] [Last Name] [Health card #]\n";
					cin.ignore();
					getline(cin, str_input);

					strstr.str(str_input);
					strstr>> temp_ele.first_name;
					strstr>> temp_ele.last_name;
					strstr>> temp_ele.healthcard_number;
					patient_queue.addToBack(temp_ele);

					break;
				case 2:
					temp_ele=patient_queue.takeFromFront();
					//examine patient
					break;
				case 3:
					cout<<"\n\n|============================== Patient Queue ==============================|\n\n";
					patient_queue.showQueue();
					break;
				case 4:
					cout<<"\n\n|============================== Patient Detail ==============================|\n";
					//show patient function
					break;
			}
		}while (int_input!=0);

	}

	void menu::help_prompt(int err){

	}






