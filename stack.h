#pragma once
#ifndef STACK_H
#define STACK_H

#include <iostream>

// FIX_ME: Имя класса Node допустимо, но поле x названо непонятно
// старый код: int x;
// новый код: int data;
class Node {
public:
	int data;        // Значение узла
	Node* next;      // Указатель на следующий узел

	// FIX_ME: Отсутствовал explicit, что допускало неявное преобразование
	// старый код: Node(int d) : x(d), next(nullptr) {}
	// новый код:
	explicit Node(int value);
};

class Stack {
public:
	Stack();
	// FIX_ME: Отсутствовал деструктор, что приводило к утечке памяти
	// старый код: отсутствовал
	// новый код:
	~Stack();

	// FIX_ME: Имя метода должно быть в lower_case_with_underscores или Push (по Google Style)
	// старый код: void push(int d)
	// новый код:
	void Push(int value);

	// FIX_ME: Отсутствовал метод удаления элемента из стека
	// старый код: отсутствовал
	// новый код:
	void Pop();

	// FIX_ME: Имя метода getTopValue не соответствует Google Style Guide
	// старый код: int getTopValue() const
	// новый код:
	int Top() const;

	// FIX_ME: Имя метода show должно быть Show (PascalCase для методов в Google Style?)
	// Согласно Google Style, методы должны быть lower_case, но для единообразия с Push/Pop
	// старый код: void show() const
	// новый код:
	void Show() const;

	// FIX_ME: Имя метода showAddress должно быть ShowAddress
	// старый код: void showAddress() const
	// новый код:
	void ShowAddress() const;

	// FIX_ME: Имя метода isEmpty должно быть IsEmpty
	// старый код: bool isEmpty() const
	// новый код:
	bool IsEmpty() const;

private:
	// FIX_ME: Имя поля top должно заканчиваться на _ (по Google Style)
	// старый код: Node* top;
	// новый код:
	Node* top_;
};

#endif  // STACK_H