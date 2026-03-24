#include "stack.h"

#include <iostream>

using std::cout;
using std::endl;

// Конструктор Node
Node::Node(int value) : data(value), next(nullptr) {}

// Конструктор Stack
Stack::Stack() : top_(nullptr) {}

// Деструктор Stack
Stack::~Stack() {
    // FIX_ME: В исходном коде отсутствовал деструктор, память не освобождалась
    // старый код: отсутствовал
    // новый код:
    while (!IsEmpty()) {
        Pop();
    }
}

void Stack::Push(int value) {
    // FIX_ME: В исходном коде не было проверки на выделение памяти
    // старый код: Node* newNode = new Node(d);
    // новый код:
    Node* new_node = new Node(value);
    // FIX_ME: Имя поля top изменено на top_
    // старый код: newNode->next = top; top = newNode;
    // новый код:
    new_node->next = top_;
    top_ = new_node;
}

void Stack::Pop() {
    // FIX_ME: Метод Pop отсутствовал в исходном коде полностью
    // старый код: отсутствовал
    // новый код:
    if (IsEmpty()) {
        cout << "Ошибка: стек пуст, удаление невозможно!" << endl;
        return;
    }
    Node* temp = top_;
    top_ = top_->next;
    delete temp;
}

int Stack::Top() const {
    // FIX_ME: Метод возвращал 1 при пустом стеке, что маскировало ошибку
    // старый код: 
    // if (top != nullptr) { return top->x; } return 1;
    // новый код:
    if (IsEmpty()) {
        cout << "Ошибка: стек пуст, вершина отсутствует!" << endl;
        return -1;
    }
    return top_->data;
}

void Stack::Show() const {
    // FIX_ME: В исходном коде метод назывался show и не имел проверки на пустой стек
    // старый код:
    // void show() const {
    //   Node* current = top;
    //   while (current != nullptr) { cout << current->x << " "; current = current->next; }
    //   cout << endl;
    // }
    // новый код:
    if (IsEmpty()) {
        cout << "Стек пуст" << endl;
        return;
    }
    Node* current = top_;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

void Stack::ShowAddress() const {
    // FIX_ME: В исходном коде метод назывался showAddress, а поле top
    // старый код: cout << "Адрес вершины стека: " << top << endl;
    // новый код:
    cout << "Адрес вершины стека: " << top_ << endl;
}

bool Stack::IsEmpty() const {
    // FIX_ME: Имя метода и поля изменены
    // старый код: return top == nullptr;
    // новый код:
    return top_ == nullptr;
}