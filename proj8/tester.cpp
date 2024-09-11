/* tester.cpp is a "driver" to run the tests in the StackTester class.
 * Joel Adams, for CS 112 at Calvin University.
 */
 
#include "StackTester.h"
#include "ReversePoemTester.h"

int main() {
//	StackTester st;
//	st.runTests();
	ReversePoemTester rpt;
	rpt.runTests();

	cout << "\nEnter the name of the poem file: ";
	string poemFile;
	cin >> poemFile;

	ReversePoem ReversePoem(poemFile);
	cout << ReversePoem.getTitle() << "\n"
			<< ReversePoem.getAuthor() << "\n"
			<< "\n*** Top-To-Bottom ***\n\n"
			<< ReversePoem.getBody()
			<< "\n*** Bottom-To-Top ***\n\n"
			<< ReversePoem.getBodyReversed()
			<< endl;
}

