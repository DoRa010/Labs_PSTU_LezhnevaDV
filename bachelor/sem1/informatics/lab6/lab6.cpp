#include <iostream>
#include <locale.h>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");  

    char s[256];   // текст не более 255 символов + '\0'
    int i, k, a, b;
    char t;

    cout << "Введите строку (в конце точка): ";
    cin.getline(s, 256);   // читает строку целиком, с пробелами

    for (i = 0; s[i] != '\0' && s[i] != '.'; )
    {
        // пропускаем пробелы между словами
        while (s[i] == ' ')
            i++;

        // находим конец слова
        k = i;
        while (s[k] != ' ' && s[k] != '\0' && s[k] != '.')
            k++;

        // сортируем цифры слова по убыванию ("пузырёк")
        for (a = i; a < k - 1; a++)
            for (b = i; b < k - 1 - (a - i); b++)
                if (s[b] >= '0' && s[b] <= '9' &&
                    s[b+1] >= '0' && s[b+1] <= '9' && s[b] < s[b+1])
                {
                    t = s[b];
                    s[b] = s[b+1];
                    s[b+1] = t;
                }

        i = k;   // переходим к следующему слову
    }

    cout << "\nРезультат: " << s << endl;

    return 0;
}
