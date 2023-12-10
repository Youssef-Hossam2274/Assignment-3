#include <iostream>
#include "BoardGame_Classes.h"

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

	//board[0][2] = 'O';
	//board[1][1] = 'X';
	////board[1][2] = 'O';
	//board[1][3] = 'X';
	//board[2][0] = 'O';



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

int Pyramic_Board::is_winner()
{
	// 2: x win
	// -2 o win
	// 0 Tie

	if (board[0][2] && (board[0][2] & board[1][2] & board[2][2]) == board[0][2] && board[0][2] == 'X')// handle verticall
		return 2;
	
	if (board[0][2] && (board[0][2] & board[1][3] & board[2][3]) == board[0][2] && board[0][2] == 'X' || // handle diag
		board[0][2] && (board[0][2] & board[1][1] & board[2][0]) == board[0][2] && board[0][2] == 'X')
		return 2;

	if (board[1][1] && (board[1][1] & board[1][2] & board[1][3]) == board[1][1] && board[1][1] == 'X' ||
		board[2][0] && (board[2][0] & board[2][1] & board[2][2]) == board[2][0] && board[2][0] == 'X' ||
		board[2][1] && (board[2][1] & board[2][2] & board[2][3]) == board[2][1] && board[2][1] == 'X' ||
		board[2][2] && (board[2][2] & board[2][3] & board[2][4]) == board[2][2] && board[2][2] == 'X'
		)
		return 2;

	if (board[0][2] && (board[0][2] & board[1][2] & board[2][2]) == board[0][2] && board[0][2] == 'O')// handle verticall
		return -2;																				   
																								   
	if (board[0][2] && (board[0][2] & board[1][3] & board[2][3]) == board[0][2] && board[0][2] == 'O' || // handle diag
		board[0][2] && (board[0][2] & board[1][1] & board[2][0]) == board[0][2] && board[0][2] == 'O')
		return -2;																				   
																								   
	if (board[1][1] && (board[1][1] & board[1][2] & board[1][3]) == board[1][1] && board[1][1] == 'O' ||
		board[2][0] && (board[2][0] & board[2][1] & board[2][2]) == board[2][0] && board[2][0] == 'O' ||
		board[2][1] && (board[2][1] & board[2][2] & board[2][3]) == board[2][1] && board[2][1] == 'O' ||
		board[2][2] && (board[2][2] & board[2][3] & board[2][4]) == board[2][2] && board[2][2] == 'O'
		)
		return -2;

	if (is_draw())
		return 0;

	return 1;
}

bool Pyramic_Board::is_draw()
{
	return (n_moves == 9);
}

bool Pyramic_Board::game_is_over()
{
	return false;
}


int Pyramic_Board::minimax(int &x, int &y,int depth, bool isMaximizing, bool firstTime)
{
	int result = is_winner();
	if (result != 1)
		return result;

	int max_score = INT_MIN, min_score = INT_MAX;
	int resX, resY;

	if (isMaximizing)                 // X turn
	{
		for (int i = 0; i < n_rows; ++i)
		{
			for (int j = 0; j < n_cols; ++j)
			{
				if (board[i][j] == 0)                // this place is empty
				{
					board[i][j] = 'X';
					//display_board();
					int score = minimax(x, y, depth - 1, false, false);
					board[i][j] = 0;
					if (max_score < score)
					{
						max_score = score;
						resX = i; resY = j;
					}
					//cout << "max score: " << max_score << '\n';
				}
			}
		}
		if (firstTime)
		{
			x = resX;
			y = resY;
		}
		return max_score;
	}

	else
	{
		for (int i = 0; i < n_rows; ++i)
		{
			for (int j = 0; j < n_cols; ++j)
			{
				if (board[i][j] == 0)                // this place is empty
				{
					board[i][j] = 'O';
					//display_board();
					int score = minimax(x, y, depth - 1, true, false);
					board[i][j] = 0;
					if (min_score > score)
					{
						min_score = score;
						resX = i; resY = j;
					}
				}
			}
		}
		if (firstTime)
		{
			x = resX;
			y = resY;
		}
		return min_score;
	}

}
