#include <iostream>
#include "BoardGame_Classes.h"

void play()
{
    cout << "Welcome to Tic Tac Toe Games :).\n\n";


    int Game_choice;
    cout << "Games with number of choice:\n\n"
        << "1) Pyramic Tic Tac Toe\n"
        << "2) Four in a row\n"
        << "3) 5x5 Tic Tac Toe\n"
        << "4) X-O Tic Tac Toe\n\n";
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
        else if (Game_choice == 4)
            players[1] = new AIPlayer('O', new X_O_Board());
    }

    if (Game_choice == 1)
        GameManager(new Pyramic_Board(), players).run();
    else if (Game_choice == 2)
        GameManager(new connect4_Board(), players).run();
    else if (Game_choice == 3)
        GameManager(new Five_Five_Board(), players).run();    
    else if (Game_choice == 4)
        GameManager(new X_O_Board(), players).run();

    system("pause");
}

void TestAI_1()
{
    Player* players[2];
    players[0] = new Player(1, 'X');
    players[1] = new AIPlayer('O', new X_O_Board());

    GameManager(new X_O_Board(), players).run();
}

void TestAI_2()
{
    int x, y; 
    Board* board = new X_O_Board();
    board->display_board();

    cin >> x >> y;
    board->update_board(x, y, 'X');

    board->minimax(x, y, 100, false);
    cout << x << ' ' << y;
    board->display_board();
    
    cin >> x >> y;
    board->update_board(x, y, 'X');

    board->minimax(x, y, 100, false);
    cout << x << ' ' << y;
    board->display_board();

    cin >> x >> y;
    board->update_board(x, y, 'X');

    board->minimax(x, y, 100, false);
    cout << x << ' ' << y;
    board->display_board();

    cin >> x >> y;
    board->update_board(x, y, 'X');

    board->minimax(x, y, 100, false);
    cout << x << ' ' << y;
    board->display_board();
}

void TestAI_3()
{
    Player* players[2];
    Board* board;
    board = new X_O_Board();

    players[0] = new Player(1, 'X');
    players[1] = new AIPlayer('O', board);
    GameManager game(board, players);
    game.run();
    
    
}

void TestAI_4()
{
    Board* board = nullptr;
    Player* players[2];
    
    cout << "Welcome to Tic Tac Toe Games :).\n\n";

    cout << "Games with number of choice:\n\n"
        << "1) Pyramic Tic Tac Toe\n"
        << "2) Four in a row\n"
        << "3) 5x5 Tic Tac Toe\n"
        << "4) X-O Tic Tac Toe\n\n";
    cout << "Choice >> ";
    int Game_choice;
    cin >> Game_choice;

    players[0] = new Player(1, 'X');
    if (Game_choice == 1)
        board = new Pyramic_Board();
    else if (Game_choice == 2)
        board = new connect4_Board();
    else if (Game_choice == 3)
        board = new Five_Five_Board();
    else if (Game_choice == 4)
        board = new X_O_Board();


    cout << "\nPlay with:\n\n"
        << "1) Computer\n"
        << "2) Friend\n"
        << "3) AI (under progress)\n";
    cout << "\nChoice >> ";
    int choice;
    cin >> choice;
    cout << "\n";

    if (choice == 1)
        players[1] = new RandomPlayer('O', 3);
    else if (choice == 2)
        players[1] = new Player(2, 'O');
    else if (choice == 3)
        players[1] = new AIPlayer('O', board);

    GameManager game(board, players);
    game.run();

}


int main()
{
    //play();
    //TestAI_1();
    //TestAI_2();
    //TestAI_3();
    TestAI_4();
    return 0;
}
