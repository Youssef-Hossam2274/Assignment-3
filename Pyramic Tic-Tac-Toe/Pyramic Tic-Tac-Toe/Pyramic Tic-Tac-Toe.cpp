#include <iostream>
#include "BoardGame_Classes.h"

int main()
{
    int choice;
    Player* players[2];
    players[0] = new Player(1, 'x');

    cout << "Welcome to FCAI X-O Game. :)\n";
    cout << "Press 1 if you want to play with computer: ";
    cin >> choice;
    if (choice != 1)
        players[1] = new Player(2, 'o');
    else
        players[1] = new RandomPlayer('o', 3);

    GameManager x_o_game(new Pyramic_Board(), players);
    x_o_game.run();
    system("pause");

	return 0;
}
