#include <iostream>
#include <vector>
#include "filter_iterator.h"

using namespace std;

class IsEven {
public:
    bool operator()(int a) { return a % 2 == 0; }
};

class IsEqualThree {
public:
    bool operator()(char a) { return a == '3'; }
};

class IsGreaterThanThree {
public:
    bool operator()(float a) { return a > 3; }
};

int main() {
    { // integer | Обход с шагом 3
    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    FilterIterator<vector<int>::iterator, IsEven> i(v.begin(), v.end());
    cout << "int   | IsEven()             ->  ";
    for (; i < v.end(); i+=3)
        cout << *i << "\t";
    cout << endl;
    }

    { // char | Обход с конца
    vector<char> v = {'1', '2', '3', '4', '3', '2'};
    FilterIterator<vector<char>::iterator, IsEqualThree> i(v.end() - 1, v.begin());
    cout << "char  | IsEqualThree()       ->  ";
    for (; i >= v.begin(); --i)
        cout << *i << "\t";
    cout << endl;
    }

    { // float | Обход с начала
    vector<float> v = {1.0f, 2.3f, 4.5f, 7.1f};
    FilterIterator<vector<float>::iterator, IsGreaterThanThree> i(v.begin(), v.end());
    cout << "float | IsGreaterThanThree() ->  ";
    for (; i < v.end(); ++i)
        cout << *i << '\t';
    cout << endl;
    }

    return 0;
}