#include "queue.h"

#include <iostream>
#include <windows.h>

// FIX_ME: В исходном коде использовалась директива using namespace std
// старый код: using namespace std;
// новый код: используется явное std::

int main() {
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    TQueue queue;

    // FIX_ME: В условии сказано: "очередь содержит не менее пяти элементов"
    // В исходном коде просто добавлялись числа от 1 до 10 без ввода с клавиатуры
    // старый код: for (int i = 1; i <= 10; ++i) { Enqueue(Q, i); }
    // новый код: ввод с клавиатуры с проверкой

    int initial_count;
    std::cout << "Введите количество начальных элементов (не менее 5): ";
    std::cin >> initial_count;

    // FIX_ME: Отсутствовала проверка, что элементов не менее 5
    // новый код:
    if (initial_count < 5) {
        std::cout << "Ошибка: очередь должна содержать не менее 5 элементов!" << std::endl;
        return 1;
    }

    std::cout << "Введите " << initial_count << " чисел:" << std::endl;
    for (int i = 0; i < initial_count; ++i) {
        int value;
        std::cout << "Число " << i + 1 << ": ";
        std::cin >> value;
        Enqueue(queue, value);
    }

    std::cout << "\nИсходная очередь: ";
    ShowQueue(queue);
    ShowAddresses(queue);

    // FIX_ME: Извлекаем 5 элементов согласно условию
    // В исходном коде извлекалось 5 элементов без проверки
    // старый код: for (int i = 0; i < 5; ++i) { ... }
    // новый код: с проверкой на пустоту
    std::cout << "\nИзвлеченные элементы: ";
    for (int i = 0; i < 5; ++i) {
        if (!IsEmpty(queue)) {
            int value = Dequeue(queue);
            std::cout << value << " ";
        }
        else {
            std::cout << "\nОчередь опустела раньше времени!";
            break;
        }
    }
    std::cout << std::endl;

    // FIX_ME: Вывод адресов результирующей очереди
    // В исходном коде адреса выводились только если очередь не пуста
    // новый код: используется функция ShowAddresses
    std::cout << "\nРезультирующая очередь: ";
    ShowQueue(queue);
    ShowAddresses(queue);

    // FIX_ME: Отсутствовала проверка на пустоту при выводе адресов
    // В исходном коде проверка была, но неполная
    // новый код: проверка вынесена в функцию ShowAddresses

    // FIX_ME: Отсутствовало освобождение оставшейся памяти
    // новый код:
    while (!IsEmpty(queue)) {
        Dequeue(queue);  // Очищаем очередь
    }

    return 0;
}
