#include <iostream>
#include <clocale>
#include <iomanip> 
#include <string>  

using namespace std;

int main()
{
    setlocale(LC_ALL, ".65001");
    
    int summa;
    int a[2][3];
    int s_a[2];

    for(int i = 0; i < 2; i++)
    {
        summa = 0;
        for(int j = 0; j < 3; j++)
        {
            cin >> a[i][j];
            summa += a[i][j];
        }
        s_a[i] = summa;
    }

    int r = 0;
    for(int i = 0; i < 2; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            int cur_len = to_string(a[i][j]).length();
            if (cur_len > r)
            {
                r = cur_len;
            }
        }
    }

    cout << "Массив" << endl;
    for(int i = 0; i < 2; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            cout << setw(r + 2) << a[i][j] << "  ";  //выравнивание
        }
        cout << endl;
    }
    cout << "Сумма в первой строке: " << s_a[0] << endl;
    cout << "Сумма во второй строке: " << s_a[1] << endl;

    return 0;
}