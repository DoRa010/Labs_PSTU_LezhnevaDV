#include <iostream>
#include <cstdlib>     // rand, srand
#include <ctime>   
using namespace std;

int main()
{
    int n, m, i, j;
    int **a, **b;
    int imin, jmin, bi, bj;

    srand(time(NULL));

    cout << "Razmer matricy (n m): ";
    cin >> n >> m;

    // формируем динамический массив, заполняем случайными числами
    a = new int*[n];
    for (i = 0; i < n; i++)
    {
        a[i] = new int[m];
        for (j = 0; j < m; j++)
            a[i][j] = rand() % 100;
    }

    // печатаем исходную матрицу
    cout << "\nIshodnaya matrica:\n";
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
            cout << a[i][j] << "\t";
        cout << endl;
    }

    // ищем минимальный элемент
    imin = 0;
    jmin = 0;
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            if (a[i][j] < a[imin][jmin])
            {
                imin = i;
                jmin = j;
            }
    cout << "\nMin element = " << a[imin][jmin]
         << ", str " << imin + 1
         << ", stolb " << jmin + 1 << endl;

    // формируем новую матрицу без строки и столбца с минимумом
    b = new int*[n - 1];
    bi = 0;
    for (i = 0; i < n; i++)
    {
        if (i == imin) continue;        // строку пропускаем
        b[bi] = new int[m - 1];
        bj = 0;
        for (j = 0; j < m; j++)
        {
            if (j == jmin) continue;    // столбец пропускаем
            b[bi][bj] = a[i][j];
            bj++;
        }
        bi++;
    }

    // печатаем результат
    cout << "\nMatrica posle:\n";
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < m - 1; j++)
            cout << b[i][j] << "\t";
        cout << endl;
    }

    // удаляем динамические массивы
    for (i = 0; i < n; i++)
        delete[] a[i];
    delete[] a;
    for (i = 0; i < n - 1; i++)
        delete[] b[i];
    delete[] b;

    return 0;
}

