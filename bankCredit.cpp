#include <iostream>
#include <cmath>

    double calculateAnnuityPayment(double loanAmount, int term, double interestRate) {
        double monthlyInterestRate = interestRate / 12 / 100; // Процентная ставка в месяц
        double coefficient = monthlyInterestRate * pow(1 + monthlyInterestRate, term) / (pow(1 + monthlyInterestRate, term) - 1);
        return loanAmount * coefficient;
    }

    double calculateDifferentiatedPayment(double loanAmount, int term, double interestRate, int month) {
        double monthlyInterestRate = interestRate / 12 / 100; // Процентная ставка в месяц
        double bodyPayment = loanAmount / term; // Сумма выплаты по основному долгу в месяц
        double interestPayment = (loanAmount - (month - 1) * bodyPayment) * monthlyInterestRate; // Сумма выплаты по процентам в месяц
        return bodyPayment + interestPayment;
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

        std::cout << "Введите общую сумму кредита: ";
        std::cin >> loanAmount;
        std::cout << "Введите срок кредита (в месяцах): ";
        std::cin >> term;
        std::cout << "Введите процентную ставку: ";
        std::cin >> interestRate;
        std::cout << "Введите тип кредита (аннуитетный или дифференцированный): ";
        std::cin >> type;

        double monthlyPayment;
        double overpayment;
        double totalPayment;

        if (type == "аннуитетный") {
            monthlyPayment = calculateAnnuityPayment(loanAmount, term, interestRate);
            overpayment = calculateOverpayment(monthlyPayment, term, loanAmount);
            totalPayment = calculateTotalPayment(monthlyPayment, term);
        } else if (type == "дифференцированный") {
            monthlyPayment = calculateDifferentiatedPayment(loanAmount, term, interestRate, 1);
            overpayment = calculateOverpayment(monthlyPayment, term, loanAmount);
            totalPayment = calculateTotalPayment(monthlyPayment, term);
        } else {
            std::cout << "Неверно указан тип кредита." << std::endl;
            return 0;
        }
                
        std::cout << "Ежемесячный платеж: " << monthlyPayment << std::endl;
        std::cout << "Переплата по кредиту: " << overpayment << std::endl;
        std::cout << "Общая выплата: " << totalPayment << std::endl;

        return 0;
    }

