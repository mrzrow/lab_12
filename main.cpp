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
    vector<int> vec = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    FilterIterator<vector<int>::iterator, IsEven> iter(vec.begin(), vec.end());
    for (; iter != vec.end(); iter++)
        std::cout << *iter << std::endl;
    return 0;
}
