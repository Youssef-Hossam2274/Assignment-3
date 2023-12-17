#include <iostream>
#include "BoardGame_Classes.h"

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

    int dimension = (Game_choice == 3) ? 5 : 3;

    cout << "\nPlay with:\n\n"
         << "1) Computer\n"
         << "2) Friend\n"
         << "3) AI (under progress)\n";
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
    //TestAI_1();
    return 0;
}
