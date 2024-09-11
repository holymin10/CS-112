/* StackTester.cpp defines test-methods for the 
 *  dynamically allocated (array) Stack operations
 * Joel Adams, for CS 112 at Calvin University
 * Student Name: Sungmin (David) Choi (sc94)
 * Date: 03/21/2022
 */

#include "StackTester.h"
#include "StackException.h"
#include "Stack.h"
#include <iostream>  // cout, cerr, ...
#include <cassert>   // assert()
#include <cstdlib>   // exit()
using namespace std;

void StackTester::runTests() {
	cout << "Testing Stack class..." << endl;
	testConstructor();
	testIsEmpty();
	testPushPeekTopAndIsFull();
	testPop();
	testCopyConstructor();
	testAssignment();
	testDestructor();
	testgetSize();
	testgetCapacity();
	testsetCapacity();
	cout << "All tests passed!" << endl;
}

void StackTester::testConstructor() {
	cout << "- Testing constructor... " << flush;
	// invalid parameter
	try {
		Stack<unsigned> s1(0);
		cerr << "\nConstructed stack of size 0\n";
		exit(1);
	} catch (const StackException& se) {
		cout << se << flush;
		cout << " 0 " << flush;
	}
	// valid parameter
	Stack<unsigned> s2(3);
	cout << " 1 " << flush;
	cout << " Passed!" << endl;
}

void StackTester::testIsEmpty() {
	cout << "- Testing isEmpty()... " << flush;
	// capacity 1
	Stack<unsigned> s1(1);
	assert( s1.isEmpty() );
	cout << " 1 " << flush;
	// capacity > 1
	Stack<unsigned> s2(3);
	assert( s2.isEmpty() );
	cout << " 2 " << flush;
	cout << " Passed!" << endl;
}


void StackTester::testPushPeekTopAndIsFull() {
	cout << "- Testing push()... " << flush;
	// test with capacity 1
	Stack<unsigned> s1(1);
	s1.push(11);
	assert( s1.peekTop() == 11 );
	assert( !s1.isEmpty() );
	assert( s1.isFull() );
	try {
		s1.push(22);
		cerr << "\npush() worked on a full stack (size 1)\n";
		exit(1);
	} catch (const StackException& se) {
		cout << " 1 " << flush;
	}
//	 test with capacity > 1
	Stack<unsigned> s2(3);
	s2.push(11);
	assert( s2.peekTop() == 11 );
	s2.push(22);
	assert( s2.peekTop() == 22 );
	s2.push(33);
	assert( s2.peekTop() == 33 );
	try {
		s2.push(44);
		cerr << "\npush() worked on a full stack (size 3)\n";
		exit(1);
	} catch (const StackException& se) {
		cout << " 2 " << flush;
	}
	cout << " Passed! " << endl;
}

void StackTester::testPop() {
	cout << "- Testing pop()... " << flush;
	// try empty, capacity 1
	Stack<unsigned> s1(1);
	assert( s1.isEmpty() );
    try {
            s1.peekTop();
            cerr << "\npeekTop() worked on empty stack (size 1)\n";
            exit(1);
    } catch (const StackException& se) {
            cout << " 0a " << flush;
    }
	try {
		s1.pop();
		cerr << "\npop() worked on empty stack (size 1)\n";
		exit(1);
	} catch (const StackException& se) {
		cout << " 0b " << flush;
	}

	// try empty, capacity > 1
	Stack<unsigned> s2(3);
	try {
		s2.pop();
		cerr << "\npop() worked on empty stack (size 3)\n";
		exit(1);
	} catch (const StackException& se) {
		cout << " 1a " << flush;
	}
    try {
            s2.peekTop();
            cerr << "\npeekTop() worked on empty stack (size 3)\n";
            exit(1);
    } catch (const StackException& se) {
            cout << " 1b " << flush;
    }

	// try non-empty, capacity 1
	Stack<unsigned> s3(1);
	s3.push(11);
	assert( s3.peekTop() == 11 );
	assert( s3.pop() == 11 );
	cout << " 2 " << flush;
	try {
		s3.pop();
		cerr << "\ns3.pop() worked on empty stack (size 1)\n";
		exit(1);
	} catch (const StackException& se) {
		cout << " 2a " << flush;
	}
    try {
            s3.peekTop();
            cerr << "\ns3.peekTop() worked on empty stack (size 1)\n";
            exit(1);
    } catch (const StackException& se) {
            cout << " 2b " << flush;
    }

	// try non-empty, capacity > 1
	Stack<unsigned> s4(3);
	s4.push(11);
	s4.push(22);
	s4.push(33);
	assert( s4.peekTop() == 33 );
	assert( s4.pop() == 33 );
	assert( s4.peekTop() == 22 );
	assert( s4.pop() == 22 );
	assert( s4.peekTop() == 11 );
	assert( s4.pop() == 11 );
	cout << " 3 " << flush;
	try {
		s4.pop();
		cerr << "\ns4.pop() worked on empty stack (size 3)\n";
		exit(1);
	} catch (const StackException& se) {
		cout << " 3a " << flush;
	}
    try {
            s4.peekTop();
            cerr << "\ns4.peekTop() worked on empty stack (size 3)\n";
            exit(1);
    } catch (const StackException& se) {
            cout << " 3b " << flush;
    }

	cout << " Passed!" << endl;
}

void StackTester::testCopyConstructor() {
	cout << "- Testing copy constructor... " << flush;
	// minimal empty Stack
	Stack<unsigned> s1(1);
	Stack<unsigned> s2(s1);
	assert( s2.isEmpty() );
	assert( s2.myArray != nullptr );
	assert( s2.myCapacity == 1 );
	assert( s2.myArray != s1.myArray );
	cout << " 1 " << flush;
	// minimal non-empty Stack
	Stack<unsigned> s3(1);
	s3.push(11);
	Stack<unsigned> s4(s3);
	assert( !s4.isEmpty() );
	assert( s4.isFull() );
	assert( s4.peekTop() == 11 );
	assert( s4.myArray != s3.myArray );
	cout << " 2 " << flush;
	// non-minimal, non-empty stack
	Stack<unsigned> s5(3);
	s5.push(11);
	s5.push(22);
	s5.push(33);
	Stack<unsigned> s6(s5);
	assert( s6.myCapacity == s5.myCapacity );
	assert( s6.mySize == s5.mySize );
	assert( s6.myArray != s5.myArray );
	assert( s6.pop() == 33 );
	assert( s6.pop() == 22 );
	assert( s6.pop() == 11 );
	assert( s5.peekTop() == 33 );
	cout << " 3 " << flush;
	cout << "Passed!" << endl;
}

void StackTester::testAssignment() {
	cout << "- Testing assignment... " << flush;
	// minimal empty Stacks, same size
	Stack<unsigned> s1(1);
	Stack<unsigned> s2(1);
	s2 = s1;
	assert( s2.isEmpty() );
	assert( s2.myArray != nullptr );
	assert( s2.myArray != s1.myArray );
	assert( s2.myCapacity == 1 );
	cout << " 1 " << flush;
	// minimal non-empty Stack to empty Stack, same capacity
	Stack<unsigned> s3(1);
	s3.push(11);
	Stack<unsigned> s4(1);
	s4 = s3;
	assert( !s4.isEmpty() );
	assert( s4.isFull() );
	assert( s4.peekTop() == 11 );
	assert( s4.myArray != s3.myArray );
	cout << " 2 " << flush;
	// minimal empty stack to non-empty stack, same capacity
	Stack<unsigned> s5(1);
	Stack<unsigned> s6(1);
	s6.push(11);
	s6 = s5;
	assert( s6.isEmpty() );
	assert( s6.myArray != nullptr );
	assert( s6.myArray != s5.myArray );
	assert( s6.myCapacity == 1 );
	cout << " 3 " << flush;
	// non-minimal non-empty stack to empty stack, different capacities
	Stack<unsigned> s7(3);
	s7.push(11);
	s7.push(22);
	s7.push(33);
	Stack<unsigned> s8(2);
	s8 = s7;
	assert( s8.myArray != s7.myArray );
	assert( s8.myCapacity == s7.myCapacity );
	assert( s8.mySize == s7.mySize );
	assert( s8.pop() == 33 );
	assert( s8.pop() == 22 );
	assert( s8.pop() == 11 );
	assert( s7.peekTop() == 33 );
	cout << " 4 " << flush;
	// non-minimal, empty stack to non-empty stack, different capacities
	Stack<unsigned> s9(2);
	Stack<unsigned> s10(3);
	s10.push(11);
	s10.push(22);
	s10.push(33);
	s10 = s9;
	assert( s10.isEmpty() );
	assert( s10.myArray != s9.myArray );
	assert( s10.myCapacity == s10.myCapacity );
	cout << " 5 " << flush;
	// self-assignment, minimal size
	Stack<unsigned> s11(1);
	s11.push(11);
	s11 = s11;
	assert( s11.isFull() );
	assert( !s11.isEmpty() );
	cout << " 6 " << flush;
	// chaining
	Stack<unsigned> s12(2);
	s12.push(11);
	s12.push(22);
	Stack<unsigned> s13(1);
	Stack<unsigned> s14(1);
	s14 = s13 = s12;
	assert( s14.isFull() );
	assert( s14.myArray != s13.myArray );
	assert( s14.myArray != s12.myArray );
	assert( s14.pop() == 22 );
	assert( s14.pop() == 11 );
	assert( s14.isEmpty() );
	cout << " 7 " << flush;
      // self-assignment, non-minimal size
      s13 = s13;
	assert( !s13.isEmpty() );
	assert( s13.isFull() );
	assert( s13.pop() == 22 );
	assert( s13.pop() == 11 );
	assert( s13.isEmpty() );
	cout << " 8 " << flush;
	cout << "Passed!" << endl;
}

void StackTester::testDestructor() {
	cout << "- Testing destructor..." << flush;
	// minimal, empty
	Stack<unsigned> s1(1);
	s1.~Stack();
	assert( s1.isEmpty() );
	assert( s1.myArray == nullptr );
	assert( s1.myCapacity == 0 );
	cout << " 1 " << flush;
	// minimal, non-empty
	Stack<unsigned> s2(1);
	s2.push(11);
	s2.~Stack();
	assert( s2.isEmpty() );
	assert( s2.myArray == nullptr );
	assert( s2.myCapacity == 0 );
	cout << " 2 " << flush;
	// non-minimal, empty
	Stack<unsigned> s3(3);
	s3.~Stack();
	assert( s3.isEmpty() );
	assert( s3.myArray == nullptr );
	assert( s3.myCapacity == 0 );
	cout << " 3 " << flush;
	// non-minimal, non-empty
	Stack<unsigned> s4(3);
	s4.push(11);
	s4.push(22);
	s4.push(33);
	s4.~Stack();
	assert( s4.isEmpty() );
	assert( s4.myArray == nullptr );
	assert( s4.myCapacity == 0 );
	cout << " 4 " << flush;
	cout << " Passed!" << endl;
}

void StackTester::testgetSize() {
	cout << "Testing getSize operation..." << flush;
	Stack<unsigned> a1(5);
	a1.push(11);
	a1.push(22);
	a1.push(33);
	a1.push(44);
	assert(a1.getSize() == 4);
	a1.pop();
	a1.pop();
	assert(a1.getSize() == 2);
	cout << "Test completed!" << endl;
}

void StackTester::testgetCapacity() {
	cout << "Testing getCapacity operation..." << flush;
	Stack<unsigned> a2(6);
	a2.push(99);
	a2.push(88);
	a2.push(77);
	a2.push(66);
	assert(a2.getCapacity() == 6);
	cout << "Test completed!" << endl;
}

void StackTester::testsetCapacity() {
	cout << "Setting new Capacity..." << flush;
	Stack<unsigned> a3(5);
	a3.push(10);
	a3.push(20);
	a3.push(30);
	a3.push(40);
	a3.push(50);
	assert(a3.getSize() == 5);
	assert(a3.getCapacity() == 5);
	assert(a3.peekTop() == 50);
	assert(a3.isFull());
	cout << "1... ";
	a3.setCapacity(7);
	assert(a3.getSize() == 5);
	assert(a3.getCapacity() == 7);
	assert(a3.peekTop() == 50);
	assert(!a3.isFull());
	cout << "2... ";
	a3.push(60);
	a3.push(70);
	assert(a3.getSize() == 7);
	assert(a3.peekTop() == 70);
	assert(a3.isFull());
	cout << "3... ";
	cout << "Test completed!" << endl;
}
