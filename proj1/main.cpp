/*
 * main.cpp
 *
 *  Created on: Jan 20, 2022
 *      Author: sungminchoi
 */


#include <iostream>
#include <cassert>
#include "utils.h"
using namespace std;


void findNPrimes(unsigned primes[], unsigned size){
	int n = 1, i = 0;
	while (n <= size) {
		if (isPrime(n)) {
			primes[i] = n;
			n++;
			i++;
		}else {
			n++;
		}
	}
}

int main(){

	unsigned arr[100];
	findNPrimes (arr, 541);

	assert(arr[4] == 11);
	assert(arr[38] == 167);
	assert(arr[99] == 541);

	assert(isPrime(11) == true);
	assert(isPrime(4) == false);
	cout << "All tests passed \n";

	return 0;
}


