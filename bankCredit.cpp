#include <iostream>
#include <cmath>

using namespace std;

double calculateAnnuityPayment(double loanAmount, int term, double interestRate) {
    double monthlyInterestRate = interestRate / 12 / 100; // Процентная ставка в месяц
    cout << "monthlyInterestRate " << monthlyInterestRate;
    double numerator = loanAmount * monthlyInterestRate * pow(1 + monthlyInterestRate, term);
    double coefficient = pow(1 + monthlyInterestRate, term) - 1;
    return numerator / coefficient;
}

void differentialPayment(double loanAmount, double interestRate, int term) {
    double monthlyInterestRate = interestRate / 12 / 100;
    double monthlyLA = loanAmount / term;

    for (int i = 1; i <= term; i++) {
        double monthlyPayment = monthlyLA + loanAmount * monthlyInterestRate;
        cout << "Месяц " << i << ":" << monthlyPayment << " рублей" << endl;
        loanAmount -= monthlyLA;
    }
}

double calculateOverpayment(double monthlyPayment, int term, double loanAmount) {
    return monthlyPayment * term - loanAmount;
}

double calculateTotalPayment(double monthlyPayment, int term) {
    return monthlyPayment * term;
}

int main() {
    double loanAmount;
    int term;
    double interestRate;
    std::string type;
    setlocale(LC_ALL, "Russian");

    cout << "Введите общую сумму кредита: ";
    cin >> loanAmount;
    cout << "Введите срок кредита (в месяцах): ";
    cin >> term;
    cout << "Введите процентную ставку: ";
    cin >> interestRate;
    cout << "Введите тип кредита (аннуитетный или дифференцированный): ";
    cin >> type;

    double monthlyPayment;
    double overpayment;
    double totalPayment;

    if (type == "a") {
        monthlyPayment = calculateAnnuityPayment(loanAmount, term, interestRate);
        overpayment = calculateOverpayment(monthlyPayment, term, loanAmount);
        totalPayment = calculateTotalPayment(monthlyPayment, term);
    }
    else if (type == "b") {
        differentialPayment(loanAmount, interestRate, term);
        return 1;
    }
    else {
        cout << "Неверно указан тип кредита." << endl;
        return 1;
    }

    cout << "Ежемесячный платеж: " << monthlyPayment << endl;
    cout << "Переплата по кредиту: " << overpayment << endl;
    cout << "Общая выплата: " << totalPayment << endl;

    return 0;
