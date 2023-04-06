#include <iostream>
#include <vector>
#include "filter_iterator.h"

using namespace std;

class IsEven {
public:
    bool operator()(int a) {
        return a % 2 == 0;
    }
};

int main() {
    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    FilterIterator<vector<int>::iterator, IsEven> i(v.begin(), v.end());
    for (; i < v.end(); i+=3)
        cout << *i << endl;
    return 0;
}