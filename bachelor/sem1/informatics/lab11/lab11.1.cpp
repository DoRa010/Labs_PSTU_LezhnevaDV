// Лабораторная работа №11. Однонаправленный список
#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;


struct SingleNode {
    int data;                        // поле с данными
    SingleNode* next;                // указатель на следующий узел

    SingleNode(int value) {          // конструктор: вызывается при создании узла
        data = value;
        next = nullptr;
    }
};


struct SingleList {
    SingleNode* head;                // указатель на головной узел
    SingleNode* tail;                // указатель на хвостовой узел
    int size;                        // размер списка

    
    static bool isBefore(int a, int b, bool ascending) {
        if (ascending) return a < b;     // по возрастанию
        return a > b;                    // по убыванию
    }

    SingleList() {                   // конструктор: создаёт пустой список
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    ~SingleList() {                  // деструктор: сам удаляет все узлы, когда список уничтожается
        clear();
    }

    // Доступ к элементу по индексу: возвращает адрес узла или nullptr
    SingleNode* getAt(int k) {
        if (k < 0 || k >= size) return nullptr;      // такого индекса нет
        SingleNode* temp = head;
        for (int i = 0; i < k; i++) {                // идём от головы на k шагов
            temp = temp->next;
        }
        return temp;
    }

    // Добавление в начало
    void pushFront(int value) {
        SingleNode* newNode = new SingleNode(value);
        newNode->next = head;                        // новый узел указывает на бывшую голову
        head = newNode;                              // новый узел становится головой
        if (tail == nullptr) tail = newNode;         // список был пуст
        size++;
    }

    // Добавление в конец
    void pushBack(int value) {
        SingleNode* newNode = new SingleNode(value);
        if (head == nullptr) {
            head = newNode;                          // список был пуст
        } else {
            tail->next = newNode;                    // старый хвост указывает на новый узел
        }
        tail = newNode;                              // хвост всегда меняем на новый элемент
        size++;
    }

    // Добавление ПОСЛЕ элемента с индексом k
    void insertAfter(int k, int value) {
        SingleNode* left = getAt(k);                 // узел, после которого вставляем
        if (left == nullptr) return;                 // индекс введён неверно - выход
        SingleNode* temp = new SingleNode(value);
        temp->next = left->next;                     // новые связи
        left->next = temp;
        if (left == tail) tail = temp;               // вставили после хвоста
        size++;
    }

    // Добавление по индексу: новый элемент получит индекс k
    void insertAt(int k, int value) {
        if (k < 0 || k > size) return;
        if (k == 0) {
            pushFront(value);
        } else {
            insertAfter(k - 1, value);               // вставляем после предыдущего узла
        }
    }

    // Добавление ПЕРЕД элементом с индексом k
    void insertBefore(int k, int value) {
        if (k < 0 || k >= size) return;              // элемента с индексом k нет
        insertAt(k, value);                          // новый узел встанет на место k, старый сдвинется вправо
    }

    // Удаление первого элемента
    void popFront() {
        if (head == nullptr) return;                 // список пуст
        SingleNode* temp = head;                     // запоминаем голову
        head = head->next;
        if (head == nullptr) tail = nullptr;         // в списке был один элемент
        delete temp;
        size--;
    }

    // Удаление последнего элемента
    void popBack() {
        if (head == nullptr) return;
        if (head == tail) {                          // всего один элемент
            popFront();
            return;
        }
        SingleNode* current = head;
        while (current->next != tail) {              // ищем предпоследний узел
            current = current->next;
        }
        delete tail;
        tail = current;
        tail->next = nullptr;
        size--;
    }

    // Удаление элемента по индексу
    void erase(int k) {
        if (k < 0 || k >= size) return;
        if (k == 0) {                                // удаляем голову
            popFront();
            return;
        }
        SingleNode* prev = getAt(k - 1);             // узел, который стоит перед удаляемым
        SingleNode* toDelete = prev->next;           // узел, который удаляем
        prev->next = toDelete->next;                 // перекидываем связь через него
        if (toDelete == tail) tail = prev;
        delete toDelete;
        size--;
    }

    // Добавление нескольких элементов подряд, начиная с индекса start
    void insertK(int start, const vector<int>& values) {
        for (int i = 0; i < (int)values.size(); i++) {
            insertAt(start + i, values[i]);
        }
    }

    // Удаление k элементов подряд, начиная с индекса start
    void eraseK(int start, int k) {
        for (int i = 0; i < k; i++) {
            erase(start);                            // следующий элемент встаёт на место start
        }
    }

    // Сортировка вставками (по возрастанию или по убыванию)
    void insertionSort(bool ascending) {
        SingleNode* sorted = nullptr;                // начало нового, отсортированного списка
        SingleNode* current = head;                  // узел, который сейчас переносим
        while (current != nullptr) {
            SingleNode* nextNode = current->next;    // запоминаем следующий узел заранее
            if (sorted == nullptr || isBefore(current->data, sorted->data, ascending)) {
                current->next = sorted;              // узел встаёт в начало отсортированной части
                sorted = current;
            } else {
                SingleNode* p = sorted;              // ищем, после какого узла его поставить
                while (p->next != nullptr && !isBefore(current->data, p->next->data, ascending)) {
                    p = p->next;
                }
                current->next = p->next;
                p->next = current;
            }
            current = nextNode;
        }
        head = sorted;
        tail = head;                                 // заново находим хвост
        while (tail != nullptr && tail->next != nullptr) {
            tail = tail->next;
        }
    }

    // Удаление всего списка
    void clear() {
        while (head != nullptr) {
            popFront();
        }
    }

    // Вывод списка на экран
    void print(const string& title) {
        cout << title << ":" << endl << "   ";
        for (SingleNode* p = head; p != nullptr; p = p->next) {
            cout << p->data << " -> ";
        }
        cout << "nullptr (размер " << size << ")" << endl;
    }
};