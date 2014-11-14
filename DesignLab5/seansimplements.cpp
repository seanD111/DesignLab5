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
		beds=0;
	}
	registry::registry(int a){
		size=a;
		back=-1;
		queue=new element[size];
		largestDil=0;
		beds=0;
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
	//c)then set the new element to index 'back'
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

	//back of queue function; returns the private variable 'back'//
	int registry::backOfQueue(){
		return back;
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
			cout<<setw(20)<<i<<setw(30)<<queue[i].last_name + ", "+ queue[i].first_name<<setw(24);
			queue[i].printstatus();
			cout<<"\n";
		}
	}
	//most urgent function; needs to://
	//a)go through the queue, searching for patient with highest dilation
	//b)report name and dilation status
	void registry::mostUrgent(){
		cout<<"\n";
		largestDil=0;
		for(int i=0; i<=back; i++){
			if (queue[largestDil].cervix_dilation<queue[i].cervix_dilation){
				largestDil=i;
			}
		}
		cout<<setw(30)<<"Most Urgent Patient"<<setw(25)<<"Cervical Dilation(cm)"<<setw(25)<<"Condition\n";
		for(int i=0; i<80; i++) cout<<"-";
		cout<<"\n"<< setw(28)<<queue[largestDil].first_name<<" "<<queue[largestDil].last_name<<setw(25)<<queue[largestDil].cervix_dilation<<setw(24);
		queue[largestDil].printstatus();
		cout<<"\n\n";
	}

	//find element function; needs to return the patient at index 'a'//
	element registry::findEle(int a){
		return queue[a];
	}
/****************USER IMPLEMENTATION*************************/



	user::user(): str_input(""), int_input(0), menu_select(0), patient_queue()
	{
		temp_ele=new element;
	}

	user::user(int a): str_input(""), int_input(0), menu_select(0), patient_queue(a)
	{
		temp_ele=new element;
	}

	user::~user(){
		delete temp_ele;
	}

	void user::main_menu(){
		// main menu loop
		do {
			stringstream strstr;
			temp_ele->resetpatient();
			cout<<"\n\n|============================== Main Menu ==============================|\nPlease enter the number of the task you wish to do:\n";
			cout<<"\t0: Exit Program\n\t1: Add a Patient to Queue\n\t2: Examine Next Patient\n\t3: Show Patient Queue\n\t4: Show specific Patient Information\n\t5: Show Most Urgent Patient\n";

			//ask user for input; do a function depending on input
			cin>>menu_select;
			switch(menu_select){
				//add patient
				case 1:

					cout<<"\n\n|============================== Add Patient ==============================|\n";
					cout<<"Enter the patient's info, in form: [First Name] [Last Name] [Health card #]\n";

					//use stringstream to get input
					cin.ignore();
					getline(cin, str_input);

					strstr.str(str_input);
					strstr>> temp_ele->first_name;
					strstr>> temp_ele->last_name;
					strstr>> temp_ele->healthcard_number;
					//add the patient (stored in temp_ele) to the back of the queue
					patient_queue.addToBack(*temp_ele);

					break;
				//examine patient
				case 2:
					//if the queues not empty, take the firstmost one
					if(patient_queue.backOfQueue()>-1){
					*temp_ele=patient_queue.takeFromFront();

					//test the patient's status while examining them; they get sent to the back sometimes
					switch(temp_ele->examinepatients()){
						case UNKNOWN:
							patient_queue.addToBack(*temp_ele);
							break;

						case CHECKUP:
							patient_queue.addToBack(*temp_ele);
							break;

						case LABOUR:
							patient_queue.addToBack(*temp_ele);
							break;
						case ADMIT:
							patient_queue.beds++;
							temp_ele->bed_number=patient_queue.beds;
							cout<<setw(20)<<"First Name"<<setw(20)<<"Last Name"<<setw(20)<<"Healthcard Number"<<setw(20)<<"Bed Number"<<setw(20)<<"Contraction Rate(min)"<<setw(20)<<"Cervix Dilation(cm)"<<setw(20)<<"Condition\n";
							for(int i=0; i<140; i++) cout<<"-";
							cout<<"\n";
							temp_ele->showpatients();

						default:
							break;
					}
					}
					else cout<<"\n\nThere are no patients in queue!\n\n";



					break;
				//show queue; calls the registry function
				case 3:
					cout<<"\n\n|============================== Patient Queue ==============================|\n\n";
					patient_queue.showQueue();
					break;
				//shows specific patients' detail, by calling the register function
				case 4:
					cout<<"\n\n|============================== Patient Detail ==============================|\n";

						cout<<"Enter the patient's position in the queue:\n";
						cin>>int_input;
					if (int_input<0||int_input>patient_queue.backOfQueue()){
						cout<<"\n\nNo patient is in this position!\n\n";
					}
					else{

					cout<<setw(20)<<"First Name"<<setw(20)<<"Last Name"<<setw(20)<<"Healthcard Number"<<setw(20)<<"Bed Number"<<setw(20)<<"Contraction Rate(min)"<<setw(20)<<"Cervix Dilation(cm)"<<setw(20)<<"Condition\n";

					for(int i=0; i<140; i++) cout<<"-";
					cout<<"\n";
					*temp_ele=patient_queue.findEle(int_input);
					temp_ele->showpatients();
					cout<<"\n\n";
					}


					break;
				//most urgent patient; calls the registry function
				case 5:
					cout<<"\n\n|============================== Most Urgent Patient ==============================|\n";
					patient_queue.mostUrgent();
					break;
			}
		}while (menu_select!=0);

		cout<<"\n\nLeaving Program";

	}









