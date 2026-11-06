#include <iostream>
#include <iomanip>
#include <cmath>
#include <clocale>
using namespace std;

int main()
{
    setlocale(LC_ALL, "");

    const double PI  = 3.14159265358979;
    const double a   = PI / 5;      // начало диапазона
    const double b   = PI;          // конец диапазона
    const int    k   = 10;          // число шагов
    const int    n   = 20;          // число членов ряда (случай а)
    const double eps = 0.0001;      // точность (случай б)

    double h = (b - a) / k;         // шаг изменения аргумента

    cout << fixed << setprecision(5);
    cout << "   x        S(n=20)     S(eps)        y" << endl;

    for (int i = 0; i <= k; i++)
    {
        double x = a + i * h;

        // а) сумма первых n членов ряда
        double s1 = 0, sign = -1;           // (-1)^1 =-1
        for (int m = 1; m <= n; m++)
        {
            s1 += sign * cos(m * x) / (m * m);
            sign = -sign;
        }

        // б) суммирование до достижения точности
        double s2 = 0, term;
        sign = -1;
        int m = 0;
        do
        {
            m++;
            term = sign * cos(m * x) / (m * m);   // очередной член ряда
            s2 += term;
            sign = -sign;
        } while (fabs(term) >= eps);              // точность: |an| < eps

        // точное значение функции
        double y = (x * x - PI * PI / 3) / 4;

        cout << setw(10) << x
             << setw(12) << s1
             << setw(12) << s2
             << setw(12) << y << endl;
    }

    return 0;
}

