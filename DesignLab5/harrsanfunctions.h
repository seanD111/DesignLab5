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
	LABOUR,
	CHECKUP,
	ADMIT,

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
int cervix_dilation;//each variable initialized in patient class


enum_Status examinepatients();
void printstatus();
void showpatients();





};
typedef patient element;


#endif /* MYFUNCTIONS_H_ */
