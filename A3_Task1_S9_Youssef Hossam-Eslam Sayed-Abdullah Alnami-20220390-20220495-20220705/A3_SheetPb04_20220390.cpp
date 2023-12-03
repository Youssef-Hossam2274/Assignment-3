#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

template <class T>
class Set
{
private:
    vector<T> vec;

public:
    void addItme(T item)
    {
        if (!exist(item))
        {
            vec.push_back(item);
            sort(vec.begin(), vec.end());
        }
    }

    void removeItem(T item)
    {
        auto it = find(vec.begin(), vec.end(), item);
        vec.erase(it);
    }

    int Size()
    {
        return vec.size();
    }

    bool exist(T item)
    {
        for (T it: vec)
            if (it == item)
                return true;
        return false;
    }

    T* copyItme()
    {
        T* arr;
        arr = new T[vec.size()];

        for (int i {0}; i < vec.size(); ++i)
            arr[i] = vec[i];
        
        return arr;
    }

    void print()
    {
        for (T item: vec)
            cout << item << ' ';
        cout << '\n';
    }
};

int main()
{
    Set<int> s;
    
    s.addItme(3);
    s.addItme(2);
    s.addItme(8);
    s.addItme(1);
    s.addItme(9);

    int *arr = s.copyItme();
    cout << arr[3];
    return 0;
}