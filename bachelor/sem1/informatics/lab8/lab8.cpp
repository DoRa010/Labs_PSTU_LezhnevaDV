#include <iostream>
#include <stdio.h>
#include <string.h>
#include <locale.h>
using namespace std;

const int L = 30;

struct STADION
{
    char name[L];    // название
    char adres[L];   // адрес
    int  vmest;      // вместимость
    char sport[L];   // виды спорта
};

// формирование двоичного файла
void formFile()
{
    FILE *f = fopen("stadion.dat", "wb");
    if (f == NULL)
    {
        cout << "Ошибка при открытии файла" << endl;
        return;
    }
    int n;
    cout << "Количество стадионов: ";
    cin >> n;
    STADION s;
    for (int i = 0; i < n; i++)
    {
        cout << "Стадион " << i + 1 << " (название адрес вместимость спорт): ";
        cin >> s.name >> s.adres >> s.vmest >> s.sport;
        fwrite(&s, sizeof(STADION), 1, f);
        if (ferror(f))
        {
            cout << "Ошибка при записи в файл" << endl;
            fclose(f);
            return;
        }
    }
    fclose(f);
}

// печать содержимого файла
void printFile()
{
    FILE *f = fopen("stadion.dat", "rb");
    if (f == NULL)
    {
        cout << "Ошибка при открытии файла" << endl;
        return;
    }
    STADION s;
    int i = 1;
    while (fread(&s, sizeof(STADION), 1, f) == 1)
    {
        cout << i << ") " << s.name << " " << s.adres << " "
             << s.vmest << " " << s.sport << endl;
        i++;
    }
    fclose(f);
}

// поиск структуры для удаления по названию
int findByName(char name[])
{
    FILE *f = fopen("stadion.dat", "rb");
    if (f == NULL) return -1;
    STADION s;
    int i = 0;
    while (fread(&s, sizeof(STADION), 1, f) == 1)
    {
        if (strcmp(s.name, name) == 0)
        {
            fclose(f);
            return i;    // номер найденного элемента
        }
        i++;
    }
    fclose(f);
    return -1;           // не найден
}

// удаление элемента с заданным названием (через вспомогательный файл)
void delByName(char name[])
{
    FILE *f = fopen("stadion.dat", "rb");
    FILE *g = fopen("temp.dat", "wb");
    if (f == NULL || g == NULL)
    {
        cout << "Ошибка при открытии файлов" << endl;
        if (f) fclose(f);
        if (g) fclose(g);
        return;
    }
    STADION s;
    bool deleted = false;
    while (fread(&s, sizeof(STADION), 1, f) == 1)
    {
        if (strcmp(s.name, name) == 0)   // удаляемый элемент не переписывается
        {
            deleted = true;
            continue;
        }
        fwrite(&s, sizeof(STADION), 1, g);
    }
    fclose(f);
    fclose(g);
    remove("stadion.dat");
    rename("temp.dat", "stadion.dat");
    if (deleted)
        cout << "Элемент удалён" << endl;
    else
        cout << "Элемент с таким названием не найден" << endl;
}

// добавление 2 элементов после элемента с указанным номером
void addAfter(int num)
{
    FILE *f = fopen("stadion.dat", "rb");
    FILE *g = fopen("temp.dat", "wb");
    if (f == NULL || g == NULL)
    {
        cout << "Ошибка при открытии файлов" << endl;
        if (f) fclose(f);
        if (g) fclose(g);
        return;
    }
    STADION s;
    int i = 0;
    bool added = false;
    while (fread(&s, sizeof(STADION), 1, f) == 1)
    {
        fwrite(&s, sizeof(STADION), 1, g);
        i++;
        if (i == num)                    // после этого элемента вставляем 2
        {
            STADION a;
            for (int k = 1; k <= 2; k++)
            {
                cout << "Новый стадион " << k << " (название адрес вместимость спорт): ";
                cin >> a.name >> a.adres >> a.vmest >> a.sport;
                fwrite(&a, sizeof(STADION), 1, g);
            }
            added = true;
        }
    }
    fclose(f);
    fclose(g);
    remove("stadion.dat");
    rename("temp.dat", "stadion.dat");
    if (!added)
        cout << "Элемент с таким номером не найден" << endl;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    char name[L];
    int num;

    formFile();
    cout << "Содержимое файла:" << endl;
    printFile();

    cout << "Название для удаления: ";
    cin >> name;
    delByName(name);
    cout << "Содержимое файла после удаления:" << endl;
    printFile();

    cout << "Номер элемента, после которого добавить 2 новых: ";
    cin >> num;
    addAfter(num);
    cout << "Содержимое файла после добавления:" << endl;
    printFile();

    return 0;
}
