#include "heap.h"
#include <iostream>

using namespace std;
bool camp(int &a, int &b)
{
    return a >= b ? true : false;
}
int main()
{
    Heap<int> h;
    h.registerFunc(camp);
    int array[] = { 2, 18, 21, 1, 43, 2, 4, 6, 76, 127, -17, 195, -10, 54, 78, 96, -1000 };
    h.build(array, 17);
    for (auto i = 0; i < 17; i++)
        cout << array[i] << endl;

    cout << "      " << endl;
    cout << h.del() << endl;
    for (auto i = 0; i < 16; i++)
        cout << h.heap()[i] << endl;
    h.insert(1000);
    for (auto i = 0; i < 17; i++)
        cout << h.heap()[i] << " ";
    system("pause");
    return 0;
}
