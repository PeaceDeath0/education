#include <iostream>
#include <cstring>

int main() {
    // Вводим 100 значных чисел через массив типа char
    char buffer[101];
    std::cout << "Введите 100 значных чисел:\n";
    std::cin.getline(buffer, sizeof(buffer));
    
    // Массив типа int для хранения преобразованных чисел
    int numbers[100];
    
    // Преобразуем строки во входном буфере в числа типа int
    for (int i = 0; i < 100; i++) {
        std::string numberString(&buffer[i*100], &buffer[i*100] + 100);
        numbers[i] = std::stoi(numberString);
    }
    
    // Выводим сумму и разность чисел
    int sum = 0;
    int diff = numbers[0];
    for (int i = 1; i < 100; i++) {
        sum += numbers[i];
        diff -= numbers[i];
    }
    std::cout << "Сумма чисел: " << sum << std::endl;
    std::cout << "Разность чисел: " << diff << std::endl;
    
    // Выводим произведение чисел
    long long product = 1;
    for (int i = 0; i < 100; i++) {
        product *= numbers[i];
    }
    std::cout << "Произведение чисел: " << product << std::endl;
    
    return 0;
}
