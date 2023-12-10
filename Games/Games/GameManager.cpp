#include <iostream>
#include"BoardGame_Classes.h"
using namespace std;

GameManager::GameManager(Board* bPtr, Player* playerPtr[2]){
    boardPtr = bPtr;
    players[0] = playerPtr[0];
    players[1] = playerPtr[1];
}

void GameManager::run() {
    int x, y;
    boardPtr->display_board();

    while (!boardPtr->game_is_over()) {
        for (int i : {0, 1}) {
            players[i]->get_move(x, y);
            if (i == 1)
                boardPtr->minimax(x, y, 100, false);
            while (!boardPtr->update_board(x, y, players[i]->get_symbol())) {
                players[i]->get_move(x, y);
            }
            boardPtr->display_board();

            if (boardPtr->is_winner() == -2 || boardPtr->is_winner() == 2) {
                cout << players[i]->to_string() << " wins\n";
                cout << boardPtr->is_winner() << '\n';
                return;
            }
            
            if (boardPtr->is_draw()) {
                cout << "Draw!\n";
                return;
            }
        }
    }
}
