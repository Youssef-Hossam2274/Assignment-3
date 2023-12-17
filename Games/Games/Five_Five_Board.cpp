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

void Five_Five_Board::update_points() {
    x_points = 0;
    o_points = 0;
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            //horizontal
            if (j <= 2 && board[i][j] != 0 && board[i][j] == board[i][j + 1] &&
                board[i][j + 1] == board[i][j + 2]) {
                (board[i][j] == 'X') ? x_points++ : o_points++;
            }
            // vertical
            if (i <= 2 && board[i][j] != 0 && board[i][j] == board[i + 1][j] &&
                board[i + 1][j] == board[i + 2][j]) {
                (board[i][j] == 'X') ? x_points++ : o_points++;
            }

            // Diagonal
            if (i <= 2 && j <= 2) {
                if (board[i][j] != 0 && board[i][j] == board[i + 1][j + 1] &&
                    board[i + 1][j + 1] == board[i + 2][j + 2]) {
                    (board[i][j] == 'X') ? x_points++ : o_points++;
                }
                if (board[i][j + 2] != 0 && board[i][j + 2] == board[i + 1][j + 1] &&
                    board[i + 1][j + 1] == board[i + 2][j]) {
                    (board[i][j + 2] == 'X') ? x_points++ : o_points++;
                }
            }
        }
    }
}

bool Five_Five_Board::is_winner() {
    update_points();
    if (n_moves != 24) {
        cout << "X has points -> " << x_points << endl;
        cout << "Y has points -> " << o_points << endl;
        return false;
    }
    if (x_points == o_points)
        cout << "Draw!\n";
    else if (x_points > o_points)
        cout << "player with symbol X" << " wins with " << x_points << " points\n";

    else
        cout << "player with symbol Y" << " wins with " << o_points << " points\n";
    return false;
}

bool Five_Five_Board::is_draw() {
    return false;
}

bool Five_Five_Board::game_is_over() {
    if (n_moves == 24)
        return true;
    return false;
}

bool Five_Five_Board::update_board(int x, int y, char mark) {
    if (x < n_rows && y < n_cols && board[x][y] == 0) {
        board[x][y] = toupper(mark);
        n_moves++;
        return true;
    }
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


int Five_Five_Board::minimax(int &x, int &y, bool isMaximizing, bool firstTime) {
//    int max_x_points = 0;
//    int max_o_points = 0;
//    int final_x, final_y;
//    for (int i = 0; i < n_rows; ++i) {
//        for (int j = 0; i < n_cols; ++j) {
//            if (board[i][j] != 0) {
//                board[i][j] = 'O';
//                update_points();
//                if (o_points > max_o_points) {
//                    final_x = i;
//                    final_y = j;
//                    max_o_points = o_points;
//                }
//                board[i][j] = 0;
//            }
//        }
//    }
//    if(max_o_points == 0){
//        for (int i = 0; i < n_rows; ++i) {
//            for (int j = 0; i < n_cols; ++j) {
//                if (board[i][j] != 0) {
//                    board[i][j] = 'X';
//                    update_points();
//                    if (x_points > max_x_points) {
//                        final_x = i;
//                        final_y = j;
//                        max_x_points = x_points;
//                    }
//                    board[i][j] = 0;
//
//                }
//            }
//        }
//    }
//    if(max_x_points == 0){
//        x = (int)(rand() / (RAND_MAX + 1.0) * 5);
//        y = (int)(rand() / (RAND_MAX + 1.0) * 5);
//    }


}