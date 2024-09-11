/*
 * main.cpp
 *
 *  Created on: Feb 4, 2022
 * Student Name: Sungmin (David) Choi (sc94)
 */

#include <cassert>
#include <iostream>

#include "CS112List.h"
using namespace std;


int main() {
	cout << "Test constructors...\n";
	CS112List<string> lst;
	assert(lst.getSize() == 0);

	CS112List<string>  lst2(5);
	assert(lst2.getSize() == 5);

	cout << "Testing getValue\n";
	assert(lst2.getValue(0) == "");
	assert(lst2.getValue(4) == "");
	try {
		assert(lst2.getValue(5) == "");
		assert(false);
	} catch (const range_error &re) {
		// do nothing here: All is well!
	}

	cout << "testing setValue\n";
	lst2.setValue(0, "hi");
	assert(lst2.getValue(0) == "hi");
	try {
		assert(lst2.getValue(5) == "");
		assert(false);
	} catch (const range_error &re) {
		// do nothing here: All is well!
	}

	cout << "Testing []\n";
	assert(lst2[0] == "hi");  // getting the value
	lst2[1] = "hello";        // setting the value.
	assert(lst2[1] == "hello");
	try {
		assert(lst2[5] == "");
		assert(false);
	} catch (const range_error &re) {
		// do nothing here: All is well!
	}

	cout << "Test copy constructor\n";
	CS112List<string> lst3(lst2);
	assert(lst3.getSize() == lst2.getSize());
	lst2[2] = "please work!";
	assert(lst3[2] != "please work!");

	cout << "Testing printing...\n";
	CS112List<string>  lst4(2);
	lst4[0] = "Emma";
	lst4[1] = "Wang";
	cout << "This is a list -->" << lst4 << "<--\n";

	cout << "Testing append...\n";
	CS112List<string>  aList;
	assert(aList.getSize() == 0);
	aList.append("Alex");
	assert(aList.getSize() == 1);
	assert(aList[0] == "Alex");
	cout << aList << endl;

	aList.append("Heyab");
	assert(aList.getSize() == 2);
	assert(aList[0] == "Alex");
	assert(aList[1] == "Heyab");
	cout << aList << endl;

	aList.append("Prof Norman is weird.");
	cout << aList << endl;

	cout << "Testing operator+" << endl;
	CS112List<string>  l1;
	l1.append("Hi");
	CS112List<string>  l2;
	l2.append("Nihao");
	l2.append("Konnichiwa");
	CS112List<string>  l3 = l1 + l2;
	cout << l3 << endl;
	assert(l3.getSize() == 3);
	assert(l3[0] == "Hi");
	assert(l3[1] == "Nihao");
	assert(l3[2] == "Konnichiwa");

	cout << "Validating index(find)..." << endl;
	assert(l3.find("Hi") == 0);
	assert(l3.find("Nihao") == 1);
	assert(l3.find("annyeonhasayo") == -1);
	cout << "Validation completed!" << endl;

	cout << "Testing negative indexes..." << endl;
	assert(l3[-1] == "Konnichiwa");
	assert(l3[-2] == "Nihao");
	assert(l3.getValue(-2) == "Nihao");
	try {
		l3[-4];
		assert(false);
	} catch (const range_error &re) {
		// nothing here.
	}
	l3[-1] = "AufWiedersehen";
	assert(l3[2] == "AufWiedersehen");
	l3.setValue(-1, "Hallo");
	assert(l3[2] == "Hallo");

	cout << "Testing insert...\n";

	CS112List<string> list1;
	list1.append("1");
	list1.append("2");
	list1.append("3");
	list1.append("4");
	list1.insert(2, "5");
	assert(list1.getSize() == 5);
	assert(list1[0] == "1");
	assert(list1[2] == "5");
	assert(list1[3] == "3");

	cout << "Testing insert complete!\n";

	cout << "Testing remove...\n";
	CS112List<string> list2;
	list2.append("1");
	list2.append("2");
	list2.append("3");
	list2.append("4");
	list2.append("5");
	assert(list2.remove("4") == true);
	assert(list2.remove("8") == false);

	cout << "Testing remove complete!\n";

	cout << "Testing removeAt...\n";
	CS112List<string> list3;
	list3.append("1");
	list3.append("2");
	list3.append("3");
	list3.append("4");
	list3.append("5");
	list3.append("6");
	list3.append("7");
	list3.append("8");
	assert (list3.getSize() == 8);
	list3.removeAt(3);
	assert(list3[3] == "5");
	assert(list3[5] == "7");

	try {
		assert(list3.getValue(14) == "");
		assert(false);
	} catch(range_error &re){
		cerr << "Index is out of range" << endl;
	}

	cout << "Testing slice..." << endl;
	CS112List<string> list4(10);
	list4.setValue(0, "1");
	list4.setValue(1, "2");
	list4.setValue(2, "3");
	list4.setValue(3, "4");
	list4.setValue(4, "5");
	list4.setValue(5, "6");
	list4.setValue(6, "7");
	list4.setValue(7, "7");
	list4.setValue(8, "8");
	list4.setValue(9, "9");
	cout << "Checking for different slices" << endl;

	//checking with positives
	cout << list4.slice(3) << endl; // 0,1,2
	cout << list4.slice(1, 3) << endl; // 1,2
	cout << list4.slice(7, 999999) << endl; // 7,8,9
	cout << list4.slice(3, 9, 5) << endl; // 3, 8
	cout << list4.slice(1, 1) << endl; //empty
	cout << endl;

	//checking with negatives
	cout << list4.slice(-7, -2) << endl; //3,4,5,6,7
	cout << list4.slice(-6, -5) << endl; //4,5
	cout << list4.slice(-10, -1, 3) << endl; // 0,3,6
	cout << list4.slice(-5, -5) << endl; //empty
	cout << "Finished slice testing!" << endl;

	cout << "All tests passed!\n";
	return 0;
}
