/*
 * ReversePoem.h
 *
 *  Created on: Mar 21, 2022
 *      Author: Sungmin (David) Choi (sc94)
 */

#ifndef REVERSEPOEM_H_
#define REVERSEPOEM_H_

#include <string>
#include <fstream>
#include <cassert>
#include "Stack.h"
#include "StackException.h"
using namespace std;

class ReversePoem {
public:
	ReversePoem(const string& fileName);
	string getTitle() const;
	string getAuthor() const;
	string getBody() const;
	string getBodyReversed() const;

private:
	Stack<string> *myStack;
	string myTitle;
	string myAuthor;
	string myBody;
	string myBodyReversed;
};

#endif /* REVERSEPOEM_H_ */
