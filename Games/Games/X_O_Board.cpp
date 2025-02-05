#include <iostream>
#include <random>
#include <iomanip>
#include <algorithm>
#include "BoardGame_Classes.h"
using namespace std;

bool X_O_Board::equal(char x, char y, char z)
{
    if (x == y && x == z && x != 0) {
        return true;
    }
    return false;
}

int X_O_Board::check_status() {
    //  2: X winner
    // -2: O winner
    //  0: Tie
    //  1: No winner

    // For rows
    for (int i = 0; i < 3; i++) {
        if (equal(board[i][0], board[i][1], board[i][2])) {
            return board[i][0] == 'X' ? 2 : -2;
        }
    }

    // For cols
    for (int i = 0; i < 3; i++) {
        if (equal(board[0][i], board[1][i], board[2][i])) {
            return board[0][i] == 'X' ? 2 : -2;
        }
    }

    // Diameter 1
    if (equal(board[0][0], board[1][1], board[2][2])) {
        return board[0][0] == 'X' ? 2 : -2;
    }

    // Diameter 2
    if (equal(board[0][2], board[1][1], board[2][0])) {
        return board[2][0] == 'X' ? 2 : -2;
    }

    // For Tie Case
    bool tie = true;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == 0) {
                tie = false;
            }
        }
    }
    if (tie) return 0;

    // Else
    return 1;
}

X_O_Board::X_O_Board () {
   n_rows = n_cols = 3;
   board = new char*[n_rows];
   for (int i = 0; i < n_rows; i++) {
      board [i] = new char[n_cols];
      for (int j = 0; j < n_cols; j++)
         board[i][j] = 0;
   }

   // test 1
   //board[0][0] = 'X';
   //board[0][1] = 'X';
   //board[1][1] = 'X';
   //board[0][2] = 'O';
   //board[1][0] = 'O';
   //board[2][2] = 'O';

   // test 2
   //board[0][0] = 'X';
   //board[0][2] = 'X';
   //board[1][0] = 'O';
   //board[0][1] = 'O';
   
   // test 3
   //board[0][0] = 'X';
   //board[0][2] = 'X';
   //board[0][1] = 'O';
   //board[1][1] = 'O';
   

}

bool X_O_Board::update_board (int x, int y, char mark){
   if (!(x < 0 || x > 2 || y < 0 || y > 2) && (board[x][y] == 0)) {
      board[x][y] = toupper(mark);
      n_moves++;
      return true;
   }
   else
      return false;
}

bool X_O_Board::is_winner()
{
    int res = check_status();
    if (res == 2 || res == -2)
        return true;

    return false;
}

void X_O_Board::display_board() {
    
    cout << '\n';
   for (int i = 0; i < n_rows; ++i)
   {
       cout << "|";
       for (int j = 0; j < n_cols && board[i][j] != 'W'; ++j)
       {
           if (board[i][j] == 0)
               cout << "(" << i << ", " << j << ")" << "|";
           else
               cout << "  " << board[i][j] << "   " << "|";
       }
       cout << '\n';
   }
}

bool X_O_Board::is_draw() {
    return (check_status() == 0);
}

bool X_O_Board::game_is_over () {
    return n_moves >= 9;
}

int X_O_Board::minimax(int& x, int& y, bool isMaximizing, bool firstTime)
{
    int result = check_status();
    if (result != 1)
        return result;

    int max_score = INT_MIN, min_score = INT_MAX;
    int finalI, finalJ;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
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
                        cout << "in " << i << ", " << j << (score == 2 ? "X win" : (score == -2) ? "O win" : " Draw");
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
                        cout << "in " << i << ", " << j << (score == 2 ? " X win" : (score == -2) ? " O win" : " Draw") << '\n';
                }
            }
        }
    }

    if (firstTime)
        x = finalI, y = finalJ;
    return (isMaximizing ? max_score : min_score);
}
