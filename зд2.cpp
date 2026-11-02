// упорядочен ли массив по возрастанию
#include <iostream>
#include <clocale>
using namespace std;

int main() 
{
    setlocale(LC_ALL, ".65001");

    const int N = 7;
    int arr[N];

    for (int i = 0; i < N; ++i) 
    {
        cin >> arr[i];
    }

    bool f = false;           // флажок: false — пока упорядочен, true — найдено нарушение
    int i = 0;                // индекс для прохода по парам

    // Цикл идёт, пока есть следующая пара (i < N-1) И пока не найдено нарушение (f == false)
    while ((i < N - 1) && (!f)) 
    {
        if (arr[i] >= arr[i + 1]) 
        {
            f = true;         // нарушение порядка найдено
        }
        else 
        {
            // порядок для этой пары соблюдён, переходим к следующей
            i = i + 1;
        }
    }

    if (!f) 
    {
        cout << "Массив упорядочен по возрастанию." << endl;
    } 
    else 
    {
        cout << "Массив НЕ упорядочен по возрастанию." << endl;
    }

    return 0;
}
