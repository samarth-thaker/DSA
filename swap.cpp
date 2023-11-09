#include <iostream>
using namespace std;
int main()
{
    int x = 5, y = 3;
    // start with the one with lower value:
    y = x + y;
    x = y - x;
    y = y - x;
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;
}