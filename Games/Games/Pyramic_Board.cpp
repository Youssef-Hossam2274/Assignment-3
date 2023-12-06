#include <iostream>
#include "BoardGame_Classes.h"

Pyramic_Board::Pyramic_Board()
{
	n_rows = 3;
	board = new char* [n_rows];
	for (int i = 0; i < n_rows; ++i)
	{
		board[i] = new char[i * 2 + 1];
		for (int j = 0; j < i * 2 + 1; ++j)
			board[i][j] = 0;
	}
}

bool Pyramic_Board::update_board(int x, int y, char mark)
{
	if (x < n_rows && y <= x * 2 && board[x][y] == 0)
	{
		board[x][y] = toupper(mark);
		n_moves++;
		return true;
	}
	return false;
}

void Pyramic_Board::display_board()
{
	cout << '\n';
	 for (int i = 0; i < n_rows; ++i)
	{
		int spaces = n_rows - i - 1;
		while (spaces--)
			cout << "       ";
		cout << "|";
		for (int j = 0; j < i * 2 + 1; ++j)
		{
			if (board[i][j] == 0)
				cout << "(" << i << ", " << j << ')' << "|";
			else
				cout << "  " << board[i][j] << "   " << "|";
		}
		cout << '\n';
	}
}

bool Pyramic_Board::is_winner()
{
	if (board[0][0] && (board[0][0] & board[1][1] & board[2][2]) == board[0][0])  // handle verticall
		return true;
	
	if (board[0][0] && (board[1][0] & board[2][0] & board[0][0]) == board[0][0] || // handle diag
		board[0][0] && (board[0][0] & board[1][2] & board[2][4]) == board[0][0] )
		return true;

	if (board[1][0] && (board[1][0] & board[1][1] & board[1][2]) == board[1][0] ||
		board[2][0] && (board[2][0] & board[2][1] & board[2][2]) == board[2][0] ||
		board[2][1] && (board[2][1] & board[2][2] & board[2][3]) == board[2][1] ||
		board[2][2] && (board[2][2] & board[2][3] & board[2][4]) == board[2][2]
		)
		return true;
	
	return false;
}

bool Pyramic_Board::is_draw()
{
	return (n_moves == 9 && !is_winner());
}

bool Pyramic_Board::game_is_over()
{
	return false;
}
