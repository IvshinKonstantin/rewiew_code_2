#ifndef LINKED_LIST_H
#define LINKED_LIST_H

// FIX_ME: В исходном коде отсутствовали guards заголовочного файла
// FIX_ME: Использовалась директива using namespace std в глобальной области
// старый код: using namespace std;
// новый код: удалено, используется явное std::

class Node {
public:
    int data;       
    Node* next;     
    
    // FIX_ME: Конструктор должен быть explicit для предотвращения неявных преобразований
    // старый код: Node(int value) : data(value), next(nullptr) {}
    // новый код:
    explicit Node(int value);
};

class LinkedList {
private:
    Node* head_;  // FIX_ME: Имя поля head должно заканчиваться на _ (Google Style)
                  // старый код: Node* head;
                  // новый код: Node* head_;

public:
    // FIX_ME: Конструктор должен инициализировать head_ = nullptr
    // старый код: LinkedList() : head(nullptr) {}
    // новый код:
    LinkedList();
    
    // FIX_ME: Добавлен деструктор для освобождения памяти
    // старый код: отсутствовал
    // новый код:
    ~LinkedList();
    
    // FIX_ME: Имена методов должны быть в CamelCase или lower_case? 
    // Google Style рекомендует CamelCase для классов, но для методов - lower_case
    // В данной задаче используем lower_case_with_underscores
    // старый код: void add(int value)
    // новый код:
    void Add(int value);
    
    // FIX_ME: Метод insertBeforeEverySecond - слишком длинное имя
    // но оставим для ясности, изменив на lower_case
    // старый код: void insertBeforeEverySecond(int M)
    // новый код:
    void InsertBeforeEverySecond(int m);
    
    // FIX_ME: Метод print переименован в Print или Show
    // старый код: void print()
    // новый код:
    void Print() const;
    
    // FIX_ME: Метод getLastNode должен быть const, если не изменяет список
    // старый код: Node* getLastNode()
    // новый код:
    Node* GetLastNode() const;
    
    // FIX_ME: Метод clearList переименован в Clear
    // старый код: void clearList()
    // новый код:
    void Clear();
    
    // FIX_ME: Метод для проверки пустоты отсутствовал
    // новый код:
    bool IsEmpty() const;
    
    // FIX_ME: Дружественная функция не нужна, так как есть публичный метод
    // старый код: friend void insertBeforeEverySecond(LinkedList& list, int M);
    // новый код: удалено
    
private:
    // FIX_ME: Вспомогательный метод для вставки (логика вынесена из публичного метода)
    // новый код:
    void InsertBeforeNode(Node* current, int m);
};

#endif  // LINKED_LIST_H
