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
	 //cout << '\n';
	 //for (int i = 0; i < n_rows; ++i)
	 //{
		// int j = 0;
		// int spaces = n_rows - i - 1;
		// while (spaces--)
		//	cout << "       ", j++;
		// cout << "|";
		// for (; j < n_cols && board[i][j] != 'W'; ++j)
		// {
		//	if (board[i][j] == 0)
		//		cout << "(" << i << ", " << j << ")" << "|";
		//	else
		//		cout << "  " << board[i][j] << "   " << "|";
		// }
		//cout << '\n';
	 //}
	for (int i = 0; i < n_rows; ++i)
	{
		for (int j = 0; j < n_cols; ++j)
			cout << num_of_ways(i, j) << ' ';
		cout << '\n';
	}
}

bool Pyramic_Board::is_winner()
{
	if (board[0][2] && (board[0][2] & board[1][2] & board[2][2]) == board[0][2])  // handle verticall
		return true;
	
	if (board[0][2] && (board[0][2] & board[1][3] & board[2][3]) == board[0][2] || // handle diag
		board[0][2] && (board[0][2] & board[1][1] & board[2][0]) == board[0][2] )
		return true;

	if (board[1][1] && (board[1][1] & board[1][2] & board[1][3]) == board[1][1] ||
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

int Pyramic_Board::ways_verticall(int x,int y)
{
	int num_ways = 0;
	if (x + 2 < n_rows && (!board[x][y] || board[x][y] == 'O') && (!board[x + 1][y] || board[x + 1][y] == 'O') && (!board[x + 2][y] || board[x + 2][y] == 'O'))
		num_ways++;
	
	if (x + 1 < n_rows && (!board[x][y] || board[x][y] == 'O') && (!board[x + 1][y] || board[x + 1][y] == 'O') && (!board[x -1][y] || board[x -1][y] == 'O'))
		num_ways++;

	if (x < n_rows && (!board[x][y] || board[x][y] == 'O') && (!board[x - 1][y] || board[x - 1][y] == 'O') && (!board[x - 2][y] || board[x - 2][y] == 'O'))
		num_ways++;

	return num_ways;
}

int Pyramic_Board::ways_horizontall(int x, int y)
{
	int num_ways = 0;
	
	if (y + 2 <= x*2+1 && (!board[x][y] || board[x][y] == 'O') && (!board[x][y+1] || board[x][y+1] == 'O') && (!board[x][y+2] || board[x][y+2] == 'O'))
		num_ways++;

	if (y + 1 <= x * 2 + 1 && (!board[x][y] || board[x][y] == 'O') && (!board[x][y + 1] || board[x][y + 1] == 'O') && (!board[x][y -1] || board[x][y - 1] == 'O'))
		num_ways++;

	if (y <= x * 2 + 1 && (!board[x][y] || board[x][y] == 'O') && (!board[x][y - 1] || board[x][y - 1] == 'O') && (!board[x][y - 2] || board[x][y - 2] == 'O'))
		num_ways++;

	return 0;
}

int Pyramic_Board::num_of_ways(int x, int y)
{
	return ways_horizontall(x, y);
}

pair<int, int> Pyramic_Board::best_place()
{
	int best_x = 0, best_y = 0;
	for (int i = 0; i < n_rows; ++i)
	{
		for (int j = 0; j < n_cols; ++j)
			if (num_of_ways(best_x, best_y) < num_of_ways(i, j))
				best_x = i, best_y = j;
	}
	return { best_x,best_y };
}
