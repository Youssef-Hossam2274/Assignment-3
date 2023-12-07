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
	cout << "  ";
	for (int i = 0; i < n_cols; ++i) {
		cout << "   " << i;
	}
	cout << '\n';

	// Printing the game board
	for (int i = 0; i < n_rows; ++i) {
		cout << " |";
		for (int j = 0; j < n_cols; ++j) {
			cout << " _ |";
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
	// type Algorithm here:

	return false;
}

bool connect4_Board::is_draw()
{
	// type Algorithm here:

	return false;
}

bool connect4_Board::game_is_over()
{
	return false;
}
