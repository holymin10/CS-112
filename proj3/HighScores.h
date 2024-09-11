/*
 * HighScores.h
 *
 *  Created on: Feb 6, 2022
 *      Author: SungminChoi
 *      sc94
 */

#ifndef HIGHSCORES_H_
#define HIGHSCORES_H_

class HighScores {
public:
    HighScores();
    virtual ~HighScores();

    // Getters
    int getNumScores();
    int getScore(int i);

    // Setters
    void addScore(int aScore);

private:
    int myScores[10];
    int myNumScores;

    int findLocalToInsert(int newScore);

    void shiftUp(int fromIndex);
};

#endif /* HIGHSCORES_H_ */