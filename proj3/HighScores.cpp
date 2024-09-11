/*
 * HighScores.cpp
 *
 *  Created on: Feb 6, 2022
 *      Author: SungminChoi
 *      sc94
 */
#include "HighScores.h"
#include <stdexcept>
using namespace std;

HighScores::HighScores() {
	for (int i = 0; i < 10; i++) {
		myScores[i] = 0;
	}
	myNumScores = 0;
}

int HighScores::getNumScores() {
	return myNumScores;
}

int HighScores::getScore(int i) {
	if ((i < -1) || (i > 10)) {
		throw invalid_argument("That number is outside the range of stored values.");
	}
	return myScores[i];
}

int HighScores::findLocalToInsert(int newScore) {
	// If there is nothing in the array.
	if (myNumScores == 0) {
		return 0;
	}

	// If there are numbers in the array.
	for (int i = 0; i < 10; i++) {
		if (newScore > myScores[i]) {
			return i;
		}
	}

	return -1;
}

void HighScores::shiftUp(int fromIndex) {
	// If the new score it greater than X, move every number from X onwards up 1 index position in the array.
	for (int i = 9; i >= fromIndex + 1; i--) {
		myScores[i] = myScores[i - 1];
	}
}

void HighScores::addScore(int aScore) {
	int index = findLocalToInsert(aScore);

	// If the new score is less than all current scores.
	if (index == -1) {
		return;
	}
	else { // Else if the new score is greater than a current score.
		shiftUp(index);
		myScores[index] = aScore;

		// Keep track of how many scores are held in the array, up to 10 scores.
		if (myNumScores < 10) {
			myNumScores++;
		}
	}
}

HighScores::~HighScores() {
	// TODO Auto-generated destructor stub
}
