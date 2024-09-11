/* Vec.cpp defines the methods for Vec, a simple vector class.
 * Student Name: Sungmin Choi (sc94)
 * Student Name: Youngha Kweon (yk85)
 * Date: Feb 8, 2022
 * Begun by: Joel C. Adams, for CS 112 at Calvin University.
 */

#include <stdexcept>
#include "Vec.h"
using namespace std;

Vec::Vec() {
	mySize = 0;
	myArray = nullptr;
}

Vec::Vec(unsigned size) {
	mySize = size;
	if (size > 0) {
		myArray = new Item[size];
		for (unsigned i = 0; i < mySize; ++i){
			myArray[i] = 0;
		}
	} else {
		myArray = nullptr;
	}
}

Vec::Vec(const Vec& original) {
	mySize = original.mySize;
	if (original.mySize > 0){
		myArray = new Item[mySize];
		for (unsigned i = 0; i < mySize; ++i){
			myArray[i] = original.myArray[i];
		}
	} else {
		myArray = nullptr;
	}
}

Vec::~Vec() {
	delete[] myArray;
	myArray = nullptr;
	mySize = 0;
}

Vec& Vec::operator=(const Vec& original) {
	if (mySize != original.mySize) {
	} if (mySize > 0) {
		delete[] myArray;
		myArray = nullptr;
	} if (original.mySize > 0) {
		myArray = new Item[original.mySize];
	} mySize = original.mySize;
	for (unsigned i = 0; i < mySize; ++i) {
		myArray[i] = original.myArray[i];
	}
	return *this;
}

unsigned Vec::getSize() const {
	return mySize;
}

void Vec::setItem(unsigned index, const Item& it) {
	if (index > mySize) {
		throw range_error("Out of range");
	} else {
		myArray[index] = it;
	}
}

Item Vec::getItem(unsigned index) const {
	if (index >= mySize) {
		throw range_error("Out of range");
	} else {
		return myArray[index];
	}
}

void Vec::setSize(unsigned newSize) {
	if (mySize != newSize) {
		if (newSize == 0) {
			delete[] myArray;
			myArray = nullptr;
			mySize = 0;
		} else {
			Item * newArray;
			newArray = new Item[newSize];
			if (mySize < newSize) {
				for (unsigned i = 0; i < mySize; ++i) {
					newArray[i] = myArray[i] ;
				} for (unsigned i = mySize; i < newSize; ++i) {
					newArray[i] = 0;
				}
			} else {
				for (unsigned i = 0; i < newSize; ++i) {
					newArray[i] = myArray[i];
				}
			}
			mySize = newSize;
			delete[] myArray;
			myArray = newArray;
		}
	}
}

bool Vec::operator==(const Vec& v2) const {
	if (mySize == v2.mySize) {
		for (unsigned i = 0; i < mySize; ++i) {
			if (myArray[i] != v2.myArray[i]) {
				return false;
			}
		}
		return true;
	}
	return false;
}

void Vec::writeTo(ostream& out) const {
	for (unsigned i = 0; i < mySize; ++i) {
		out << myArray[i] << endl;
	}
}

void Vec::readFrom(istream& in) {
	if (mySize > 0) {
		for (unsigned i = 0; i < mySize; ++i) {
			in >> myArray[i];
		}
	} else {
		myArray = nullptr;
	}
}

Item& Vec::operator[](unsigned index) {
	if (index >= mySize) {
		throw range_error("Bad Index Value");
	}
	return myArray[index];
}

const Item& Vec::operator[](unsigned index) const {
	if (index >= mySize) {
		throw range_error("Bad Index Value");
	}
	return myArray[index];
}

Vec Vec::operator+(const Vec& v2) const {
	if (mySize != v2.mySize) {
		throw invalid_argument("Not the same size.");

	} else {
		Vec v3(mySize);
		for (unsigned i = 0; i < mySize; ++i) {
			v3.myArray[i] = myArray[i] + v2.myArray[i];
		}
		return v3;
	}
}

Vec Vec::operator-(const Vec& v2) const {
	if (mySize != v2.mySize) {
		throw invalid_argument("Not the same size.");

	} else {
		Vec v3(mySize);
		for (unsigned i = 0; i < mySize; ++i) {
			v3.myArray[i] = myArray[i] - v2.myArray[i];
		}
		return v3;
	}
}

