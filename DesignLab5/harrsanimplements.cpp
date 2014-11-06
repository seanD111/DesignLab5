/*
 * main.cpp
 *
 *  Created on: Oct 21, 2014
 *      Author: Harrsan
 */

#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
#include <ctime>
#include <cstdlib>
#include "harrsanfunctions.h"
#include "seanfunctions.h"
using namespace std;

//The constructor for patient class which initializes the values for condition as "UNKNOWN",
//the first and last name as blanks, the healthcard number, bed number, contraction rate,
//and cervix dilation as 0.
patient::patient()
{
	condition= UNKNOWN;
	first_name="";
	last_name="";
	healthcard_number=0;

	bed_number=0;
	contraction_rate=0;
	cervix_dilation=0;

}
patient::~patient()
{

}
//Examine patients function creates initial status of incoming patients
enum_Status patient::examinepatients()//function for adding patients

{
	srand(time(NULL));
	switch (condition)//Switch case is used to select a randomized condition, and the various processes that follow each condition
	{
	case UNKNOWN:

		condition= enum_Status(rand()%4+1);//chooses random condition from enum_Status

		break;
	case RELEASE:
		cout << "Patient Released\n";//if condition is released the "Patient Released" is printed

		break;
	case CHECKUP:
		cervix_dilation=0;//cervix dilation will be 0
		break;
	case ADMIT:
		cout<<"ADMITTED TO BIRTHING UNIT\n";
		break;
	case LABOUR:
		if (cervix_dilation >=4 && contraction_rate< 4)
		condition=ADMIT;

	}
	return condition;
}

//	cin.ignore();
//	getline(cin, str_input);
//
//	strstr.str(str_input);
//	strstr>> temp_ele.first_name;
//	strstr>> temp_ele.last_name;
//	strstr>> temp_ele.healthcard_number;
//	patient_queue.addToBack(temp_ele);






//
void patient::showpatients()
{

	cout<<"[Show Patients]";
	//cout<<"First Name"<<setw(5)<<"Last Name"<<setw(5)<<"Health Card Number"<<setw(5)<<"Bed Number"<<setw(5)<<"Contraction Rate"<<setw(5)<<"Cervix Dilation\n";
	for(int j=0; j<68; j++) cout<<"=";
	cout<<first_name<<setw(5)<<last_name<<setw(5)<<healthcard_number<<setw(5)<<bed_number<<setw(5)<<contraction_rate<<setw(5)<<cervix_dilation<<setw(5);

}




