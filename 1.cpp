// Метод вставки

#include <iostream>
#include <clocale>

using namespace std;

int main()
{
    setlocale(LC_ALL, ".65001");

    int a[100];
    int n;

    cout << "Введите размер массива: ";
    cin >> n;

    cout << "Введите " << n << " чисел: ";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i < n; i++) {
        int y = a[i]; // запоминаем текущий элемент в "y"
        bool f = false; // место для "y" еще не найдено
        int j = i - 1; // начинаем с последнего элемента перед "i"

        while ((j >= 0) && !f) {
            if (a[j] > y){
                a[j + 1] = a[j]; // сдвиг в вправо
                j--; // переходим к сравнению со следующим элементом слева
            }
            else{
            f = true; // иначе место найдено
            }
        }
        a[j + 1] = y; // вставляем "y" на освободившееся место
    }
        
        cout << "Отсорт массив: ";
        for (int i = 0; i < n; i++){
            cout << a[i] << " ";
        }

        cout << endl;

        return 0;
}