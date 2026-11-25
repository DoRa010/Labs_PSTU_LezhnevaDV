#include <iostream>
using namespace std;

int main()
{
    int a = 12;
    int* ptr = &a;
    int copy = *ptr;

    (*ptr)++;
    cout << a << " " << copy;

    return 0;
}

// Вывод: 13 12
/* copy - это новая, независимая переменная.
В нее просто скопировали значение (12)
