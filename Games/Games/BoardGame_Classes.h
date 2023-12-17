#pragma once
#include <iostream>
using namespace std;
class Board {
protected:
	int n_rows, n_cols;
	char** board;
	int  n_moves = 0;

public:

	virtual bool update_board(int x, int y, char symbol) = 0;
	virtual bool is_winner() = 0;
	virtual bool is_draw() = 0;
	virtual void display_board() = 0;
	virtual bool game_is_over() = 0;
	virtual int minimax(int &x, int &y, bool isMaximizing, bool firstTime = true) = 0;
};

class X_O_Board :public Board {
private:
	bool equal(char x, char y, char z);
	int check_status();
public:
	X_O_Board();
	bool update_board(int x, int y, char mark);
	bool is_winner();
	void display_board();
	bool is_draw();
	bool game_is_over();
	int minimax(int& x, int& y, bool isMaximizing, bool firstTime = true);
};

class Pyramic_Board :public Board {
private:
	bool equal (char x, char y, char z);
	int check_status();
public:
	Pyramic_Board();
	bool update_board(int x, int y, char mark);
	bool is_winner();
	void display_board();
	bool is_draw();
	bool game_is_over();
	int minimax(int &x, int &y, bool isMaximizing, bool firstTime = true);
};

class connect4_Board :public Board {
private:
	int check_status();
public:
	connect4_Board();
	bool update_board(int x, int y, char mark);
	bool is_winner();
	void display_board();
	bool is_draw();
	bool game_is_over();
	int minimax(int &x, int &y, bool isMaximizing, bool firstTime = true);
};

class Five_Five_Board :public Board {
private:
    void update_points();
        int x_points = 0;
        int o_points = 0;

public:
	Five_Five_Board();
	bool update_board(int x, int y, char mark);
	bool is_winner();
	void display_board();
	bool is_draw();
	bool game_is_over();
	int minimax(int& x, int& y, bool isMaximizing, bool firstTime = true);
};

class Player {
protected:
	string name;
	char symbol;
	Board* board;
public:
	Player(char symbol);
	Player(int order, char symbol, Board* board);
	virtual void get_move(int& x, int& y);
	string to_string();
	char get_symbol();
};


class RandomPlayer : public Player {
protected:
	int dimension;
public:
	RandomPlayer(char symbol, int dimension);
	void get_move(int& x, int& y);
};

class AIPlayer :public Player
{
private:
	Board* board;
public:
	AIPlayer(char symbol, Board*board);
	void get_move(int& x, int& y);
};



class GameManager {
private:
	Board* boardPtr;
	Player* players[2];
public:
	GameManager(Board*, Player* playerPtr[2]);
	void run();
};