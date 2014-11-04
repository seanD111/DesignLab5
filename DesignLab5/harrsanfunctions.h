/*
 * myfunctions.h
 *
 *  Created on: Oct 21, 2014
 *      Author: Harrsan
 */

#ifndef HARRSANFUNCTIONS_H_
#define HARRSANFUNCTIONS_H_
#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>

using namespace std;
//commment
enum enum_Status{
	UNKNOWN,
	RELEASE,
	CHECKUP,
	ADMIT,
	LABOUR,
};


class patient{


public:

patient();

~patient();

string first_name;
string last_name;
int healthcard_number;
enum_Status condition;
int bed_number;
int contraction_rate;
int cervix_dilation;




enum_Status examinepatients();
void showpatients();

//includes first name, last name, health card number, condition, bed number, contraction rate(minutes between contractions)
//cervix dilation(0-10cm)
//function which reads patient
//function


};
typedef patient element;


#endif /* MYFUNCTIONS_H_ */
