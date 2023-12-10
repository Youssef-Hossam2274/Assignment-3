#include <iostream>
#include <random>
#include <iomanip>
#include <algorithm>
#include "BoardGame_Classes.h"
using namespace std;

bool X_O_Board::haveTheSameValueAndNotEmpty(char x, char y, char z)
{
    if (x == y && x == z && x != 0) {
        return true;
    }
    return false;
}

int X_O_Board::checkWinner()
{
    //  2: X winner
    // -2: O winner
    //  0: Tie
    //  1: No winner

    // For rows
    for (int i = 0; i < 3; i++) {
        if (haveTheSameValueAndNotEmpty(board[i][0], board[i][1], board[i][2])) {
            return board[i][0] == 'X' ? 2 : -2;
        }
    }

    // For cols
    for (int i = 0; i < 3; i++) {
        if (haveTheSameValueAndNotEmpty(board[0][i], board[1][i], board[2][i])) {
            return board[0][i] == 'X' ? 2 : -2;
        }
    }

    // Diameter 1
    if (haveTheSameValueAndNotEmpty(board[0][0], board[1][1], board[2][2])) {
        return board[0][0] == 'X' ? 2 : -2;
    }

    // Diameter 2
    if (haveTheSameValueAndNotEmpty(board[2][0], board[1][1], board[0][2])) {
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

   //board[0][0] = 'X';
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


int X_O_Board::is_winner() {
    char row_win[3], col_win[3], diag_win[2];
    for (int i:{0,1,2}) {
        row_win[i] = board[i][0] & board[i][1] & board[i][2];
        col_win[i] = board[0][i] & board[1][i] & board[2][i];
    }
    diag_win[0] = board[0][0] & board[1][1] & board[2][2];
    diag_win[1] = board[2][0] & board[1][1] & board[0][2];

    for (int i:{0,1,2}) {
        if ((row_win[i] && (row_win[i] == 'X')) || (col_win[i] && (col_win[i] == 'X')))
            return 2;
        else if ((row_win[i] && (row_win[i] == 'O')) || (col_win[i] && (col_win[i] == 'O')))
            return -2;
    }
    if ((diag_win[0] && diag_win[0] =='X') || (diag_win[1] && diag_win[1] == 'X'))
        return 2;
    else if ((diag_win[0] && diag_win[0] == 'O') || (diag_win[1] && diag_win[1] == 'O'))
        return -2;

    if (is_draw())
        return 0;
    
    return 1;
}

bool X_O_Board::is_draw() {
    return (n_moves == 9);
}

bool X_O_Board::game_is_over () {
    return n_moves >= 9;
}

int X_O_Board::minimax(int& x, int& y, int depth, bool isMaximizing, bool firstTime)
{
    int result = checkWinner();
    if (depth == 0 || result != 1) {
        return result;
    }

    if (isMaximizing) {
        int finalScore = -10;
        int finalI, finalJ;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == 0) {
                    board[i][j] = 'X';
                    int score = minimax(x, y, depth - 1, false, false);
                    board[i][j] = 0;
                    if (score > finalScore) {
                        finalScore = score;
                        finalI = i;
                        finalJ = j;
                    }
                    if (firstTime) {
                        //cout << "score," << i << "," << j << ": " << score << "\n";
                    }
                }
            }
        }
        if (firstTime) {
            //board[finalI][finalJ] = 'O';
            x = finalI, y = finalJ;
            //cout << finalI << ' ' << finalJ << '\n';
        }
        return finalScore;
    }
    else {
        int finalScore = 10;
        int finalI, finalJ;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == 0) {
                    board[i][j] = 'O';
                    int score = minimax(x, y, depth - 1, true, false);
                    board[i][j] = 0;
                    if (score < finalScore) {
                        finalScore = score;
                        finalI = i;
                        finalJ = j;
                    }
                    if (firstTime) {
                        //cout << "score," << i << "," << j << ": " << score << "\n";
                    }
                }
            }
        }
        if (firstTime) {
            //board[finalI][finalJ] = 'O';
            x = finalI, y = finalJ;
            //cout << finalI << ' ' << finalJ << '\n';
        }
        return finalScore;
    }
}
