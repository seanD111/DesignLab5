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

enum_Status patient::examinepatients()//function for adding patients

{
	srand(time(NULL));
	switch (condition)
	{
	case UNKNOWN:

		condition= rand()%4+1;

		//rand()%

		break;
	case RELEASE:
		cout << "Patient Released\n";//kkkk

		break;
	case CHECKUP:
		cervix_dilation=0;
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





//void f() {
//    my_type test = static_cast<my_type>(rand() % last);
//}*/
//
//patients::showpatients()
//{
//	cout<<
//}




