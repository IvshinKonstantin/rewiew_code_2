#include "double_list.h"

#include <iostream>
#include <windows.h>

// FIX_ME: В исходном коде использовалась директива using namespace std
// старый код: using namespace std;
// новый код: используется явное std::

int main() {
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    DoubleList list;
    int n, value;

    // FIX_ME: Дружественный интерфейс с пояснениями
    // старый код: cout << "сколько надо числе: ";
    // новый код:
    std::cout << "Введите количество элементов в списке: ";
    std::cin >> n;

    // FIX_ME: Добавлена проверка корректности ввода
    // старый код: отсутствовала
    // новый код:
    if (n < 0) {
        std::cout << "Ошибка: количество элементов не может быть отрицательным!" << std::endl;
        return 1;
    }

    if (n > 0) {
        std::cout << "Введите " << n << " чисел:" << std::endl;
        for (int i = 0; i < n; ++i) {
            std::cout << "Элемент " << i + 1 << ": ";
            std::cin >> value;
            // FIX_ME: Метод переименован
            // старый код: list.push_back(value);
            // новый код:
            list.PushBack(value);
        }
    }

    // FIX_ME: Метод переименован
    // старый код: cout << "нормальный список: "; list.printList();
    // новый код:
    std::cout << "\nИсходный список: ";
    list.Print();

    // FIX_ME: Метод переименован и изменен тип возврата
    // старый код: DoubleList::Node* tail = list.removeSides();
    // новый код:
    DoubleList::Node* last_node = list.RemoveElementsWithEqualNeighbors();

    // FIX_ME: Метод переименован
    // старый код: cout << "обработанный список: "; list.printList();
    // новый код:
    std::cout << "Список после удаления: ";
    list.Print();

    // FIX_ME: Исправлена ошибка с выводом tail->data при пустом списке
    // старый код: cout << "последний элемент: " << tail->data << endl;
    // новый код:
    if (last_node != nullptr) {
        std::cout << "\nСсылка на последний элемент (P2): " << last_node << std::endl;
        std::cout << "Значение последнего элемента: " << last_node->data << std::endl;
    }
    else {
        std::cout << "\nСписок пуст, последний элемент отсутствует." << std::endl;
    }

    return 0;
}