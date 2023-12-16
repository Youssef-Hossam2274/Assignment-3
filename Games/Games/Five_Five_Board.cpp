#include <iostream>
#include "BoardGame_Classes.h"
#include <map>

Five_Five_Board::Five_Five_Board() {
    n_rows = 5;
    n_cols = 5;
    board = new char *[n_rows];
    for (int i = 0; i < n_rows; ++i) {
        board[i] = new char[n_cols];
        for (int j = 0; j < n_cols; ++j)
            board[i][j] = 0;
    }
}

int Five_Five_Board::check_status() {
    if (n_moves != 24)
        return 1;
    map<char, int> symbol_points;
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            if (board[i][j] != 0 && i <= 2 && j <= 2) {
                if (board[i][j] == board[i][j + 1] && board[i][j + 1] == board[i][j + 2])
                    symbol_points[board[i][j]]++;

                if (board[i][j] == board[i + 1][j] && board[i + 1][j] == board[i + 2][j])
                    symbol_points[board[i][j]]++;


                if (board[i][j] == board[i + 1][j + 1] && board[i + 1][j + 1] == board[i + 2][j + 2])
                    symbol_points[board[i + 1][j + 1]]++;

                if (board[i][j + 2] == board[i + 1][j + 1] && board[i + 1][j + 1] == board[i + 2][j])
                    symbol_points[board[i + 1][j + 1]]++;
            }
        }
    }
    auto it1 = symbol_points.begin();
    auto it2 = ++symbol_points.begin();
    if (it1->second == it2->second)
        return 0;
    else if (it1->second > it2->second)
        return (it1->first == 'X') ? 2 : -2;

    else
        return (it2->first == 'X') ? 2 : -2;
}

bool Five_Five_Board::update_board(int x, int y, char mark) {
    if (x < n_rows && y < n_cols && board[x][y] == 0) {
        board[x][y] = toupper(mark);
        n_moves++;
        return true;
    }
    return false;
}

bool Five_Five_Board::is_winner()
{
    int res = check_status();
    if (res == 2 || res == -2)
        return true;

    return false;
}

void Five_Five_Board::display_board() {
    cout << '\n';
    for (int i = 0; i < n_rows; ++i) {
        cout << "|";
        for (int j = 0; j < n_cols; ++j) {
            if (board[i][j] == 0)
                cout << "(" << i << ", " << j << ')' << "|";
            else
                cout << "  " << board[i][j] << "   " << "|";
        }
        cout << '\n';
    }
}

bool Five_Five_Board::is_draw() {
    return (check_status() == 0);
}

bool Five_Five_Board::game_is_over() {
    if (n_moves == 24)
        return true;
    return false;
}

int Five_Five_Board::minimax(int &x, int &y, bool isMaximizing, bool firstTime) {
    return 0;
}