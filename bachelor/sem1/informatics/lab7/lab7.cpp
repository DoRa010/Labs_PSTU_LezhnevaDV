#include <iostream>
#include <locale.h>
#include <cmath>
using namespace std;

// а) натуральный логарифм целого числа
double lg(int n)
{
    return log((double)n);
}

// б) десятичный логарифм действительного числа
double lg(double x)
{
    return log10(x);
}

int main()
{
    setlocale(LC_ALL, "Russian");
    int n;
    double x;
    cout << "Введите целое число: "<< endl;
    cin >> n;
    cout << "Введите действительное число: " << endl;
    cin >> x;
    cout << "Натуральный логарифм ln(" << n << ") = " << lg(n) << endl;
    cout << "Десятичный логарифм lg(" << x << ") = " << lg(x) << endl;
    return 0;
}





#include <iostream>
#include <locale.h>
using namespace std;

// k - количество параметров в переменном списке,
// далее - двоичные числа, которые переводим в троичную систему
void binToTern(int k, ...)
{
    int *p = &k;              // указатель на начало списка параметров

    for (; k != 0; k--)
    {
        int bin = *(++p);     // очередное число из переменного списка
        int b = bin, raz = 1, dec = 0;

        while (b > 0)         // дв -> десят
        {
            dec += (b % 10) * raz; // остатки от деления на 10 - цифры десятых
            raz *= 2;
            b /= 10;
        }

        long long r = 1, tr = 0;

        while (dec > 0)       // десятичное число -> троичная запись
        {
            tr += (dec % 3) * r;     // остатки от деления на 3 - цифры троичной записи
            r *= 10;
            dec /= 3;
        }

        cout << bin << " (2) -> " << tr << " (3)" << endl;
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");

    binToTern(3, 101, 1101, 11111);
    binToTern(6, 1, 10, 11, 100, 101, 110);
    binToTern(7, 111, 1000, 1001, 1010, 1011, 1100, 1101);

    return 0;
}