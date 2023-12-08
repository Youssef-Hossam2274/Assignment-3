﻿#include <iostream>
#include "BoardGame_Classes.h"

int main()
{
    cout << "Welcome to Tic Tac Toe Games :).\n\n";


    int Game_choice;
    cout << "Games with number of choice:\n\n"
        << "1) Pyramic Tic Tac Toe\n"
        << "2) Four in a row\n"
        << "3) 5x5 Tic Tac Toe\n\n";
    cout << "Choice >> ";
    cin >> Game_choice;

    cout << "\nPlay with:\n\n"
        << "1) Computer\n"
        << "2) Friend\n"
        << "3) AI (under progress)\n";
    cout << "\nChoice >> ";
    int choice;
    cin >> choice;
    cout << "\n";

    Player* players[2];
    players[0] = new Player(1, 'X');
    
    if (choice == 2)
        players[1] = new Player(2, 'O');
    else if (choice == 1)
        players[1] = new RandomPlayer('O', 3);
    else
    {
        if (Game_choice == 1)
            players[1] = new AIPlayer('O', new Pyramic_Board());
        else if (Game_choice == 2)
            players[1] = new AIPlayer('O', new connect4_Board());
        else if (Game_choice == 3)
            players[1] = new AIPlayer('O', new Five_Five_Board());
    }

    if (Game_choice == 1)
        GameManager(new Pyramic_Board(), players, false).run();
    else if (Game_choice == 2)
        GameManager(new connect4_Board(), players, true).run();
    else if (Game_choice == 3)
        GameManager(new Five_Five_Board(), players, false).run();

    system("pause");

    return 0;
}
