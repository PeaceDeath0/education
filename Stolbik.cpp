#include <iostream>
using namespace std;

int main()
{
    // Создаем массив для хранения чисел
    int numbers[3];

    // Вводим значения для массива
    cout << "Введите три 3-х значных числа: ";
    for (int i = 0; i < 3; i++)
    {
        cin >> numbers[i];
    }

    // Выводим массив типа int
    cout << "Массив: ";
    for (int i = 0; i < 3; i++)
    {
        cout << numbers[i] << " ";
    }
    cout << endl;

    // Выполняем сложение и вычитание чисел
    int sum = 0;
    int difference = numbers[0];
    for (int i = 1; i < 3; i++)
    {
        sum += numbers[i];
        difference -= numbers[i];
    }

    // Выводим результаты
    cout << "Сумма чисел: " << sum << endl;
    cout << "Разность чисел: " << difference << endl;

    // Выполняем умножение чисел
    int multiplication = 1;
    for (int i = 0; i < 3; i++)
    {
        multiplication *= numbers[i];
    }

    // Выводим результат умножения
    cout << "Умножение чисел: " << multiplication << endl;

    return 0;
}
