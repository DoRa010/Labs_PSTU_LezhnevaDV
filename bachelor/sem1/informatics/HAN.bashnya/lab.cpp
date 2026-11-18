#include <iostream>
#include <locale.h>
using namespace std;

void han(int n, int a, int b, int c);
int main()
{
    setlocale(LC_ALL, "65001");
    int n;
    cin >> n;
    han(n, 1, 2, 3);
    return 0;
}

void han(int n, int a, int b, int c)
{
    if (n > 0)
    {
        han(n - 1, a, c, b);
        cout << a << "->" << c << endl;
        han(n - 1, c, b, a);
    }
}