#include "queue.h"

#include <iostream>

// FIX_ME: Отсутствовало явное использование std::
// старый код: using namespace std;
// новый код:
using std::cout;
using std::endl;

void Enqueue(TQueue& queue, int value) {
    // FIX_ME: В исходном коде использовалась агрегатная инициализация вместо конструктора
    // старый код: PNode* newNode = new PNode{value, nullptr};
    // новый код:
    TNode* new_node = new TNode(value);

    // FIX_ME: Имена полей front/last изменены на head/tail
    // старый код: if (Q.last) { Q.last->next = newNode; }
    // новый код:
    if (queue.tail != nullptr) {
        queue.tail->next = new_node;
    }
    else {
        // FIX_ME: При добавлении в пустую очередь head также должен указывать на новый элемент
        // старый код: Q.front = newNode;
        // новый код:
        queue.head = new_node;
    }
    queue.tail = new_node;

    // FIX_ME: Отсутствовала проверка успешности выделения памяти
    // новый код: (в реальном приложении нужно проверять new_node != nullptr)
}

int Dequeue(TQueue& queue) {
    // FIX_ME: В исходном коде отсутствовала проверка на пустую очередь
    // старый код: PNode* temp = Q.front;
    // новый код:
    if (IsEmpty(queue)) {
        cout << "Ошибка: очередь пуста, извлечение невозможно!" << endl;
        return -1;  // Возвращаем ошибочное значение
    }

    TNode* temp = queue.head;
    int value = temp->data;

    // FIX_ME: Имена полей front/last изменены на head/tail
    // старый код: Q.front = Q.front->next;
    // новый код:
    queue.head = queue.head->next;

    // FIX_ME: Если очередь стала пустой, tail также должен быть nullptr
    // старый код: if (Q.front == nullptr) { Q.last = nullptr; }
    // новый код:
    if (queue.head == nullptr) {
        queue.tail = nullptr;
    }

    delete temp;
    return value;
}

// FIX_ME: Функция ShowQueue отсутствовала в исходном коде
// новый код:
void ShowQueue(const TQueue& queue) {
    if (IsEmpty(queue)) {
        cout << "Очередь пуста" << endl;
        return;
    }

    TNode* current = queue.head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

// FIX_ME: Функция IsEmpty отсутствовала в исходном коде
// новый код:
bool IsEmpty(const TQueue& queue) {
    return queue.head == nullptr;
}

// FIX_ME: Функция ShowAddresses отсутствовала в исходном коде
// новый код:
void ShowAddresses(const TQueue& queue) {
    if (IsEmpty(queue)) {
        cout << "Очередь пуста, адрес начала: nullptr" << endl;
        cout << "Очередь пуста, адрес конца: nullptr" << endl;
    }
    else {
        cout << "Адрес начала очереди: " << queue.head
            << ", Значение: " << queue.head->data << endl;
        cout << "Адрес конца очереди: " << queue.tail
            << ", Значение: " << queue.tail->data << endl;
    }
}
