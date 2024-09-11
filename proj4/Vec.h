/* Vec.h provides a simple vector class named Vec.
 * Student Name: Sungmin Choi (sc94)
 * Date: Feb 8
 * Begun by: Joel C. Adams, for CS 112 at Calvin University.
 */

#ifndef VEC_H_
#define VEC_H_

#include <iostream>
using namespace std;

typedef double Item;

class Vec {
public:
	Vec();
	Vec(unsigned size);
	Vec(const Vec& original);
	virtual ~Vec();
	Vec& operator=(const Vec& original);
	unsigned getSize() const;
	void setItem(unsigned index, const Item& it);
	Item getItem(unsigned index) const;
	void setSize(unsigned newSize);
	bool operator==(const Vec& v2) const;
	void writeTo(ostream& out) const;
	void readFrom(istream& in);
	Item& operator[](unsigned index);
	const Item& operator[](unsigned index) const;
	Vec operator+(const Vec& v2) const;
	Vec operator-(const Vec& v2) const;





private:
	unsigned mySize;
	Item *myArray;
	friend class VecTester;

};

#endif /*VEC_H_*/
