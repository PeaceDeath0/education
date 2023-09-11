#include<iostream>
#include<vector>

using namespace std;

        // Структура для хранения информации о пополнениях и снятиях
    struct Transaction {
        int month;
        double amount;
    };

        // Функция для вычисления доходности вклада
    void calculateIncome(double depositAmount, int depositTerm, double interestRate, double taxRate,
    int paymentFrequency, bool interestCapitalization, vector<Transaction>& additionalDeposits,
    vector<Transaction>& partialWithdrawals) {
        double totalInterest = 0;
        double totalTax = 0;
        double totalAmount = depositAmount;

        // Вычисление процентов и налогов за каждый месяц
        for (int month = 1; month <= depositTerm; month++) {
        // Проверка наличия пополнений
            for (Transaction deposit : additionalDeposits) {
                if (deposit.month == month) {
                    totalAmount += deposit.amount;
                }
            }

        // Проверка наличия частичных снятий
            for (Transaction withdrawal : partialWithdrawals) {
                if (withdrawal.month == month) {
                    totalAmount -= withdrawal.amount;
                }
            }

        // Вычисление процентов по процентной ставке
            double interest = (totalAmount * interestRate * paymentFrequency) / 100;
            totalInterest += interest;

        // Вычисление налога на проценты
            if (interest > 0) {
                double tax = (interest * taxRate) / 100;
                totalTax += tax;
            }       

        // Проверка капитализации процентов
            if (interestCapitalization) {
                totalAmount += interest - totalTax;
            } else {
                totalAmount += interest - totalTax;
            }
        }   

        // Вывод результатов
        cout << "Начисленные проценты: " << totalInterest << endl;
        cout << "Сумма налога: " << totalTax << endl;
        cout << "Сумма на вкладе к концу срока: " << totalAmount << endl;
    }

    int main() {
        // Ввод параметров вклада
        double depositAmount;
        int depositTerm;
        double interestRate;
        double taxRate;
        int paymentFrequency;
        bool interestCapitalization;

        cout << "Введите сумму вклада: ";
        cin >> depositAmount;

        cout << "Введите срок размещения (в месяцах): ";
        cin >> depositTerm;

        cout << "Введите процентную ставку: ";
        cin >> interestRate;

        cout << "Введите налоговую ставку: ";
        cin >> taxRate;

        cout << "Введите периодичность выплат (количество раз в год): ";
        cin >> paymentFrequency;

        cout << "Введите капитализацию процентов (1 - да, 0 - нет): ";
        cin >> interestCapitalization;
        
        // Ввод пополнений
        int additionalDepositsCount;
        cout << "Введите количество пополнений: ";
        cin >> additionalDepositsCount;

        vector<Transaction> additionalDeposits;
        for (int i = 0; i < additionalDepositsCount; i++) {
            Transaction deposit;
            cout << "Введите месяц пополнения: ";
            cin >> deposit.month;
            cout << "Введите сумму пополнения: ";
            cin >> deposit.amount;
            additionalDeposits.push_back(deposit);
        }

        // Ввод частичных снятий
        int partialWithdrawalsCount;
        cout << "Введите количество частичных снятий: ";
        cin >> partialWithdrawalsCount;

        vector<Transaction> partialWithdrawals;
            for (int i = 0; i < partialWithdrawalsCount; i++) {
            Transaction withdrawal;
            cout << "Введите месяц снятия: ";
            cin >> withdrawal.month;
            cout << "Введите сумму снятия: ";
            cin >> withdrawal.amount;
            partialWithdrawals.push_back(withdrawal);
        }

        // Вычисление доходности вклада
        calculateIncome(depositAmount, depositTerm, interestRate, taxRate, paymentFrequency, interestCapitalization,
        additionalDeposits, partialWithdrawals);

        return 0;
    }
