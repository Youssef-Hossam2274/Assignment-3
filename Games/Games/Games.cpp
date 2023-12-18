#include <iostream>
#include "BoardGame_Classes.h"

// FCAI - OOP Programming - 2023 - Assignment 3
// Program Name: Games.cpp
// Last Modification Date:  17/12/2023
// Author1 and ID and Group:  Abdullah Saeed Alnami  20220705  bdallhsydalnmy@gmail.com Section 9
// Author2 and ID and Group:  Eslam Sayed Younus     20220495  eslam894408@gmail.com    Section 9
// Author3 and ID and Group:  Youssef Hossam Ahmed   20220390  y.hossam2274@gmail.com   Section 9
// Teaching Assistant: Samar Sabry Shaker

// Purpose: Making Game App that contain 3 Games Tic Tac Toe(Pyramic, Four in a row, 5x5)


void play() {
    Board *board = nullptr;
    Player *players[2];

    cout << "Welcome to Tic Tac Toe Games :).\n\n";

    cout << "Games with number of choice:\n\n"
         << "1) Pyramic Tic Tac Toe\n"
         << "2) Four in a row\n"
         << "3) 5x5 Tic Tac Toe\n"
         << "4) X-O Tic Tac Toe\n\n";
    cout << "Choice >> ";
    int Game_choice;
    cin >> Game_choice;

    if (Game_choice == 1)
        board = new Pyramic_Board();
    else if (Game_choice == 2)
        board = new connect4_Board();
    else if (Game_choice == 3)
        board = new Five_Five_Board();
    else if (Game_choice == 4)
        board = new X_O_Board();

    int dimension;
    if (Game_choice == 2)
        dimension = 7;
    else if (Game_choice == 3)
        dimension = 5;
    else
        dimension = 3;



    cout << "\nPlay with:\n\n"
        << "1) Computer\n"
        << "2) Friend\n";
    cout << "\nChoice >> ";
    int choice;
    cin >> choice;
    cout << "\n";

    players[0] = new Player(1, 'X', board);
    if (choice == 1)
        players[1] = new RandomPlayer('O', dimension);
    else if (choice == 2)
        players[1] = new Player(2, 'O', board);
    else if (choice == 3)
        players[1] = new AIPlayer('O', board);


    GameManager game(board, players);
    game.run();

}


int main() {
    play();
    return 0;
}
