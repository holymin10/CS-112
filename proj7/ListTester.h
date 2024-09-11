/* ListTester.h declares the test-class for class List.
 * Joel Adams, for CS 112 at Calvin University.
 *      Author: Sungmin (David) Choi (sc94)
 *
 */

#ifndef LISTTESTER_H_
#define LISTTESTER_H_

class ListTester {
public:
	void runTests();
	void testDefaultConstructor();
	void testNodeDefaultConstructor();
	void testNodeExplicitConstructor();
	void testPrepend();
	void testAppend();
	void testDestructor();
	void testCopyConstructor();
	void testEquality();
	void testWriteTo();
	void testgetIndexOf();
	void testOutput();
	void testInsertAfter();
	void testInsertBefore();
};

#endif /*LISTTESTER_H_*/
