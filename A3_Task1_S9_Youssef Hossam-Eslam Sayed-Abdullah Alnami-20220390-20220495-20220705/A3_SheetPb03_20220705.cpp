#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <cctype>
#include <iomanip>

using namespace std;

class Word_FrequencyTable {
    map<string, int> word_frequency;

    static string cleanWord(const string &word) {
        string cleaned_word;
        for (const char &c: word) {
            if (isalnum(c) || c == '-') {
                cleaned_word += tolower(c);
            }
        }
        return (cleaned_word.size() > 1) ? cleaned_word : "";//ignoring the chars
    }

public:
    explicit Word_FrequencyTable(const string &fileName) {
        ifstream file(fileName);
        if (!file.is_open()) {
            cout << "Can't open the file. Check if the file exists or if you have access.\n";
        } else {
            string line;
            while (getline(file, line)) {
                istringstream input_String(line);
                string word;
                while (input_String >> word) {
                    word = cleanWord(word);
                    if (!word.empty()) {
                        word_frequency[word]++;
                    }
                }
            }
        }
    }


    void print_Table() const {
        cout << "Word Frequency Table:\n";
        cout << "---------------------------------\n";
        cout << left << setw(20) << "Word" << "Frequency" << endl;
        cout << "---------------------------------\n";
        for (const auto &word: word_frequency) {
            cout << left << setw(20) << word.first << word.second << endl;
        }
        cout << "---------------------------------\n";
    }

    int get_frequency(const string &word) const {
        return word_frequency.count(word);
    }


};

int main() {
    Word_FrequencyTable table_File1("text.txt");

    cout << table_File1.get_frequency("count") << endl;
    table_File1.print_Table();

    return 0;
}



