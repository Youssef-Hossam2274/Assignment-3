#include "BoardGame_Classes.h"



AIPlayer::AIPlayer(char symbol, Board* board):Player(symbol), board(board)
{
	this->name = "AI Player";
	cout << "My names is " << name << endl;
}
void AIPlayer::get_move(int& x, int& y)
{
	x = board->best_place().first;
	y = board->best_place().second;
}
