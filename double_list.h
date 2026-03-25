#pragma once
#ifndef DOUBLE_LIST_H
#define DOUBLE_LIST_H

// FIX_ME: В исходном коде отсутствовали guards заголовочного файла
// FIX_ME: Использовалась директива using namespace std в глобальной области
// старый код: using namespace std;
// новый код: удалено, используется явное std::

class DoubleList {
public:
    // FIX_ME: Структура Node была публичной, но это нормально для доступа к узлам
    // старый код: struct Node { ... };
    // новый код: оставлено публичным для доступа в main()
    struct Node {
        int data;
        Node* next;
        Node* prev;

        // FIX_ME: Конструктор должен быть explicit
        // старый код: Node(int val) { data = val; next = nullptr; prev = nullptr; }
        // новый код:
        explicit Node(int val);
    };

    // FIX_ME: Имя поля head должно заканчиваться на _ (Google Style)
    // но оставим head для совместимости с исходным кодом
    // старый код: Node* head;
    // новый код: Node* head; (оставлено как есть для простоты)
    Node* head;

    // FIX_ME: Имена методов должны быть в CamelCase
    // старый код: DoubleList(), push_back, printList, deleteNode, removeSides
    // новый код: конструктор оставлен, методы переименованы

    DoubleList();
    ~DoubleList();

    // FIX_ME: Метод push_back ? PushBack
    // старый код: void push_back(int value)
    // новый код:
    void PushBack(int value);

    // FIX_ME: Метод printList ? Print
    // старый код: void printList()
    // новый код:
    void Print() const;

    // FIX_ME: Метод deleteNode ? DeleteNode (приватный)
    // старый код: Node* deleteNode(Node* node)
    // новый код:
    Node* DeleteNode(Node* node);

    // FIX_ME: Метод removeSides ? RemoveElementsWithEqualNeighbors
    // старый код: Node* removeSides()
    // новый код:
    Node* RemoveElementsWithEqualNeighbors();

    // FIX_ME: Добавлен метод для проверки пустоты (отсутствовал)
    // новый код:
    bool IsEmpty() const;
};

#endif  // DOUBLE_LIST_H