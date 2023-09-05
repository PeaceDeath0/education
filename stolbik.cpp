#include <iostream>
#include <string>

// Функция для преобразования строкового числа в массив типа int
     int* strToIntArray(const std::string& number) {
            int* arr = new int[number.length()];
     for (int i = 0; i < number.length(); i++) {
         arr[i] = number[i] - '0'; // Преобразование символа в цифру
     }
     return arr;
    }

// Функция для вывода массива типа int
    void printIntArray(int* arr, int size) {
           for (int i = 0; i < size; i++) {
               std::cout << arr[i];
            }
     std::cout << std::endl;
    }

    int main() {
        std::string number1, number2;
        std::cout << "Введите первое число: ";
        std::cin >> number1;
        std::cout << "Введите второе число: ";
        std::cin >> number2;

    // Преобразование строковых чисел в массивы типа int
    int* arr1 = strToIntArray(number1);
    int* arr2 = strToIntArray(number2);

    int size = number1.length(); // Предполагаем, что длины чисел одинаковые

    int* result = new int[size]; // Массив для хранения результата

    int choice;
    std::cout << "Выберите действие:" << std::endl;
    std::cout << "1. Вычесть" << std::endl;
    std::cout << "2. Сложить" << std::endl;
    std::cout << "3. Умножить" << std::endl;
    std::cin >> choice;

    switch (choice) {
        case 1: // Вычитание
            for (int i = 0; i < size; i++) {
                result[i] = arr1[i] - arr2[i];
            }
        break;
        case 2: // Сложение
            for (int i = 0; i < size; i++) {
                result[i] = arr1[i] + arr2[i];
            }
        break;
        case 3: // Умножение
            for (int i = 0; i < size; i++) {
                result[i] = arr1[i] * arr2[i];
            }
        break;

        default: // Некорректный выбор
        std::cout << "Некорректный выбор действия." << std::endl;
        delete[] arr1;
        delete[] arr2;
        delete[] result;
        return 0;
    }

    std::cout << "Результат: ";
    printIntArray(result, size);

    delete[] arr1;
    delete[] arr2;
    delete[] result;

    return 0;
}
