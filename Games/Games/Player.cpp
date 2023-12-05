#include<iostream>
#include<random>
#include<iomanip>
#include<algorithm>
#include"BoardGame_Classes.h"
using namespace std;

Player::Player(char symbol) {
    this->symbol = symbol;
}

Player::Player(int order, char symbol) {
    cout << "Welcome player " << order << endl;
    cout << "Please enter your name: ";
    cin >> name;
    this->symbol = symbol;
}

void Player::get_move(int& x, int& y) {
    cout  << "\n" << to_string() << " with symbol " << get_symbol()
          <<  " enter your move x and y from available bracket separated by spaces: ";
    cin >> x >> y;
}

string Player::to_string() {
    return "Player: " + name;
}

char Player::get_symbol() {
    return symbol;
}