#include <iostream>
#include <vector>
#include <chrono>
#include <thread>

using namespace std;

class Universe {
    int size;
    vector<vector<string> > vec;

public:
    explicit Universe(const int &size) : size(size),
                                         vec(size, vector<string>(size, "⬛")) {
        cout << "-----------Game of life-----------\n";
    }

    void display() const {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                cout << vec[i][j];
            }
            cout << endl;
        }
    }

    int count_neighbours(const int &row, const int &column) {
        int num_neighbours = 0;

        // Iterate over the 3x3 neighborhood
        for (int i = row - 1; i < row + 2; i++) {
            for (int j = column - 1; j < column + 2; j++) {
                // Skip the cell itself and handle out-of-bounds indices
                if ((i >= 0 && i < size) && (j >= 0 && j < size) &&
                    !(i == row && j == column)) {
                    if (vec[i][j] == "⬜")
                        num_neighbours++;
                }
            }
        }
        return num_neighbours;
    }


    void reset() {
        for (auto row: vec)
            fill(row.begin(), row.end(), "⬛");


    }

    void initialize() {
        int x, y, cnt;
        cout << "Enter the number of live cells you want\n";
        cin >> cnt;
        cout << "Enter the (x,y) for the alive cells :)\n";

        while (cnt--) {
            cin >> x >> y;
            vec[x][y] = "⬜";
        }
        cout << "Your game initialized with:\n";
        display();

    }

    void run() {
        int times;
        int speed;
        cout << "Enter how many times to run:\n";
        cin >> times;
        cout << "Enter the speed in milliseconds 700  is recommended:\n";
        cin >> speed;
        while (times--) {
            next_generation();
            display();
            this_thread::sleep_for(chrono::milliseconds(speed));
        }
    }


    void next_generation() {
        vector<vector<string> > next_generation = vec;
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                int num_neighbours = count_neighbours(i, j);
                if (vec[i][j] == "⬛" && num_neighbours == 3) {
                    next_generation[i][j] = "⬜";

                } else if (vec[i][j] == "⬜" && (num_neighbours > 3 || num_neighbours < 2)) {
                    next_generation[i][j] = "⬛";
                }
            }
        }

        vec = next_generation;

    }
};


int main() {
    Universe u1(50);

    u1.initialize();


    u1.run();


    return 0;
}


//25 25
//25 26
//25 27
//26 25
//26 26
//26 27
//27 25
//27 26
//27 27

