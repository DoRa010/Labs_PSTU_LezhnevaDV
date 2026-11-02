// max и min массива
#include <iostream>
#include <clocale>
using namespace std;

int main() 
{
    setlocale(LC_ALL, ".65001");

    const int N = 10;
    int arr[N];

    for (int i = 0; i < N; ++i) 
    {
        cin >> arr[i];
    }

    // Инициализируем максимум и минимум первым элементом
    int maxVal = arr[0];
    int minVal = arr[0];
    int maxIndex = 0;
    int minIndex = 0;
    int countMax = 1;
    int countMin = 1;

    // Проходим по остальным элементам (начиная со второго)
    for (int i = 1; i < N; ++i) 
    {
        // Обработка максимума
        if (arr[i] > maxVal) 
        {
            maxVal = arr[i];
            countMax = 1;          // новый максимум, счётчик сбрасываем
            maxIndex = i;         // запоминаем индекс первого такого максимума
        }
        else if (arr[i] == maxVal) 
        {
            countMax = countMax + 1;
        }

        // Обработка минимума
        if (arr[i] < minVal) 
        {
            minVal = arr[i];
            countMin = 1;         // новый минимум, счётчик сбрасываем
            minIndex = i;         // запоминаем индекс первого такого минимума
        }
        else if (arr[i] == minVal) 
        {
            countMin = countMin + 1;
        }
    }

    cout << "Максимальный элемент: " << maxVal << endl;
    cout << "Индекс первого максимального элемента (с 0): " << maxIndex << endl;
    cout << "Номер первого максимального элемента (с 1): " << (maxIndex + 1) << endl;
    cout << "Количество максимальных элементов: " << countMax << endl;

    cout << "Минимальный элемент: " << minVal << endl;
    cout << "Индекс первого минимального элемента (с 0): " << minIndex << endl;
    cout << "Номер первого минимального элемента (с 1): " << (minIndex + 1) << endl;
    cout << "Количество минимальных элементов: " << countMin << endl;

    return 0;
}
