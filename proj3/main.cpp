/*
 * main.cpp
 *
 *  Created on: Feb 6, 2022
 *      Author: Sungmin Choi
 *      sc94
 */

#include <iostream>
#include <string>
#include <cassert>
#include "HighScores.h"
#include <stdexcept>
using namespace std;

int main() {

	// Create an instance of HighScores, and test it.
	HighScores h1;
	assert(h1.getNumScores() == 0);

	// Adding a score to hs1 and test it.
	h1.addScore(32);
	assert(h1.getNumScores() == 1);

	// Filling the array with scores
	for (int i = 0; i < 10; i++) {
		h1.addScore(i);
	}
	assert(h1.getNumScores() == 10);

	// Try to read from an index outside the range of the array, and make sure that the array is still just 10 slots.
	try {
		h1.getScore(42);
		assert(false);    // the above line should thrown an exception
	}
	catch (const invalid_argument& ie) {
		assert(h1.getNumScores() == 10);   // check to see that the array wasn't affected.
	};

	// Create a second instance of HighScores, add 2 scores, and test that they are stored properly.
	HighScores h2;
	h2.addScore(32);
	h2.addScore(8);
	assert(h2.getScore(0) == 32);
	assert(h2.getScore(1) == 8);

	// Add a third score and test that all scores are stored properly.
	h2.addScore(40);
	assert(h2.getScore(0) == 40);
	assert(h2.getScore(1) == 32);
	assert(h2.getScore(2) == 8);

	// Creating a third instance of HighScores and fill it with multiples of 8, then test that all scores are stored properly.
	HighScores h3;
	for (int i = 0; i < 10; i++) {
		h3.addScore(i * 8);
	}
	assert(h3.getScore(0) == 72);
	assert(h3.getScore(1) == 64);
	assert(h3.getScore(2) == 56);
	assert(h3.getScore(3) == 48);
	assert(h3.getScore(4) == 40);
	assert(h3.getScore(5) == 32);
	assert(h3.getScore(6) == 24);
	assert(h3.getScore(7) == 16);
	assert(h3.getScore(8) == 8);
	assert(h3.getScore(9) == 0);

	// Adding a new score, and test that all affected scores are stored properly.
	h3.addScore(42);
	assert(h3.getScore(4) == 42);
	assert(h3.getScore(5) == 40);
	assert(h3.getScore(6) == 32);
	assert(h3.getScore(7) == 24);
	assert(h3.getScore(8) == 16);
	assert(h3.getScore(9) == 8);

	//print out the test results.
	for (int i = 0; i < 10; i++) {
		cout << h3.getScore(i) << endl;
	}
	cout << "All tests passed!" << endl;
	return 0;
}
