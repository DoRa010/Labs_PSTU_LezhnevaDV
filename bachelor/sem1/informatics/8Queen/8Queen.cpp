// Задача о восьми ферзях: поиск ОДНОГО решения методом поиска с возвратом (backtracking).
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#ifdef _WIN32
#include <windows.h>
#endif
using namespace std;

const int N = 8;                 // размер доски и количество ферзей
const int SHOW_STEPS = 12;       // сколько первых шагов поиска показать на экране

long long placed = 0;            // сколько раз мы ставили ферзя
long long backtracks = 0;        // сколько раз мы убирали ферзя (возвраты)
int step = 0;                    // номер шага (нужен только для вывода хода поиска)


// Можно ли поставить ферзя в следующую строку в столбец col?
// queens[i] - столбец ферзя, который стоит в строке i.
bool isSafe(const vector<int>& queens, int col) {
    int row = queens.size();                        // номер строки, которую заполняем
    for (int r = 0; r < row; r++) {
        int c = queens[r];
        if (c == col) return false;                 // тот же столбец
        if (abs(c - col) == abs(r - row)) return false;  // та же диагональ
    }
    return true;
}


// Рисует доску: Q - ферзь, точка - пустая клетка.
void showBoard(const vector<int>& queens) {
    for (int r = 0; r < N; r++) {
        for (int c = 0; c < N; c++) {
            if (r < (int)queens.size() && queens[r] == c)
                cout << "Q ";
            else
                cout << ". ";
        }
        cout << endl;
    }
    cout << endl;
}


// Печатает шаг поиска и доску (только для первых SHOW_STEPS шагов).
void logStep(const string& text, const vector<int>& queens) {
    step++;
    if (step <= SHOW_STEPS) {
        cout << "Шаг " << step << ": " << text << endl;
        showBoard(queens);
    }
}


// Расставляет ферзей по строкам.
// Возвращает true, как только найдено ПЕРВОЕ решение, и сразу заканчивает поиск.
bool solve(vector<int>& queens) {
    if ((int)queens.size() == N) {
        return true;                                // все ферзи стоят - решение найдено
    }
    for (int col = 0; col < N; col++) {
        if (isSafe(queens, col)) {
            queens.push_back(col);                  // ставим ферзя
            placed++;
            logStep("ставим ферзя в строку " + to_string(queens.size()) +
                    ", столбец " + to_string(col + 1), queens);
            if (solve(queens)) {
                return true;                        // решение найдено - ферзей больше не трогаем
            }
            queens.pop_back();                      // возврат: убираем ферзя и пробуем другой столбец
            backtracks++;
            logStep("откат: убираем ферзя из строки " + to_string(queens.size() + 1), queens);
        }
    }
    return false;                                   // в этой строке ничего не подошло - идём назад
}


// Независимая проверка: сравниваем каждую пару ферзей.
bool isCorrect(const vector<int>& queens) {
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            if (queens[i] == queens[j]) return false;               // один столбец
            if (abs(queens[i] - queens[j]) == j - i) return false;  // одна диагональ
        }
    }
    return true;
}


int main() {
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);        // чтобы русские буквы нормально выводились в консоли Windows
#endif
    vector<int> queens;                 // queens[i] - столбец ферзя в строке i

    cout << "=== Ход поиска (первые " << SHOW_STEPS << " шагов) ===\n" << endl;
    bool found = solve(queens);

    if (!found) {
        cout << "Решение не найдено" << endl;
        return 0;
    }

    cout << "=== Результат ===" << endl;
    cout << "Решение найдено" << endl;
    cout << "Поставлено ферзей за весь поиск: " << placed << endl;
    cout << "Возвратов (убрано ферзей): " << backtracks << endl;
    cout << "Решение верно: " << (isCorrect(queens) ? "да" : "нет") << "\n" << endl;

    cout << "Найденное решение:" << endl;
    showBoard(queens);

    cout << "Ферзи по строкам (строка: столбец):" << endl;
    for (int r = 0; r < N; r++) {
        cout << "  " << r + 1 << ": " << queens[r] + 1 << endl;
    }
    return 0;
}
