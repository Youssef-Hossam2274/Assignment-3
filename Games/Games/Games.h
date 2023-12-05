#pragma once
#include "BoardGame_Classes.h"
class Games 
{
public:
	void Pyramic_Tic_Tac_Toe()
	{
        int choice;
        Player* players[2];
        players[0] = new Player(1, 'X');

        cout << "Welcome to FCAI X-O Game. :)\n";
        cout << "Press 1 if you want to play with computer: ";
        cin >> choice;
        if (choice != 1)
            players[1] = new Player(2, 'O');
        else
            players[1] = new RandomPlayer('O', 3);

        GameManager x_o_game(new Pyramic_Board(), players);
        x_o_game.run();
        system("pause");
	}

	void Four_in_a_row()
	{

	}

	void Tic_Tac_Toe_5x5()
	{

	}
};

