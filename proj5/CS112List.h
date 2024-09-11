/*
 * CS112List.h
 *
 *  Created on: Feb 15, 2022
 * Student Name: Sungmin (David) Choi (sc94)
 */

#ifndef CS112LIST_H_
#define CS112LIST_H_

#include <stdexcept>
#include <iostream>
#include <string>
using namespace std;

template <class Item>
class CS112List {
public:
	CS112List();
	CS112List(int size);
	CS112List(const CS112List<Item> &orig); // copy ctor
	int find(string item);
	virtual ~CS112List();
	void insert(int index, Item it);
	bool remove(Item it);
	Item removeAt(int index);
	CS112List &slice(int stop_index) const;
	CS112List &slice(int start_index, int stop_index) const;
	CS112List &slice(int start_index, int stop_index, unsigned step_index) const;

	// getters
	int getSize() const;
	Item getValue(int index);
	Item & operator[](int index) const;

	// setters
	void setValue(int index, const Item &value);

	// others
	void append(const Item &value);

	CS112List<Item> & operator+(const CS112List<Item> &rhs) const;

private:
	int mySize;      // number of items in the array
	int myCapacity;  // how much space we have for items
	Item *myArray;   // an array, of course.
	int validate_index(int index) const;
};

template <class Item>
CS112List<Item>::CS112List() {
	mySize = 0;
	myCapacity = 0;
	myArray = nullptr;
}

template <class Item>
CS112List<Item>::CS112List(int size) {
	mySize = myCapacity = size;
	myArray = new Item[size]();
}

template <class Item>
CS112List<Item>::CS112List(const CS112List<Item> &orig) {
	// cout << "copy ctor called with object " << &orig << endl;
	mySize = orig.mySize;
	myCapacity = orig.myCapacity;
	if (myCapacity == 0) {
		myArray = nullptr;
	} else {
		// deep copy.
		myArray = new Item[mySize]();
		for (int i = 0; i < mySize; i++) {
			myArray[i] = orig.myArray[i];
		}
	}
}

// called when object goes out of scope.

template <class Item>
CS112List<Item>::~CS112List() {
	delete [] myArray;
}

template <class Item>
void CS112List<Item>::append(const Item &value) {
	if (mySize >= myCapacity) {
		// Note: double the capacity, unless it was 0, then make it 1.
		int newCapacity = myCapacity == 0 ? 1 : myCapacity * 2;
		Item *tmp = new Item[newCapacity]();
		for (int i = 0; i < mySize; i++) {
			tmp[i] = myArray[i];
		}
		myCapacity = newCapacity;
		delete[] myArray;
		myArray = tmp;
	}
	myArray[mySize] = value;
	mySize++;
}

template <class Item>
int CS112List<Item>::getSize() const {
	return mySize;
}

template <class Item>
Item CS112List<Item>::getValue(int index) {
	return myArray[validate_index(index)];
}

template <class Item>
void CS112List<Item>::setValue(int index, const Item &value) {
	myArray[validate_index(index)] = value;
}
// return a reference to the index-th location.
template <class Item>
Item & CS112List<Item>::operator[](int index) const {
	return myArray[validate_index(index)];
}

template <class Item>
CS112List<Item> & CS112List<Item>::operator+(const CS112List<Item> &rhs) const {
	CS112List *result = new CS112List(mySize + rhs.mySize);
	for (int i = 0; i < mySize; i++) {
		(*result)[i] = myArray[i];
	}
	for (int i = 0; i < rhs.mySize; i++) {
		(*result)[mySize + i] = rhs[i];
	}
	return *result;
}

template <class Item>
ostream& operator<<(ostream &out, const CS112List<Item> &rhs) {
	out << "[";
	for (int i = 0; i < rhs.getSize(); i++) {
		out << rhs[i];
		if (i < rhs.getSize() - 1) {
			out << ", ";
		}
	}
	out << "]";
	return out;
}

template <class Item>
int CS112List<Item>::validate_index(int index) const {
	if (index >= mySize) {
		throw range_error("Index greater than size");
	}
	if (index < -mySize) {
		throw range_error("Range smaller than size");
	} else {
		if (index >= 0) {
			return index;
		}
	}
	return mySize + index;
}

template <class Item>
int CS112List<Item>::find(string item) {
	for (int i = 0; i < mySize; i++) {
		if (myArray[i] == item) {
			return i;
		}
	}
	return -1;
}

// insert the given item into the array at the given index.
template <class Item>
void CS112List<Item>::insert(int index, Item it) {
	if (mySize >= myCapacity) {
		int newCapacity = myCapacity == 0 ? 1 : myCapacity * 2;
		Item *newArray = new Item[newCapacity]();
		for (int i = 0; i < mySize; i++) {
			newArray[i] = myArray[i];
		}
		for (int i = index; i < mySize; i++) {
			newArray[i + 1] = myArray[i];
		}
		myCapacity = newCapacity;
		delete[] myArray;
		myArray = newArray;
		++mySize;
	}
	else {
		for (int i = index; i < mySize; i++) {
			myArray[i + 1] = myArray[i];
		}
	}
	myArray[index] = it;
}

//search the array for the given Item. If it is found, remove it from the list
template <class Item>
bool CS112List<Item>::remove(Item it){
	int value = find(it);
	if (value == -1) {
		return false;
	}
	else {
		for (int i = value; i < mySize; i++) {
			myArray[i] = myArray[i + 1];
		}
		return true;
	}
}

// remove whatever item was at the given index,
//returning the item, and shifting the remaining items down to fill the gap.
template<class Item>
Item CS112List<Item>::removeAt(int index) {
	if (index < -mySize || index > mySize) {
		throw range_error("The index is out of range");
	}
	string item = myArray[index];
	for (int i = index; i < mySize; i++) {
		myArray[i] = myArray[i + 1];
	}

	mySize--;
	Item *newArray = new Item[mySize]();
	for (int i = 0; i < mySize; i++) {
		newArray[i] = myArray[i];
	}
	delete [] myArray;
	myArray = newArray;
	return item;
}
template<class Item>
CS112List<Item> & CS112List<Item>::slice(int stop_index) const {
	return slice(0, stop_index, 1);
}

template<class Item>
CS112List<Item> & CS112List<Item>::slice(int start_index, int stop_index) const {
	return slice(start_index, stop_index, 1);
}

template<class Item>
CS112List<Item> & CS112List<Item>::slice(int start_index, int stop_index, unsigned step_index) const {
	if (start_index < 0) {
		start_index = start_index + mySize;
	}
	if (stop_index < 0) {
		stop_index = stop_index + mySize;
	}

	if (stop_index > mySize) {
		stop_index = mySize;
	}

	if (step_index == 0) {
		throw invalid_argument("The slice step cannot be zero");
	}

	CS112List<Item> *result = new CS112List;
	for (int i = start_index; i < stop_index; i = i + step_index) {
		result -> append(myArray[i]);
	}
	return *result;
}



// make it so we can do cout << aList.]
template<class Item>
ostream& operator<<(ostream &out, const CS112List<Item> &rhs);

#endif /* CS112LIST_H_ */
