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
#include <cmath>
#include "myfunctions.h"
using namespace std;

patient::patient()
{
	condition= UNKNOWN;

}


enum_Status patient::examinepatients()//function for adding patients

{
	switch (condition)
	{
	case UNKNOWN:
		//diagnose or randomize function
		break;
	case RELEASE:
		cout << "Patient Released\n";
		return condition;

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


/*enum my_type {
    a, b, c, d,
    last
};

void f() {
    my_type test = static_cast<my_type>(rand() % last);
}*/



}



