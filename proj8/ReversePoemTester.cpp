/*
 * ReversePoemTester.cpp
 *
 *  Created on: Mar 21, 2022
 *      Author: Sungmin (David) Choi (sc94)
 */

#include "ReversePoemTester.h"
#include "ReversePoem.h"
#include <iostream>
#include <cassert>
using namespace std;

void ReversePoemTester::runTests() {
	cout << "Testing..." << flush;
	ReversePoem rp("cats.txt");
	cout << "checking the title... " << endl;
	assert(rp.getTitle() == "Cats");
	cout << "checking the author... " << endl;
	assert(rp.getAuthor() == "Leo J. Smada");
	cout << "checking the body... " << endl;
	cout << "body should be... " << endl;
	cout << "I love it when cats rub against me. \nI could never say \nI hate those purring felines.\n";
	cout << "-------------------" << endl;
	cout << rp.getBody() << endl;
	cout << "-------------------" << endl;
	cout << "checking the reversed body..." << endl;
	cout << "reversed body should be... " << endl;
	cout << "\nI hate those purring felines. \nI could never say \nI love it when cats rub against me.\n";
	cout << "-------------------" << endl;
	cout << rp.getBodyReversed() << endl;
	cout << "-------------------" << endl;
	cout << "Test completed." <<endl;
}
