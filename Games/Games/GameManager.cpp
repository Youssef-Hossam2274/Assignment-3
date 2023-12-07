#include <iostream>
#include"BoardGame_Classes.h"
using namespace std;

GameManager::GameManager(Board* bPtr, Player* playerPtr[2], bool flag){
    boardPtr = bPtr;
    players[0] = playerPtr[0];
    players[1] = playerPtr[1];

    if (flag == true)
        x = INT_MIN;
}

void GameManager::run() {
    int x1 = x;
    int y1 = y;
    boardPtr->display_board();

    while (!boardPtr->game_is_over()) {
        for (int i : {0, 1}) {
            players[i]->get_move(x1, y1);
            while (!boardPtr->update_board(x1, y1, players[i]->get_symbol())) {
                players[i]->get_move(x1, y1);
            }
            boardPtr->display_board();
            if (boardPtr->is_winner()) {
                cout << players[i]->to_string() << " wins\n";
                return;
            }
            if (boardPtr->is_draw()) {
                cout << "Draw!\n";
                return;
            }
        }
    }
}
