/*
 * ReversePoem.cpp
 *
 *  Created on: Mar 21, 2022
 *      Author: Sungmin (David) Choi (sc94)
 */

#include "ReversePoem.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

ReversePoem::ReversePoem(const string& fileName) {
	myStack = new Stack<string>(1);
	ifstream fin(fileName);
	assert(fin.is_open());
	// make an empty line
	string linetracker;
	getline(fin, myTitle);
	getline(fin, myAuthor);
	getline(fin, linetracker);
	while (getline(fin, linetracker)) {
		try { myStack->push(linetracker);
		} catch (const StackException& se) {
			myStack->setCapacity(myStack->getCapacity()*2);
			myStack->push(linetracker);
		}
		myBody += linetracker + "\n";
	}
	while (!myStack->isEmpty() ) {
		myBodyReversed = myBodyReversed + myStack->pop() + "\n";
	}
	fin.close();
}



string ReversePoem::getTitle() const {
	return myTitle;
}

string ReversePoem::getAuthor() const {
	return myAuthor;
}

string ReversePoem::getBody() const {
	return myBody;
}

string ReversePoem::getBodyReversed() const {
	return myBodyReversed;
}
