/* VecTester.h provides unit tests for Vec, a simple vector class.
 * Student Name: Sungmin Choi (sc94)
 * Student Name: Youngha Kweon (yk85)
 * Date: Feb 8
 * Begun by: Joel C. Adams, for CS 112 at Calvin University.
 */

#ifndef VECTESTER_H_
#define VECTESTER_H_

#include "Vec.h"

class VecTester {
public:
	void runTests() const;
	void testDefaultConstructor() const;
	void testExplicitConstructor() const;
	void testDestructor() const;
	void testGetSize() const;
	void testSetItem() const;
	void testGetItem() const;
	void testSetSize() const;
	void testCopyConstructor() const;
	void testAssignment() const;
	void testEquality() const;
	void testWriteToStream() const;
	void testReadFromStream() const;
	void testSubscript() const;
	void testInequality() const;
	void testAddition() const;
	void testSubtraction() const;
	void testDotProduct() const;
	void testReadFromFile() const;
	void testWriteToFile() const;
};

#endif /*VECTESTER_H_*/
