#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

class LabelGenerator
{
protected:
    string label;
    int number, start;
public:
    LabelGenerator(string label, int start): label(label), number(start), start(start){} 

    string nextLabel()
    {
        string new_label = label + to_string(number++);
        return new_label;
    }
};

class FileLabelGenerator: public LabelGenerator
{
private:
    string file_name;
    vector<string> captions;
    
public:
    FileLabelGenerator(string label, int start, string file_name): LabelGenerator(label, start), file_name(file_name)
    {
        fstream file_handle(file_name.c_str());
        if (file_handle.fail())
            cout << "there are an error in FileLabelGenerator constructor\n";
        
        string caption;
        while(getline(file_handle, caption))
            captions.push_back(caption);
    }

    string nextLabel()
    {
        string new_label = label + to_string(number) + ' ' + captions[number-start];
        number++;
        return new_label;
    }

};

int main()
{

    LabelGenerator figureNumbers("Figure ", 1); 
    LabelGenerator pointNumbers("P", 0); 
    
    cout << "Figure numbers: "; 
    for (int i = 0; i < 3; i++)
        cout << figureNumbers.nextLabel() << ", ";
    
    cout << endl << "Point numbers: "; 
    for (int i = 0; i < 5; i++)
        cout << pointNumbers.nextLabel() << ", "; 
    
    cout << endl << "More figures: "; 
    for (int i = 0; i < 3; i++) 
        cout << figureNumbers.nextLabel() << ", "; 
    
    cout << endl;

    FileLabelGenerator figureLabels ("Figure ", 1, "labels.txt"); 
    
    cout << "Figure labels: \n"; 
    for (int i = 0; i < 3; i++)
        cout << figureLabels.nextLabel() << endl;

    return 0;
}