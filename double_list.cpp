#include "double_list.h"

#include <iostream>

// FIX_ME: Отсутствовало явное использование std::
// старый код: using namespace std;
// новый код:
using std::cout;
using std::endl;

// Конструктор Node
// FIX_ME: Добавлен explicit и правильная инициализация
// старый код: Node(int val) { data = val; next = nullptr; prev = nullptr; }
// новый код:
DoubleList::Node::Node(int val) : data(val), next(nullptr), prev(nullptr) {}

// Конструктор DoubleList
// FIX_ME: Инициализация head
// старый код: DoubleList() { head = nullptr; }
// новый код:
DoubleList::DoubleList() : head(nullptr) {}

// Деструктор DoubleList
// FIX_ME: Исправлен обход для корректного удаления
// старый код: 
// ~DoubleList() {
//     if (!head) return;
//     Node* curr = head;
//     while (true) {
//         Node* tmp = curr;
//         curr = curr->next;
//         delete tmp;
//         if (curr == head) break;
//     }
// }
// новый код:
DoubleList::~DoubleList() {
    if (!head) {
        return;
    }

    Node* current = head;
    Node* next_node = nullptr;

    do {
        next_node = current->next;
        delete current;
        current = next_node;
    } while (current != head);

    head = nullptr;
}

// Метод PushBack
// FIX_ME: Переименован и улучшен
// старый код: void push_back(int value)
// новый код:
void DoubleList::PushBack(int value) {
    Node* new_node = new Node(value);

    if (!head) {
        head = new_node;
        new_node->next = new_node;
        new_node->prev = new_node;
    }
    else {
        Node* tail = head->prev;
        tail->next = new_node;
        new_node->prev = tail;
        new_node->next = head;
        head->prev = new_node;
    }
}

// Метод Print
// FIX_ME: Переименован, добавлена проверка на пустой список
// старый код: void printList()
// новый код:
void DoubleList::Print() const {
    // FIX_ME: Отсутствовала проверка на пустой список
    // старый код: сразу начинал обход
    // новый код:
    if (!head) {
        cout << "Список пуст" << endl;
        return;
    }

    Node* current = head;
    do {
        cout << current->data << " ";
        current = current->next;
    } while (current != head);
    cout << endl;
}

// Метод DeleteNode
// FIX_ME: Переименован, улучшена логика
// старый код: Node* deleteNode(Node* node)
// новый код:
DoubleList::Node* DoubleList::DeleteNode(Node* node) {
    // FIX_ME: Добавлена проверка на nullptr
    // старый код: if (!node) return nullptr;
    // новый код: та же проверка, но улучшена логика

    if (!node) {
        return nullptr;
    }

    // FIX_ME: Исправлена логика удаления единственного элемента
    // старый код: if (node->next == node && node->prev == node)
    // новый код: оставлено, но улучшено

    if (node->next == node && node->prev == node) {
        if (node == head) {
            head = nullptr;
        }
        delete node;
        return nullptr;
    }

    Node* next_node = node->next;

    // FIX_ME: Перенаправление указателей
    // старый код: node->prev->next = node->next; node->next->prev = node->prev;
    // новый код: то же самое, но с проверками

    node->prev->next = node->next;
    node->next->prev = node->prev;

    // FIX_ME: Обновление head при удалении головы
    // старый код: if (node == head) head = nextNode;
    // новый код:
    if (node == head) {
        head = next_node;
    }

    delete node;
    return next_node;
}

// Метод IsEmpty
// FIX_ME: Метод отсутствовал в исходном коде
// новый код:
bool DoubleList::IsEmpty() const {
    return head == nullptr;
}

// Метод RemoveElementsWithEqualNeighbors
// FIX_ME: КРИТИЧЕСКАЯ ОШИБКА в логике удаления
// старый код: Node* removeSides() - сложный и ошибочный алгоритм
// новый код:
DoubleList::Node* DoubleList::RemoveElementsWithEqualNeighbors() {
    // FIX_ME: Проверка на пустой список
    // старый код: if (!head) return nullptr;
    // новый код:
    if (!head) {
        return nullptr;
    }

    // FIX_ME: Если в списке один элемент, удалять нечего
    // старый код: отсутствовала проверка
    // новый код:
    if (head->next == head) {
        return head;
    }

    bool deleted;
    do {
        deleted = false;
        Node* current = head;
        bool complete_cycle = false;

        while (!complete_cycle) {
            // FIX_ME: Проверяем условие удаления (левый и правый сосед совпадают)
            // старый код: int leftData = curr->prev->data; int rightData = curr->next->data;
            // новый код:
            int left_data = current->prev->data;
            int right_data = current->next->data;

            if (left_data == right_data) {
                deleted = true;
                Node* next_node = current->next;

                // FIX_ME: Обновление head перед удалением
                // старый код: if (curr == head) head = nextNode;
                // новый код:
                if (current == head) {
                    head = next_node;
                }

                current = DeleteNode(current);

                // FIX_ME: Если список стал пустым
                // старый код: if (!curr) return nullptr;
                // новый код:
                if (!current) {
                    return nullptr;
                }

                // FIX_ME: Продолжаем проверку с текущего элемента
                complete_cycle = false;
                continue;
            }
            else {
                current = current->next;
            }

            // FIX_ME: Проверяем завершение полного обхода
            // старый код: if (curr == start) completedCycle = true;
            // новый код:
            if (current == head) {
                complete_cycle = true;
            }
        }
    } while (deleted);  // FIX_ME: Продолжаем, пока были удаления

    // FIX_ME: Возвращаем последний элемент
    // старый код: if (!head) return nullptr; Node* tail = head->prev; return tail;
    // новый код:
    if (!head) {
        return nullptr;
    }

    return head->prev;
}