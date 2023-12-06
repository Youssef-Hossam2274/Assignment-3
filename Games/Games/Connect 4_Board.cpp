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
	if (x < n_rows && y < n_cols && board[x][y] == 0)
	{
		board[x][y] = toupper(mark);
		n_moves++;
		return true;
	}
	return false;
}

void connect4_Board::display_board()
{
	cout << '\n';
	for (int i = 0; i < n_rows; ++i)
	{
		cout << "|";
		for (int j = 0; j < n_cols; ++j)
		{
			if (board[i][j] == 0)
				cout << "(" << i << ", " << j << ')' << "|";
			else
				cout << "  " << board[i][j] << "   " << "|";
		}
		cout << '\n';
	}
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
