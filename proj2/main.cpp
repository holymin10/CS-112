/*
 * main.cpp
 *
 *  Created on: Jan 31, 2022
 *      Author: sungminchoi
 */

#include <iostream>
#include <iomanip>
#include "utils.h"
using namespace std;

int main(){
	int n;

	cout << "Please enter an odd number from 1 - 15: ";
	cin >> n;

	if (n % 2 == 0) {
		cerr << "The number you entered wasn't odd" << endl;
	}
	else {
		buildSquare(n);
	}
}


