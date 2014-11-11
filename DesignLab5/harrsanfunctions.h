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

enum enum_Status{//enumerated values set for condition
	UNKNOWN,
	RELEASE,
	LABOUR,
	CHECKUP,
	ADMIT,

};


class patient{//patient class stores information in class


public:

patient();

~patient();

string first_name;
string last_name;
int healthcard_number;
enum_Status condition;
int bed_number;
int contraction_rate;
int cervix_dilation;//each variable initialized in patient class


enum_Status examinepatients();//shows patient class
void printstatus();//prints condition
void showpatients();//prints patient information in one line
void resetpatient();//clears patient information





};
typedef patient element;//use of patient class in registry


#endif /* MYFUNCTIONS_H_ */
