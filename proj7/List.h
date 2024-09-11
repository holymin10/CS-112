/*
 * List.h
 *
 *  Created on: Feb 21, 2022
 *      Author: Sungmin (David) Choi (sc94)
 */

#ifndef LIST_H_
#define LIST_H_

#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

typedef double Item;
template <class Item>
class List {
public:
	List();
	List(const List<Item> & original);
	virtual ~List();
	unsigned getSize() const { return mySize; }
	Item getFirst() const;
	Item getLast() const;
	void prepend(const Item &it);
	void writeTo(ostream &out, char separator = ' ') const;
	void append(const Item &it);
	bool equality(const List<Item>& rhs) const;
	int getIndexOf(const Item &it) const;
	bool insertAfter(string& otherPersonsName, string& yourName);
	bool insertBefore(string& otherPersonsName, string& yourName);


private:
	struct Node {
		Node();
		Node(Item it, Node* next);
		virtual ~Node();
		Item myItem;
		Node *myNext;
	};
	unsigned mySize;
	Node *myFirst;
	Node *myLast;

	friend class ListTester;
};

template <class Item>
List<Item>::List() {
	mySize = 0;
	myFirst = myLast = nullptr;
}

template <class Item>
List<Item>::~List() {
	mySize = 0;
	delete myFirst;
	myFirst = myLast = nullptr;
}

template <class Item>
List<Item>::Node::Node() {
	myItem = Item();
	myNext = nullptr;
}

template <class Item>
List<Item>::Node::Node(Item it, Node* next) {
	myItem = it;
	myNext = next;
}

template <class Item>
List<Item>::Node::~Node() {
	// cout << "~Node() is deallocating the node containing item "
	//		<< myItem << endl;
	delete myNext;
	myNext = nullptr;
}

template <class Item>
Item List<Item>::getFirst() const {
	if (mySize == 0) {
		throw underflow_error("list is empty");
	}
	return myFirst->myItem;
}

template <class Item>
Item List<Item>::getLast() const {
	if (mySize == 0) {
		throw underflow_error("list is empty");
	}
	return myLast->myItem;
}

template <class Item>
void List<Item>::prepend(const Item &it) {
	Node *newNode = new Node(it, myFirst);
	myFirst = newNode;
	if (mySize == 0) {
		myLast = newNode;
	}
	mySize++;
}

template <class Item>
void List<Item>::writeTo(ostream &out, char separator) const {
	for (Node *curr = myFirst; curr != nullptr; curr = curr->myNext) {
		out << curr->myItem << " ";
	}
}

template <class Item>
void List<Item>::append(const Item &it) {
	Node *newNode = new Node(it, nullptr);
	if (mySize == 0) {
		myFirst = newNode;
	} else {
		myLast -> myNext = newNode;
	}
	myLast = newNode;
	mySize++;
}

template <class Item>
int List<Item>::getIndexOf(const Item &it) const {
	int result = 0;
	for (Node*curr = myFirst; curr!= nullptr; curr = curr->myNext) {
		if (curr->myItem == it) {
			return result;
		}
		result++;
	}
	return -1;
}

template <class Item>
List<Item>::List(const List<Item> & original) {
	myFirst = nullptr;
	myLast = nullptr;
	mySize = 0;
	if (original.mySize > 0) {
		Node *newNode = original.myFirst;
		while (newNode != nullptr) {
			append(newNode -> myItem);
			newNode = newNode -> myNext;
		}
	}
}

template <class Item>
bool List<Item>::equality(const List<Item>& rhs) const {
	if(this -> mySize != rhs.mySize) {
		return false;
	}
	Node *currRight = rhs.myFirst;
	for (Node *currLeft = this->myFirst; currLeft!= nullptr; currLeft = currLeft->myNext) {
		if (currLeft->myItem != currRight->myItem) {
			return false;
		}
		currRight = currRight->myNext;
	}
	return true;
}

//Overload operator: values are printed out in the console with the equal sign.
template <class Item>
ostream& operator<<(ostream&out, List<Item> &l){
	l.writeTo(out, '=');
	return out;
}

// Node insertAfter Function that inputs yourName anywhere (inputs after the otherPersonsName)
template <class Item>
bool List<Item>::insertAfter(string& otherPersonsName, string& yourName) {
		Node *myNode = myFirst;
		while (myNode != nullptr) {
			if (myNode ->myItem == otherPersonsName) {
					myNode->myNext = new Node(yourName, myNode->myNext);
					if (myNode->myNext->myNext == nullptr) {
						myLast = myNode->myNext;
					}
					mySize++;
					return true;
			} else {
				myNode = myNode->myNext;
			}
	}
	return false;
}

// Node insertBefore Function inserts yourName anywhere (inputs before the otherPersonsName)
template <class Item>
bool List<Item>::insertBefore(string& otherPersonsName, string& yourName) {
		Node *myNode = myFirst;
		if (getIndexOf(otherPersonsName) == -1) {return false; }
		if (getFirst() == otherPersonsName) {
			prepend(yourName);
			return true;
	} else {
			while (myNode != 0) {
				if (myNode->myNext->myItem == otherPersonsName) {
					myNode->myNext = new Node(yourName, myNode->myNext);
					mySize++;
					return true;
			} else {
					myNode = myNode->myNext;
			}
		}
	}
	return false;

}

#endif /* LIST_H_ */
