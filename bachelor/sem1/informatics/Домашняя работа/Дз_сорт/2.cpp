// Метод выбора

#include <iostream>
#include <clocale>

using namespace std;

int main()
{
    setlocale(LC_ALL, ".65001");

    int n;
    int a[101];

    cout << "Введите размер массива: ";
    cin >> n;

    cout << "Введите " << n << " чисел: ";
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }

    for (int i = 1; i < n; i++){
        int min = i; // Предполагаем, мин.элемент - это текущий
        
        for (int j = i + 1; j <= n; j++){
            if (a[j] < a[min]){
                min = j; // Если нашли элемент меньше - запоминаем
            }
        }

        int k = a[i];
        a[i] = a[min];
        a[min] = k;
    }

    cout << "Отсортированный массив: ";
    for (int i = 1; i <= n; i++){
        cout << a[i] << " ";
    }

    cout << endl;

    return 0;
}