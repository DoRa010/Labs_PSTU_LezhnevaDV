// максимальный элемент двумерного массива
#include <iostream>
#include <clocale>
using namespace std;

int main() 
{
    setlocale(LC_ALL, ".65001");

    const int ROWS = 3;
    const int COLS = 4;
    int arr[ROWS][COLS];

    for (int i = 0; i < ROWS; ++i) 
    {
        for (int j = 0; j < COLS; ++j) 
        {
            cin >> arr[i][j];
        }
    }

    int maxVal = arr[0][0];
    int rowIndex = 0;
    int colIndex = 0;

    for (int i = 0; i < ROWS; ++i) 
    {
        for (int j = 0; j < COLS; ++j) 
        {
            if (arr[i][j] > maxVal) 
            {
                maxVal = arr[i][j];
                rowIndex = i;
                colIndex = j;
            }
        }
    }

    cout << "Максимальный элемент: " << maxVal << endl;
    cout << "Индекс строки (с 0): " << rowIndex << endl;
    cout << "Индекс столбца (с 0): " << colIndex << endl;
    cout << "Позиция в виде [строка][столбец]: [" << rowIndex << "][" << colIndex << "]" << endl;

    return 0;
}
