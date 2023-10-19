#include <iostream>
#include <sstream>

// Функция для ввода 100 значных чисел через буфер
void inputNumbers(int buffer[100]) {
    std::string input;

    // Запрашиваем у пользователя ввод чисел
    std::cout << "Введите 100 значных чисел через пробел: ";
    std::getline(std::cin, input);

    // Используем строковый поток для разделения чисел
    std::istringstream iss(input);

    // Заполняем буфер
    for (int i = 0; i < 100; i++) {
        iss >> buffer[i];
    }
}

// Функция для вывода массива типа int
void printArray(int array[100]) {
    for (int i = 0; i < 100; i++) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    // Создаем буфер и массив для вывода
    int buffer[100];
    int array[100];

    // Вызываем функцию ввода чисел
    inputNumbers(buffer);

    // Выводим массив типа int
    std::cout << "Массив типа int: ";
    printArray(buffer);

    // Выполняем сложение и вычитание
    int sum = 0;
    int difference = 0;

    for (int i = 0; i < 100; i++) {
        sum += buffer[i];
        difference -= buffer[i];
    }

    std::cout << "Сумма чисел: " << sum << std::endl;
    std::cout << "Разность чисел: " << difference << std::endl;

    // Выполняем умножение
    int product = 1;

    for (int i = 0; i < 100; i++) {
        product *= buffer[i];
    }

    std::cout << "Произведение чисел: " << product << std::endl;

    return 0;
}

