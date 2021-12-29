#include "include/std.h"

void ArrayTest()
{
    array<int, 10> arr{1, 2, 3, 4, 5, 6};
    cout << arr.at(2) << endl;
    cout << arr.at(3) << endl;
    cout << arr.front() << endl;
    cout << arr.back() << endl;
    cout << *(arr.data() + sizeof(int)) << endl;
    cout << arr.size() << endl;
    cout << arr.max_size() << endl;
}