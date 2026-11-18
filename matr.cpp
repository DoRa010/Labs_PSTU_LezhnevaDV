#include <iostream>
using namespace std;

int main() {
    // 1. Ввод размеров
    int n, m;
    cout << "Введите количество строк и столбцов: ";
    cin >> n >> m;

    // 2. Выделение памяти под матрицу a (n x m)
    int** a = new int*[n];
    for (int i = 0; i < n; i++) {
        a[i] = new int[m];
    }

    // 3. Ввод элементов
    cout << "Введите элементы матрицы:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    // Выделение памяти под результат b (m x n)
    int** b = new int*[m];
    for (int i = 0; i < m; i++) {
        b[i] = new int[n];
    }

    // 4. Транспонирование (меняем индексы i и j местами)
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            b[j][i] = a[i][j];
        }
    }

    // 5. Вывод результата
    cout << "\nТранспонированная матрица " << m << "x" << n << ":\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << b[i][j] << " ";
        }
        cout << endl;
    }

    // 6. Освобождение памяти обеих матриц
    for (int i = 0; i < n; i++) {
        delete[] a[i];
    }
    delete[] a;

    for (int i = 0; i < m; i++) {
        delete[] b[i];
    }
    delete[] b;

    return 0;
}