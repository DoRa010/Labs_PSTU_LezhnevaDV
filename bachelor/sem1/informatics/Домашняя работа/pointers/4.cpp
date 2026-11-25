#include <iostream>
using namespace std;

int main()
{
    int a = 5, b = 8;
    int& r = a;
    int& s = a;
    int copy = a;
    r = b;
    s += 2;
    b = copy;
    cout << a << " " << b << " " << r << " " << s << " " << copy;
    return 0;
}

// Вывод: 10 5 10 10 5
// copy не меняется, так как это независимая переменная.