#include <iostream>
#include "BoardGame_Classes.h"

connect4_Board::connect4_Board()
{
	n_rows = 6;
	n_cols = 7;
	board = new char* [n_rows];
	for (int i = 0; i < n_rows; ++i)
	{
		board[i] = new char[n_cols];
		for (int j = 0; j < n_cols; ++j)
			board[i][j] = 0;
	}
}

bool connect4_Board::update_board(int x, int y, char mark)
{
	if (y < n_rows && y >= 0) {
		for (int i = 5; i >= 0; i--) // loop over the column from buttom to the top
		{
			if (board[i][y] == 0)
			{
				board[i][y] = toupper(mark);
				n_moves++;
				return true;
			}
		}
	}
	return false;
}

void connect4_Board::display_board()
{
	cout << '\n';

	// Printing column numbers

	for (int i = 0; i < n_cols; ++i) {
		cout << "   " << i;
	}
	cout << '\n';

	// Printing the game board
	for (int i = 0; i < n_rows; ++i) {
		cout << " |";
		for (int j = 0; j < n_cols; ++j) {
			if (board[i][j] == 0) {
				cout << " _ |";
			}
			else {
				cout << " " << board[i][j] << " |";
			}
		}
		cout << '\n';
	}
	// Printing the bottom boundary
	cout << " |";
	for (int i = 0; i < n_cols; ++i) {
		cout << "___|";
	}
	cout << '\n';
}

bool connect4_Board::is_winner()
{
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++) {

			if (board[i][j] && (board[i + 1][j + 1] & board[i + 2][j + 2] & board[i + 3][j + 3]) == board[i][j]) // handle one diagonal 
				return true; // Found a diagonal match with positive slope
		}
	}

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++) {

			if (board[i][j] && (board[i + 1][j] & board[i + 2][j] & board[i + 3][j]) == board[i][j])  // handle verticall
				return true;

			if (board[i][j] && (board[i][j + 1] & board[i][j + 2] & board[i][j + 3]) == board[i][j]) // handle Horizontal
				return true;
		}
	}

	for (int i = n_rows - 1; i >= 3; i--) {
		for (int j = n_cols - 1; j >= 4; j--) {

			if (board[i][j] && (board[i - 1][j - 1] & board[i - 2][j - 2] & board[i - 3][j - 3]) == board[i][j])
				return true; // Found a diagonal match with negative slope
		}
	}

	return false; // No winner
}

bool connect4_Board::is_draw()
{
	return (n_moves == 42 && !is_winner());
	return false;

	return false;
}

bool connect4_Board::game_is_over()
{
	return false;
}

int connect4_Board::num_of_ways(int x, int y)
{
	return 0;
}

pair<int, int> connect4_Board::best_place()
{
	return pair<int, int>();
}
