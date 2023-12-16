#include <iostream>
#include "BoardGame_Classes.h"

bool Pyramic_Board::equal(char x, char y, char z)
{
	if (x == y && x == z && x != 0) {
		return true;
	}
	return false;
}

Pyramic_Board::Pyramic_Board()
{
	n_rows = 3;
	n_cols = 5;
	board = new char* [n_rows];
	for (int i = 0; i < n_rows; ++i)
	{
		board[i] = new char[n_cols];
		for (int j = 0; j < n_cols; ++j)
			board[i][j] = 'W';
	}
	for (int i = 0, j = 2; i < n_rows;++i, j--)
		for (int k = 0; k < (i * 2 + 1); ++k)
			board[i][j + k] = 0;

	// test 1
	//board[1][1] = 'X';
	//board[1][2] = 'X';
	//board[2][4] = 'X';
	//board[2][0] = 'O';
	//board[0][2] = 'O';
	//board[1][3] = 'O';
}

int Pyramic_Board::check_status()
{
	//  2: X winner
	// -2: O winner
	//  0: Tie
	//  1: No winner

	// for row
	for (int i = 0; i < n_rows; ++i)
		for (int j = 0; j < 3; ++j)
			if (equal(board[i][j], board[i][j + 1], board[i][j + 2]))
				return board[i][j] == 'X' ? 2 : -2;

	// for col
	if (equal(board[0][2], board[1][2], board[2][2]))
		return board[0][2] == 'X' ? 2 : -2;

	// for diag
	if (equal(board[0][2], board[1][1], board[2][0]) || equal(board[0][2], board[1][3], board[2][4]))
		return board[0][2] == 'X' ? 2 : -2;

	// For Tie Case
	bool tie = true;
	for (int i = 0; i < n_rows; i++) {
		for (int j = 0; j < n_cols; j++) {
			if (board[i][j] == 0) {
				tie = false;
			}
		}
	}
	if (tie)
		return 0;
	return 1;
}

bool Pyramic_Board::update_board(int x, int y, char mark)
{
	if (x < n_rows && y < n_cols && board[x][y] == 0)
	{
		board[x][y] = toupper(mark);
		n_moves++;
		return true;
	}
	return false;
}

bool Pyramic_Board::is_winner()
{
	int res = check_status();
	if (res == 2 || res == -2)
		return true;

	return false;
}

void Pyramic_Board::display_board()
{
	 cout << '\n';
	 for (int i = 0; i < n_rows; ++i)
	 {
		 int j = 0;
		 int spaces = n_rows - i - 1;
		 while (spaces--)
			cout << "       ", j++;
		 cout << "|";
		 for (; j < n_cols && board[i][j] != 'W'; ++j)
		 {
			if (board[i][j] == 0)
				cout << "(" << i << ", " << j << ")" << "|";
			else
				cout << "  " << board[i][j] << "   " << "|";
		 }
		cout << '\n';
	 }
}

bool Pyramic_Board::is_draw()
{
	return (check_status() == 0);
}

bool Pyramic_Board::game_is_over()
{
	return false;
}

int Pyramic_Board::minimax(int &x, int &y, bool isMaximizing, bool firstTime)
{
	int result = check_status();
	if (result != 1)
		return result;

	int max_score = INT_MIN, min_score = INT_MAX;
	int finalI, finalJ;

	for (int i = 0; i < n_rows; i++)
	{
		for (int j = 0; j < n_cols; j++)
		{
			if (board[i][j] == 0)
			{
				if (isMaximizing)
				{
					board[i][j] = 'X';
					int score = minimax(x, y, false, false);
					board[i][j] = 0;
					if (score >= max_score)
					{
						max_score = score;
						finalI = i;
						finalJ = j;
					}
					if (firstTime)
						cout << "in " << i << ", " << j << (score == 2 ? "X win" : (score == -2) ? "O win" : " Draw") << '\n';
				}
				else
				{
					board[i][j] = 'O';
					int score = minimax(x, y, true, false);
					board[i][j] = 0;
					if (score <= min_score)
					{
						min_score = score;
						finalI = i;
						finalJ = j;
					}
					if (firstTime)
						cout << "in " << i << ", " << j << (score == 2 ? "X win" : (score == -2) ? "O win" : " Draw") << '\n';
				}

			}
		}
	}

	if (firstTime)
		x = finalI, y = finalJ;
	return (isMaximizing ? max_score : min_score);
}