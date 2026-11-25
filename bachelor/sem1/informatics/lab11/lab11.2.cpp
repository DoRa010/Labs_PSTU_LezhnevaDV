// Лабораторная работа №11. Двунаправленный список
#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;


struct DoubleNode {
    int data;                        // поле с данными
    DoubleNode* next;                // указатель на следующий узел
    DoubleNode* prev;                // указатель на предыдущий узел

    DoubleNode(int value) {
        data = value;
        next = nullptr;
        prev = nullptr;
    }
};


struct DoubleList {
    DoubleNode* head;                // указатель на головной узел
    DoubleNode* tail;                // указатель на хвостовой узел
    int size;                        // размер списка

    // Нужно ли поставить число a раньше числа b (нужно для сортировки)
    static bool isBefore(int a, int b, bool ascending) {
        if (ascending) return a < b;     // по возрастанию
        return a > b;                    // по убыванию
    }

    DoubleList() {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    ~DoubleList() {
        clear();
    }

    // Доступ к элементу по индексу. Oт головы или от хвоста
    DoubleNode* getAt(int k) {
        if (k < 0 || k >= size) return nullptr;
        DoubleNode* temp;
        if (k <= size / 2) {                         // элемент ближе к голове
            temp = head;
            for (int i = 0; i < k; i++) temp = temp->next;
        } else {                                     // элемент ближе к хвосту
            temp = tail;
            for (int i = size - 1; i > k; i--) temp = temp->prev;
        }
        return temp;
    }

    // Добавление в начало
    void pushFront(int value) {
        DoubleNode* newNode = new DoubleNode(value);
        newNode->next = head;
        if (head != nullptr) {
            head->prev = newNode;                    // список не пуст
        } else {
            tail = newNode;                          // список был пуст
        }
        head = newNode;
        size++;
    }

    // Добавление в конец
    void pushBack(int value) {
        DoubleNode* newNode = new DoubleNode(value);
        newNode->prev = tail;
        if (tail != nullptr) {
            tail->next = newNode;                    // список не пуст
        } else {
            head = newNode;                          // список был пуст
        }
        tail = newNode;
        size++;
    }

    // Добавление после элемента с индексом k
    void insertAfter(int k, int value) {
        DoubleNode* current = getAt(k);
        if (current == nullptr) return;              // индекс введён неверно - выход
        DoubleNode* newNode = new DoubleNode(value);
        newNode->next = current->next;               // создаём новые связи
        newNode->prev = current;
        if (current->next != nullptr) {
            current->next->prev = newNode;
        } else {
            tail = newNode;                          // вставили после хвоста
        }
        current->next = newNode;
        size++;
    }

    // Добавление перед элементом с индексом k (здесь помогает указатель prev)
    void insertBefore(int k, int value) {
        DoubleNode* current = getAt(k);
        if (current == nullptr) return;
        DoubleNode* newNode = new DoubleNode(value);
        newNode->prev = current->prev;
        newNode->next = current;
        if (current->prev != nullptr) {
            current->prev->next = newNode;
        } else {
            head = newNode;                          // вставили перед головой
        }
        current->prev = newNode;
        size++;
    }

    // Добавление по индексу: новый элемент получит индекс k
    void insertAt(int k, int value) {
        if (k < 0 || k > size) return;
        if (k == 0) {
            pushFront(value);
        } else {
            insertAfter(k - 1, value);
        }
    }

    // Удаление первого элемента
    void popFront() {
        if (head == nullptr) return;
        DoubleNode* temp = head;                     // сохраняем голову для удаления
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        } else {
            tail = nullptr;                          // в списке был один элемент
        }
        delete temp;
        size--;
    }

    // Удаление последнего элемента
    void popBack() {
        if (tail == nullptr) return;
        DoubleNode* temp = tail;                     // сохраняем хвост для удаления
        tail = tail->prev;
        if (tail != nullptr) {
            tail->next = nullptr;
        } else {
            head = nullptr;                          // в списке был один элемент
        }
        delete temp;
        size--;
    }

    // Удаление элемента по индексу
    void erase(int k) {
        DoubleNode* current = getAt(k);
        if (current == nullptr) return;              // индекс введён неверно - выход
        if (current->prev != nullptr) {              // обновляем связи соседей
            current->prev->next = current->next;
        } else {
            head = current->next;
        }
        if (current->next != nullptr) {
            current->next->prev = current->prev;
        } else {
            tail = current->prev;
        }
        delete current;
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
            erase(start);
        }
    }

    // Сортировка вставками
    void insertionSort(bool ascending) {
        DoubleNode* sorted = nullptr;                // начало нового, отсортированного списка
        DoubleNode* current = head;
        while (current != nullptr) {
            DoubleNode* nextNode = current->next;    // запоминаем следующий узел заранее
            if (sorted == nullptr || isBefore(current->data, sorted->data, ascending)) {
                current->next = sorted;
                sorted = current;
            } else {
                DoubleNode* p = sorted;
                while (p->next != nullptr && !isBefore(current->data, p->next->data, ascending)) {
                    p = p->next;
                }
                current->next = p->next;
                p->next = current;
            }
            current = nextNode;
        }
        head = sorted;
        // Связи next уже верные. Заново расставляем prev и находим хвост
        DoubleNode* previous = nullptr;
        for (DoubleNode* p = head; p != nullptr; p = p->next) {
            p->prev = previous;
            previous = p;
        }
        tail = previous;
    }

    // Удаление всего списка
    void clear() {
        while (head != nullptr) {
            popFront();
        }
    }

    // Вывод списка на экран: вперёд (по next) и назад (по prev)
    void print(const string& title) {
        cout << title << ":" << endl;
        cout << "   вперёд: ";
        for (DoubleNode* p = head; p != nullptr; p = p->next) cout << p->data << " ";
        cout << "(размер " << size << ")" << endl;
        cout << "   назад:  ";
        for (DoubleNode* p = tail; p != nullptr; p = p->prev) cout << p->data << " ";
        cout << endl;
    }
};