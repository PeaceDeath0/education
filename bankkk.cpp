#include <iostream>
#include <vector>

using namespace std;

struct Payout {
    double amount;
    int duration;
};

struct Withdrawal {
    double amount;
    int duration;
};

double calculateInterest(double depositAmount, double interestRate, int duration, bool capitalization) {
    double interest = 0;
    if (capitalization) {
        for (int i = 0; i < duration; i++) {
            interest += depositAmount * interestRate / 100;
            depositAmount += interest;
        }
    } else {
        interest = depositAmount * interestRate / 100 * duration;
    }
    return interest;
}

double calculateTax(double interestAmount, double taxRate) {
    return interestAmount * taxRate / 100;
}

double calculateTotalAmount(double depositAmount, double interestAmount, double taxAmount, vector<Payout>& payouts, vector<Withdrawal>& withdrawals) {
    double totalAmount = depositAmount + interestAmount - taxAmount;

    for (auto& payout : payouts) {
        if (payout.duration <= 0) {
            totalAmount += payout.amount;
        }
    }

    for (auto& withdrawal : withdrawals) {
        if (withdrawal.duration <= 0) {
            totalAmount -= withdrawal.amount;
        }
    }

    return totalAmount;
}

int main() {
    double depositAmount, interestRate, taxRate;
    int duration;
    bool capitalization;
    int payoutCount, withdrawalCount;

    cout << "Введите сумму вклада: ";
    cin >> depositAmount;

    cout << "Введите процентную ставку: ";
    cin >> interestRate;

    cout << "Введите срок размещения (в годах): ";
    cin >> duration;

    cout << "Введите налоговую ставку: ";
    cin >> taxRate;

    cout << "Будет ли процентная ставка капитализироваться (1 - да, 0 - нет): ";
    cin >> capitalization;

    cout << "Введите количество выплат: ";
    cin >> payoutCount;

    vector<Payout> payouts(payoutCount);
    for (int i = 0; i < payoutCount; i++) {
        cout << "Введите сумму выплаты " << i + 1 << ": ";
        cin >> payouts[i].amount;
        cout << "Введите длительность выплаты " << i + 1 << ": ";
        cin >> payouts[i].duration;
    }

    cout << "Введите количество частичных снятий: ";
    cin >> withdrawalCount;

    vector<Withdrawal> withdrawals(withdrawalCount);
    for (int i = 0; i < withdrawalCount; i++) {
        cout << "Введите сумму снятия " << i + 1 << ": ";
        cin >> withdrawals[i].amount;
        cout << "Введите длительность снятия " << i + 1 << ": ";
        cin >> withdrawals[i].duration;
    }

    double interestAmount = calculateInterest(depositAmount, interestRate, duration, capitalization);
    double taxAmount = calculateTax(interestAmount, taxRate);
    double totalAmount = calculateTotalAmount(depositAmount, interestAmount, taxAmount, payouts, withdrawals);

    cout << "Начисленные проценты: " << interestAmount << endl;
    cout << "Сумма налога: " << taxAmount << endl;
    cout << "Сумма на вкладе к концу срока: " << totalAmount << endl;

    return 0;
}
