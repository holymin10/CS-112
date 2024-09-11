/*
 * utils.cpp
 *
 *  Created on: Jan 31, 2022
 *      Author: sungminchoi
 */

#include <iostream>
#include <iomanip>
using namespace std;

const unsigned int defaultsize = 15;

int printBoard(int board[][defaultsize], int rows, int cols){
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j){
			cout << board[i][j] << ' ';
		}
		cout << endl;
	} return 0;
}


void buildSquare(int size = 15) {
	int k = 1;
	int x = size;
	int rows = 0;
	int col = size / 2;
	int max = size * size;
	int board[15][15];

	for (int i = 0; i < x; ++i) {
		for (int j = 0; j < x; ++j){
			board[i][j] = 0;
		}
	}
	while (k <= max) {
		while (board[rows][col] == 0 || rows < 0 || col == size){
			if (rows < 0 && col == size){
				rows = 1;
				col = size - 1;
			}
			else {
				if (rows < 0) {
					rows = size - 1;
				}
				if (col == x) {
					col = 0;
				}
			}
			board[rows][col] = k;
			--rows;
			++col;
			++k;
		}
		rows += 2;
		--col;
	}
	cout << setw(printBoard(board, size, size));
}


