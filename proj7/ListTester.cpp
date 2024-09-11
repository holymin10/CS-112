/* ListTester.cpp defines the test methods for class List.
 * Joel Adams, for CS 112 at Calvin University.
 *      Author: Sungmin (David) Choi (sc94)
 *
 */


#include "ListTester.h" // ListTester
#include "List.h"       // List
#include <iostream>     // cin, cout
#include <cassert>      // assert()
#include <cstdlib>      // exit()
#include <stdexcept>    // underflow_error
using namespace std;

void ListTester::runTests() {
	cout << "Running List tests..." << endl;
	testDefaultConstructor();
	testNodeDefaultConstructor();
	testNodeExplicitConstructor();
	testPrepend();
	testDestructor();
	testWriteTo();
	testAppend();
	testgetIndexOf();
	testCopyConstructor();
	testEquality();
	testOutput();
	testInsertAfter();
	testInsertBefore();
	// testAssignment();
	cout << "All tests passed!" << endl;
}

void ListTester::testDefaultConstructor() {
	cout << "Testing List default constructor... " << flush;
	List<Item> aList;
	assert( aList.mySize == 0 );
	assert( aList.myFirst == NULL );
	assert( aList.myLast == NULL );
	cout << "Passed!" << endl;
}

void ListTester::testNodeDefaultConstructor() {
	cout << "Testing Node default constructor... " << flush;
	List<Item>::Node aNode;
	assert( aNode.myItem == Item() );
	assert( aNode.myNext == NULL );
	cout << "Passed!" << endl;
}

void ListTester::testNodeExplicitConstructor() {
	cout << "Testing Node explicit constructor... " << flush;
	List<Item>::Node n1(11, NULL);
	assert( n1.myItem == 11 );
	assert( n1.myNext == NULL );
	cout << " 1 " << flush;

	List<Item>::Node *n3 = new List<Item>::Node(33, NULL);
	List<Item>::Node n2(22, n3);
	assert( n2.myItem == 22 );
	assert( n2.myNext == n3 );
	cout << " 2 " << flush;
	cout << "Passed!" << endl;
}

void ListTester::testPrepend() {
	cout << "Testing prepend()... " << flush;
	// empty List
	List<Item>aList;
	assert( aList.getSize() == 0 );
	assert( aList.myFirst == NULL );
	assert( aList.myLast == NULL );
	try {
		aList.getFirst();
		cerr << "getFirst() worked on empty list" << endl;
		exit(1);
	} catch (underflow_error&) {
		cout << " 0a " << flush;
	}
	try {
		aList.getLast();
		cerr << "getLast() worked on empty list" << endl;
		exit(1);
	} catch (underflow_error&) {
		cout << " 0b " << flush;
	}
	// prepend to empty list
	aList.prepend(22);
	assert( aList.getSize() == 1 );
	assert( aList.myFirst != nullptr );
	assert( aList.myLast == aList.myFirst );
	assert( aList.getFirst() == 22 );
	assert( aList.getLast() == 22 );
	assert( aList.myFirst->myNext == nullptr );
	cout << " 1 " << flush;
	// prepend to a list containing 1 Item
	aList.prepend(11);
	assert( aList.getSize() == 2 );
	assert( aList.myFirst != nullptr );
	assert( aList.myLast != nullptr );
	assert( aList.myFirst != aList.myLast );
	assert( aList.getFirst() == 11 );
	assert( aList.getLast() == 22 );
	assert( aList.myFirst->myNext != nullptr );
	assert( aList.myLast->myNext == nullptr );
	cout << " 2 " << flush;
	// append to a list containing 2 Items
	aList.prepend(0);
	assert( aList.getSize() == 3 );
	assert( aList.myFirst != NULL );
	assert( aList.myLast != NULL );
	assert( aList.getFirst() == 0 );
	assert( aList.getLast() == 22 );
	assert( aList.myFirst->myNext->myItem == 11);
	assert( aList.myLast->myNext == NULL );
	cout << " 3 " << flush;
	cout << "Passed!" << endl;
}

void ListTester::testAppend() {
	cout << "Testing append()... " << flush;
	// empty List
	List<Item> aList;
	assert( aList.getSize() == 0 );
	assert( aList.myFirst == NULL );
	assert( aList.myLast == NULL );
	try {
		aList.getFirst();
		cerr << "getFirst() worked on empty list" << endl;
		exit(1);
	} catch (underflow_error&) {
		cout << " 0a " << flush;
	}
	try {
		aList.getLast();
		cerr << "getLast() worked on empty list" << endl;
		exit(1);
	} catch (underflow_error&) {
		cout << " 0b " << flush;
	}
	// append to empty list
	aList.append(11);
	assert( aList.getSize() == 1 );
	assert( aList.myFirst != NULL );
	assert( aList.myLast == aList.myFirst );
	assert( aList.getFirst() == 11 );
	assert( aList.getLast() == 11 );
	assert( aList.myFirst->myNext == NULL );
	cout << " 1 " << flush;
	// append to a list containing 1 Item
	aList.append(22);
	assert( aList.getSize() == 2 );
	assert( aList.myFirst != NULL );
	assert( aList.myLast != NULL );
	assert( aList.myFirst != aList.myLast );
	assert( aList.getFirst() == 11 );
	assert( aList.getLast() == 22 );
	assert( aList.myFirst->myNext != NULL );
	assert( aList.myLast->myNext == NULL );
	cout << " 2 " << flush;
	// append to a list containing 2 Items
	aList.append(33);
	assert( aList.getSize() == 3 );
	assert( aList.myFirst != NULL );
	assert( aList.myLast != NULL );
	assert( aList.getFirst() == 11 );
	assert( aList.getLast() == 33 );
	assert( aList.myFirst->myNext->myItem == 22 );
	assert( aList.myLast->myNext == NULL );
	cout << " 3 " << flush;
	cout << "Passed!" << endl;
}

void ListTester::testDestructor() {
	cout << "Testing destructor... " << flush;
	List<Item> aList;
	aList.~List();
	assert( aList.getSize() == 0 );
	assert( aList.myFirst == NULL );
	assert( aList.myLast == NULL );
	cout << " 1 " << flush;

	aList.prepend(33);
	aList.prepend(22);
	aList.prepend(11);
	aList.~List();
	assert( aList.getSize() == 0 );
	assert( aList.myFirst == NULL );
	assert( aList.myLast == NULL );
	cout << " 2 " << flush;
	cout << "Passed!  But double-check for memory leaks!" << endl;
}

void ListTester::testgetIndexOf() {
	cout << "Searching for item..." << flush;
	List<Item> listsearch;
	listsearch.append(1);
	listsearch.append(2);
	listsearch.append(3);
	listsearch.append(4);
	assert(listsearch.getSize() == 4);
	assert(listsearch.getIndexOf(2) == 1);
	assert(listsearch.getIndexOf(4) == 3);
	listsearch.append(7122);
	listsearch.append(2533);
	assert(listsearch.getSize() == 6);
	assert(listsearch.getIndexOf(2533) == 5);
	assert(listsearch.getIndexOf(7123) == -1);
}

void ListTester::testCopyConstructor() {
	cout << "Testing copy constructor... " << flush;
	// copy empty list
	List<Item> list1;
	List<Item> list2(list1);
	assert( list2.getSize() == 0 );
	assert( list2.myFirst == NULL );
	assert( list2.myLast == NULL );
	cout << " 1 " << flush;

	// copy nonempty list
	List<Item> list3;
	list3.append(11);
	list3.append(22);
	list3.append(33);
	List<Item> list4(list3);
	assert( list4.getSize() == 3 );
	assert( list4.getFirst() == 11 );
	assert( list4.getLast() == 33 );
	assert( list4.myFirst->myNext->myItem == 22 );
	assert( list4.myFirst != list3.myFirst );
	assert( list4.myLast != list3.myLast );
	cout << " 2 " << flush;
	cout << "Passed!" << endl;
}

void ListTester::testEquality() {
	cout << "Testing equality..." << flush;
	List<Item> lst1;
	lst1.append(2);
	lst1.append(4767);
	lst1.append(3);
	List<Item> lst2(lst1);
	assert(lst1.getSize() == lst2.getSize());
	assert(lst1.equality(lst2));
	lst2.append(24);
	assert(lst1.equality(lst2) == false);
	cout << "Passed!" << endl;
}

// void ListTester::testAssignment() {
// 	cout << "Testing assignment... " << flush;
// 	// empty to empty assignment
// 	List list1;
// 	List list2;
// 	list2 = list1;
// 	assert( list2.getSize() == 0 );
// 	assert( list2.myFirst == NULL );
// 	assert( list2.myLast == NULL );
// 	cout << " 1 " << flush;

// 	// non-empty to empty assignment
// 	List list3;
// 	list3.append(11);
// 	list3.append(22);
// 	list3.append(33);
// 	List list4;
// 	list4 = list3;
// 	assert( list4.getSize() == 3 );
// 	assert( list4.getFirst() == 11 );
// 	assert( list4.getLast() == 33 );
// 	assert( list4.myFirst->myNext->myItem == 22 );
//       // check that nodes are distinct
// 	assert( list4.myFirst != list3.myFirst );
// 	assert( list4.myFirst->myNext != list3.myFirst->myNext );
// 	assert( list4.myLast != list3.myLast );
// 	cout << " 2 " << flush;

// 	// equal-sized non-empty to non-empty assignment
// 	List list5;
// 	list5.append(44);
// 	list5.append(55);
// 	list5.append(66);
// 	list5 = list3;
// 	assert( list5.getSize() == 3 );
// 	assert( list5.getFirst() == 11 );
// 	assert( list5.getLast() == 33 );
// 	assert( list5.myFirst->myNext->myItem == 22 );
//       // check that nodes are distinct
// 	assert( list5.myFirst != list3.myFirst );
// 	assert( list5.myFirst->myNext != list3.myFirst->myNext );
// 	assert( list5.myLast != list3.myLast );
// 	cout << " 3 " << flush;

// 	// empty to non-empty assignment
// 	List list6;
// 	list6.append(44);
// 	list6.append(55);
// 	list6.append(66);
// 	List list7;
// 	list6 = list7;
// 	assert( list6.getSize() == 0 );
// 	assert( list6.myFirst == NULL );
// 	assert( list6.myLast == NULL );
// 	cout << " 4 " << flush;

// 	// unequal-sized non-empty to non-empty assignment
// 	List list8;
// 	list8.append(44);
// 	list8.append(55);
// 	list8.append(66);
// 	list8.append(77);
// 	list8 = list3;
// 	assert( list8.getSize() == 3 );
// 	assert( list8.getFirst() == 11 );
// 	assert( list8.getLast() == 33 );
// 	assert( list8.myFirst->myNext->myItem == 22 );
//       // check that nodes are distinct
// 	assert( list8.myFirst != list3.myFirst );
// 	assert( list8.myFirst->myNext != list3.myFirst->myNext );
// 	assert( list8.myLast != list3.myLast );
// 	cout << " 5 " << flush;

// 	// assignment chaining
// 	List list9;
// 	list9.append(44);
// 	list9.append(55);
// 	list9.append(66);
// 	list9.append(77);
// 	List list10;
// 	list10 = list9 = list8;
// 	assert( list10.getSize() == 3 );
// 	assert( list10.getFirst() == 11 );
// 	assert( list10.getLast() == 33 );
// 	assert( list10.myFirst->myNext->myItem == 22 );
// 	cout << " 6 " << flush;

// 	// self-assignment (stupid, but possible)
// 	List list11;
// 	list11.append(11);
// 	list11.append(22);
// 	list11.append(33);
// 	list11 = list11;
// 	assert( list11.getSize() == 3 );
// 	assert( list11.getFirst() == 11 );
// 	assert( list11.getLast() == 33 );
// 	assert( list11.myFirst->myNext->myItem == 22 );
// 	cout << " 7 " << flush;

// 	cout << "Passed!  But double-check for memory leaks!" << endl;
// }

void ListTester::testWriteTo() {
	cout << "Testing writeTo... " << flush;
	List<Item> l0;
	l0.prepend(33);
	l0.prepend(22);
	l0.prepend(11);
	l0.writeTo(cout);
	cout << endl << "Check that output looks like this: 11 22 33" << endl;
	cout << "Passed!" << endl;
}

void ListTester::testOutput() {
	cout << "Testing Output... " << flush;

	List<unsigned> l1;
	for (unsigned i = 0; i < 4; i++ ) {
		l1.append(i);
	}
	assert(l1.mySize == 4);
	assert(l1.myFirst->myItem == 0);
	assert(l1.myFirst->myNext->myItem == 1);
	assert(l1.myFirst->myNext->myNext->myItem == 2);
	assert(l1.myFirst->myNext->myNext->myNext->myItem == 3);
	assert(l1.myLast->myItem == 3 );

	cout << "Verify the list repeats twice.";
	cout << "\n\tIt should be displayed as: \"=0=1=2=3\"" << endl;
	cout << '\t' << l1 << endl << '\t' << l1 << endl;
	cout << "Passed! " << endl;
}

void ListTester::testInsertAfter() {
	cout << "Testing InsertAfter... " << flush;
	List<string> l1;
	assert(l1.getSize() == 0);
	string otherPersonsName = "";
	string yourName = "Daniel";

	try {
		l1.insertAfter(otherPersonsName, yourName);
	} catch (underflow_error&) {
		cout << " 0 " << flush;
	}

	// insert into a list with size one
	l1.append("Daniel");
	assert(l1.getSize() == 1);

	otherPersonsName = "Daniel";
	yourName = "Dambi";
	l1.insertAfter(otherPersonsName, yourName);
	assert(l1.getSize() == 2);
	assert(l1.getFirst() == "Daniel");
	assert(l1.myFirst->myNext->myItem == "Dambi");
	assert(l1.myFirst->myNext->myNext == nullptr);
	assert(l1.getLast() == "Dambi");
	cout << " 1 " << flush;

	// insert after the first person
	otherPersonsName = "Daniel";
	yourName = "David";
	l1.insertAfter(otherPersonsName, yourName);
	assert(l1.getSize() == 3);
	assert(l1.getFirst() == "Daniel");
	assert(l1.myFirst->myNext->myItem == "David");
	assert(l1.myFirst->myNext->myNext->myItem == "Dambi");
	assert(l1.myFirst->myNext->myNext->myNext == nullptr);
	assert(l1.getLast() == "Dambi");
	cout << " 2 " << flush;

	// insert after the last person
	otherPersonsName = "Dambi";
	yourName = "Sarah";
	l1.insertAfter(otherPersonsName, yourName);
	assert(l1.getSize() == 4);
	assert(l1.getFirst() == "Daniel");
	assert(l1.myFirst->myNext->myItem == "David");
	assert(l1.myFirst->myNext->myNext->myItem == "Dambi");
	assert(l1.myFirst->myNext->myNext->myNext->myItem == "Sarah");
	assert(l1.myFirst->myNext->myNext->myNext->myNext == nullptr);
	assert(l1.getLast() == "Sarah");
	cout << " 3 " << flush;

	// insert after middle person
	otherPersonsName = "Daniel";
	yourName = "Son";
	l1.insertAfter(otherPersonsName, yourName);
	assert(l1.getSize() == 5);
	assert(l1.getFirst() == "Daniel");
	assert(l1.myFirst->myNext->myItem == "Son");
	assert(l1.myFirst->myNext->myNext->myItem == "David");
	assert(l1.myFirst->myNext->myNext->myNext->myItem == "Dambi");
	assert(l1.myFirst->myNext->myNext->myNext->myNext->myItem == "Sarah");
	assert(l1.myFirst->myNext->myNext->myNext->myNext->myNext == nullptr);
	assert(l1.getLast() == "Sarah");
	cout << " 4 " << flush;

	// insert after non-existent name
	otherPersonsName = "Billy";
	yourName = "Bob";
	assert( l1.insertAfter(otherPersonsName, yourName) == false );
	cout << " 5 " << flush;

	cout << "Passed!" << endl;
}

void ListTester::testInsertBefore() {
	cout << "Testing InsertBefore... " << flush;
	List<string> l1;
	l1.append("Daniel");
	l1.append("Dambi");

	// insert before the first person
	string otherPersonsName = "Daniel";
	string yourName = "David";
	l1.insertBefore(otherPersonsName, yourName);
	assert(l1.getSize() == 3);
	assert(l1.getFirst() == "David");
	assert(l1.myFirst->myNext->myItem == "Daniel");
	assert(l1.myFirst->myNext->myNext->myItem == "Dambi");
	assert(l1.myFirst->myNext->myNext->myNext == nullptr);
	assert(l1.getLast() == "Dambi");
	cout << " 0 " << flush;

	// insert before the last person
	otherPersonsName = "Dambi";
	yourName = "Sarah";
	l1.insertBefore(otherPersonsName, yourName);
	assert(l1.getSize() == 4);
	assert(l1.getFirst() == "David");
	assert(l1.myFirst->myNext->myItem == "Daniel");
	assert(l1.myFirst->myNext->myNext->myItem == "Sarah");
	assert(l1.myFirst->myNext->myNext->myNext->myItem == "Dambi");
	assert(l1.myFirst->myNext->myNext->myNext->myNext == NULL);
	assert(l1.getLast() == "Dambi");
	cout << " 1 " << flush;

	// insert before the middle person
	otherPersonsName = "Daniel";
	yourName = "Son";
	l1.insertBefore(otherPersonsName, yourName);
	assert(l1.getSize() == 5);
	assert(l1.getFirst() == "David");
	assert(l1.myFirst->myNext->myItem == "Son");
	assert(l1.myFirst->myNext->myNext->myItem == "Daniel");
	assert(l1.myFirst->myNext->myNext->myNext->myItem == "Sarah");
	assert(l1.myFirst->myNext->myNext->myNext->myNext->myItem == "Dambi");
	assert(l1.myFirst->myNext->myNext->myNext->myNext->myNext == NULL);
	assert(l1.myLast->myNext == nullptr);
	assert(l1.getLast() == "Dambi");
	cout << " 2 " << flush;

	// insert before non-existent name
	otherPersonsName = "Billy";
	yourName = "Bob";

	cout << " 3 " << flush;

	cout << "Passed!" << endl;
}


