#include <iostream>
#include <clocale>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");   

    const double eps = 1e-4;
    double sum = 0;      // сумма ряда
    double a;              // текущий член ряда
    int n = 0;

    do
    {
        n++;

        // n!
        double f = 1;
        for (int i = 2; i <= n; i++) f *= i;

        // n в степени n
        double p = 1;
        for (int i = 0; i < n; i++) p *= n;

        a = f / (3 * p);   // член ряда n!/(3*n^n)
        sum += a;

        cout << "a(" << n << ") = " << a << endl;
    }
    while (a >= eps);      // точность достигнута, когда a < eps

    cout << "\nСумма ряда S = " << sum << endl;

    return 0;
}
