#include "BoardGame_Classes.h"



AIPlayer::AIPlayer(char symbol, Board* board):Player(symbol), board(board)
{
	this->name = "AI Player";
	cout << "My names is " << name << endl;
}
void AIPlayer::get_move(int& x, int& y)
{
	board->minimax(x, y, 1000, false, true);
}
