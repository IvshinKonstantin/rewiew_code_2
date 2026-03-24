#include "stack.h"

#include <iostream>
#include <windows.h>

// FIX_ME: В исходном коде использовалась директива using namespace std
// старый код: using namespace std;
// новый код: using std::cout; using std::cin; - но лучше использовать явное std::

int main() {
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Stack stack;
    int count, value;

    // FIX_ME: Имена переменных N и n не соответствуют Google Style (должны быть понятными)
    // старый код: int N, n;
    // новый код:
    std::cout << "Сколько чисел вы хотите, чтобы было в стеке? ";
    std::cin >> count;

    for (int i = 0; i < count; ++i) {
        std::cout << "Введите число " << i + 1 << ": ";
        std::cin >> value;
        // FIX_ME: Имя метода push изменено на Push
        // старый код: stack.push(n);
        // новый код:
        stack.Push(value);
    }

    // FIX_ME: Имя метода showAddress изменено на ShowAddress
    // старый код: stack.showAddress();
    // новый код:
    stack.ShowAddress();

    // FIX_ME: Имя метода show изменено на Show
    // старый код: stack.show();
    // новый код:
    std::cout << "Элементы в стеке: ";
    stack.Show();

    int d;
    std::cout << "Введите значение D для добавления в стек: ";
    std::cin >> d;
    stack.Push(d);

    std::cout << "Элементы в новом стеке: ";
    stack.Show();
    stack.ShowAddress();

    // FIX_ME: Имя метода isEmpty изменено на IsEmpty, getTopValue на Top
    // старый код: if (!stack.isEmpty()) { cout << stack.getTopValue() << endl; }
    // новый код:
    if (!stack.IsEmpty()) {
        std::cout << "Значение новой вершины: " << stack.Top() << std::endl;
    }
    else {
        std::cout << "Стек пуст!" << std::endl;
    }

    // FIX_ME: В исходном коде отсутствовал return 0 (хотя это необязательно для main)
    // новый код:
    return 0;
}