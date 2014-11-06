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
	contraction_rate=7;
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
		condition=enum_Status(rand()%2+1);

		break;
	case ADMIT:
		cout<<"ADMITTED TO BIRTHING UNIT\n";
		break;
	case LABOUR:
		cout<<"Input cervix dilation and contraction rate\n";
		cin >>cervix_dilation;
		cin >> contraction_rate;
		if (cervix_dilation >=4 && contraction_rate< 4)
		condition=ADMIT;

	}
	return condition;
}


void patient::showpatients()
{
	cout<<setw(20)<<first_name<<setw(20)<<last_name<<setw(20)<<healthcard_number<<setw(20)<<bed_number<<setw(20)<<contraction_rate<<setw(20)<<cervix_dilation<<setw(20);

}




