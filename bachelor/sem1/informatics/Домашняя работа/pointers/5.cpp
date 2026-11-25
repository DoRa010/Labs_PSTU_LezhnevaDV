#include <iostream>
using namespace std;

int main()
{
    int a = 2, b = 5, c = 8;
    int* p = &a;
    int& r = a;
    int copy = *p;
    *p = b;
    p = &c;
    r = *p;
    *p = b + copy;
    p = &b;
    *p = r - copy;
    r++;
    cout << a << " " << b << " " << c << " " << copy;
    return 0;
}

// Вывод: 9 6 7 2
/* "p" указывает в конце на переменную "b".
"r" - ссылка на переменную "a". */