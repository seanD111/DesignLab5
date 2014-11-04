/*
 * implements.cpp
 *
 *  Created on: Oct 22, 2014
 *      Author: sddelong & harrsan
 */

#include "seanfunctions.h"
#include "harrsanfunctions.h"


/**************REGISTRY IMPLMENTATION********************/
//Constructors//
	registry::registry(){
		size=QUEUE_SIZE;
		back=-1;
		queue=new element[size];
		largestDil=0;
	}
	registry::registry(int a){
		size=a;
		back=-1;
		queue=new element[size];
		largestDil=0;
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
	//most urgent function; needs to://
	//a)go through the queue, searching for patient with highest dilation
	//b)report name and dilation status
	void registry::mostUrgent(){
		cout<<"\n";
		largestDil=0;
		for(int i=0; i<back; i++){
			if (queue[largestDil].cervix_dilation<queue[i].cervix_dilation){
				largestDil=i;
			}
		}
		cout<<setw(30)<<"Most Urgent Patient"<<setw(25)<<"Cervical Dilation\n";
		for(int i=0; i<56; i++) cout<<"-";
		cout<<"\n"<< setw(30)<<queue[largestDil].first_name<<queue[largestDil].last_name<<setw(25)<<queue[largestDil].cervix_dilation;
		cout<<"\n\n";
	}


/****************USER IMPLEMENTATION*************************/



	user::user(): str_input(""), int_input(0), patient_queue()
	{
	}

	user::user(int a): str_input(""), int_input(0), patient_queue(a)
	{
	}

	user::~user(){

	}

	void user::main_menu(){
		do {
			stringstream strstr;
			cout<<"\n\n|============================== Main Menu ==============================|\nPlease enter the number of the task you wish to do:\n";
			cout<<"\t0: Exit Program\n\t1: Add a Patient to Queue\n\t2: Examine Next Patient\n\t3: Show Patient Queue\n\t4: Show specific Patient Information\n\t5: Show Most Urgent Patient\n";
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
					switch(temp_ele.condition){
						case UNKNOWN:
							break;
						case RELEASE:
							break;
						case CHECKUP:
							break;
						case ADMIT:
							break;
						case LABOUR:
							break;
					}

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
				case 5:
					cout<<"\n\n|============================== Most Urgent Patient ==============================|\n";
					patient_queue.mostUrgent();
					break;
			}
		}while (int_input!=0);

	}

	void user::help_prompt(int err){

	}






