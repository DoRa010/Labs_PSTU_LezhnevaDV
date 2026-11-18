#include <iostream>
using namespace std;

const int MAX = 10;

// проверка: первый элемент столбца j больше всех элементов обеих диагоналей
bool check(char a[][MAX], int n, int j) {
    for (int i = 0; i < n; i++) {
        if (a[0][j] <= a[i][i]) return false;          // главная диагональ
        if (a[0][j] <= a[i][n - 1 - i]) return false;  // побочная диагональ
    }
    return true;
}

// произведение элементов столбца j
long long prodColumn(char a[][MAX], int n, int j) {
    long long p = 1;
    for (int i = 0; i < n; i++)
        p *= a[i][j];
    return p;
}

int main() {
    char a[MAX][MAX];
    int n, t;

    cout << "Введите размер матрицы n: ";
    cin >> n;
    cout << "Введите элементы матрицы (числа от -128 до 127):" << endl;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            cin >> t;        // читаем число в int, иначе cin прочитает код символа
            a[i][j] = t;     // и записываем в char
        }

    long long result = 1;
    bool found = false;

    for (int j = 0; j < n; j++) {
        if (check(a, n, j)) {
            long long p = prodColumn(a, n, j);
            cout << "Столбец " << j + 1 << ": произведение = " << p << endl;
            result *= p;
            found = true;
        }
    }

    if (found)
        cout << "Общее произведение: " << result << endl;
    else
        cout << "Подходящих столбцов нет" << endl;

    return 0;
}
