#include <iostream>
#include <locale.h>
using namespace std;

int pegs[3][20];   // pegs[p][i] - размер диска на стержне p на высоте i
int cnt[3];        // сколько дисков на каждом стержне
int N;             // количество дисков

// Печать всех трёх стержней
void print_pegs()
{
    int i, j, p, d;

    for (i = N; i >= 1; i--)            // идём сверху вниз по высоте
    {
        for (p = 0; p < 3; p++)
        {
            if (cnt[p] >= i)            // на этой высоте лежит диск
            {
                d = pegs[p][i - 1];
                for (j = 0; j < N - d; j++) cout << " ";
                for (j = 0; j < 2 * d - 1; j++) cout << "#";
                for (j = 0; j < N - d; j++) cout << " ";
            }
            else                        // пусто - только стержень
            {
                for (j = 0; j < N - 1; j++) cout << " ";
                cout << "|";
                for (j = 0; j < N - 1; j++) cout << " ";
            }
            cout << "   ";
        }
        cout << endl;
    }

    for (p = 0; p < 3; p++)             // основание
    {
        for (j = 0; j < 2 * N - 1; j++) cout << "=";
        cout << "   ";
    }
    cout << endl;

    for (p = 0; p < 3; p++)             // номера стержней
    {
        for (j = 0; j < N - 1; j++) cout << " ";
        cout << p + 1;
        for (j = 0; j < N - 1; j++) cout << " ";
        cout << "   ";
    }
    cout << endl << endl;
}

// Перенос верхнего диска со стержня a на стержень b
void move_disk(int a, int b)
{
    int d = pegs[a][cnt[a] - 1];        // снимаем верхний диск
    cnt[a]--;
    pegs[b][cnt[b]] = d;                // кладём на другой стержень
    cnt[b]++;

    cout << "Диск " << d << ": " << a + 1 << " -> " << b + 1 << endl;
    print_pegs();
}

void han(int n, int a, int b, int c)
{
    if (n > 0)
    {
        han(n - 1, a, c, b);
        move_disk(a - 1, c - 1);
        han(n - 1, c, b, a);
    }
}

int main()
{
    setlocale(LC_ALL, "65001");
    int i;

    cout << "Количество дисков: ";
    cin >> N;

    // начальное состояние: все диски на 1-м стержне
    for (i = 0; i < N; i++)
        pegs[0][i] = N - i;             // снизу самый большой
    cnt[0] = N;
    cnt[1] = 0;
    cnt[2] = 0;

    cout << "\nНач.состояние:\n";
    print_pegs();

    han(N, 1, 2, 3);
    return 0;
}
