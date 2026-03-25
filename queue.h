#pragma once
#ifndef QUEUE_H
#define QUEUE_H

// FIX_ME: В исходном коде отсутствовали guards заголовочного файла
// FIX_ME: Использовалась директива using namespace std в глобальной области
// старый код: using namespace std;
// новый код: удалено, используется явное std::

// FIX_ME: Имена структур должны быть в CamelCase
// старый код: struct PNode
// новый код:
struct TNode {
    int data;
    TNode* next;

    // FIX_ME: Отсутствовал конструктор, использовалась агрегатная инициализация
    // старый код: PNode* newNode = new PNode{value, nullptr};
    // новый код:
    explicit TNode(int value) : data(value), next(nullptr) {}
};

// FIX_ME: Имя структуры PQueue не соответствует Google Style
// старый код: struct PQueue
// новый код:
struct TQueue {
    TNode* head;  // FIX_ME: Имена полей front и last не соответствуют терминологии
    // старый код: PNode* front; PNode* last;
    // новый код: head (начало), tail (конец)
    TNode* tail;

    // FIX_ME: Конструктор не инициализировал поля nullptr (хотя это и делалось в теле)
    // старый код: PQueue() : front(nullptr), last(nullptr) {}
    // новый код:
    TQueue() : head(nullptr), tail(nullptr) {}
};

// FIX_ME: Функции должны иметь имена в lower_case_with_underscores
// старый код: void Enqueue(PQueue& Q, int value)
// новый код:
void Enqueue(TQueue& queue, int value);

// FIX_ME: Функция Dequeue должна возвращать значение и освобождать память
// старый код: int Dequeue(PQueue& Q)
// новый код:
int Dequeue(TQueue& queue);

// FIX_ME: Отсутствовали функции для вывода и проверки пустоты
// старый код: отсутствовали
// новый код:
void ShowQueue(const TQueue& queue);
bool IsEmpty(const TQueue& queue);
void ShowAddresses(const TQueue& queue);

#endif  // QUEUE_H
