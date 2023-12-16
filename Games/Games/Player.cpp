#include<iostream>
#include<random>
#include<iomanip>
#include<algorithm>
#include"BoardGame_Classes.h"
using namespace std;

Player::Player(char symbol) {
    this->symbol = symbol;
}

Player::Player(int order, char symbol, Board* board) {
    cout << "Welcome player " << order << endl;
    cout << "Please enter your name: ";
    cin >> name;
    this->symbol = symbol;
    this->board = board;
}

void Player::get_move(int& x, int& y) {
    //char choice;
    //int i = 0, j = 0;
    //cout << "press Y if u want to AI guide to best place, else press N: ";
    //cin >> choice;
    //if (choice == 'Y' && get_symbol() == 'X')
    //    board->minimax(i, j, 100, true);
    //if (choice == 'Y' && get_symbol() == 'O')
    //    board->minimax(i, j, 100, false);
    //if (choice == 'Y')
    //    cout << "the best place is: " << i << ' ' << j << '\n';
      
        
    if (1) {
        cout << "\n" << to_string() << " with symbol " << get_symbol()
            << " enter your move x and y from available bracket separated by spaces: ";
        cin >> x >> y;
    }
    else
    {
        cout << "\n" << to_string() << " with symbol " << get_symbol()
            << " Enter the column you want to play: ";
        cin >> y;
    }

}

string Player::to_string() {
    return "Player: " + name;
}

char Player::get_symbol() {
    return symbol;
}