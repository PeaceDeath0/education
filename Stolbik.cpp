#include <iostream>

int main() {
    const int SIZE = 3;

    // Ввод чисел
    int buffer[SIZE];
    for (int i = 0; i < SIZE; i++) {
        std::cout << "Введите число: ";
        std::cin >> buffer[i];
    }

    // Вывод массива типа int
    std::cout << "Массив чисел: ";
    for (int i = 0; i < SIZE; i++) {
        std::cout << buffer[i] << " ";
    }
    std::cout << std::endl;

    // Вычисление сложения и вычитания
    int sum = 0;
    int difference = buffer[0];
    for (int i = 1; i < SIZE; i++) {
        sum += buffer[i];
        difference -= buffer[i];
    }
    std::cout << "Сумма чисел: " << sum << std::endl;
    std::cout << "Разность чисел: " << difference << std::endl;

    // Вычисление умножения
    int product = buffer[0];
    for (int i = 1; i < SIZE; i++) {
        product *= buffer[i];
    }
    std::cout << "Произведение чисел: " << product << std::endl;

    return 0;
}
