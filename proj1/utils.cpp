/*
 * utils.cpp
 *
 *  Created on: Jan 20, 2022
 *      Author: sungminchoi
 */

#include <iostream>
using namespace std;

double constrain(double value, double low, double high){
	if (value > high){
		return high;
	}else if (value < low){
		return low;
	}else
		return value;
}

int isPrime(unsigned int value){

	if(value <= 1)
		return false;
	for(int i = 2; i < value; i++)
		if (value % i == 0)
			return false;

	return true;
}

