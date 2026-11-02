// Метод обмена

#include <iostream>
#include <clocale>

using namespace std;

int main()
{
    setlocale(LC_ALL, ".65001");

    int n;
    int a[100];

    cout << "Введите размер массива: ";
    cin >> n;

    cout << "Введите " << n << " чисел: ";
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    for (int i = 0; i < n; i++){
        for (int j = n - 1; j > i; j--){ 
            if (a[j - 1] > a[j]){
                int k = a[j - 1];
                a[j - 1] = a[j];
                a[j] = k;
            }
        }
    }

    cout << "Отсортированный массив: ";
    for (int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}