#include <iostream>
#include <vector>

struct Deposit {
    double amount;
    int term;
    double interestRate;
    double taxRate;
    int paymentPeriod;
    bool interestCapitalization;
    std::vector<double> additions;
    std::vector<double> partialWithdrawals;
};

double calculateInterest(double amount, double interestRate, int term, int paymentPeriod, bool interestCapitalization) {
    double totalInterest = 0;
    double currentAmount = amount;
    
    for (int i = 0; i < term; i += paymentPeriod) {
        double interest = currentAmount * (interestRate / 100);
        
        if (interestCapitalization) {
            currentAmount += interest;
        } else {
            currentAmount += interest * paymentPeriod;
        }
        
        totalInterest += interest;
    }
    
    return totalInterest;
}

double calculateTax(double interest, double taxRate) {
    return interest * (taxRate / 100);
}

double calculateTotalAmount(Deposit deposit) {
    double totalAmount = deposit.amount;
    double interest = calculateInterest(
        deposit.amount, deposit.interestRate, deposit.term, deposit.paymentPeriod, deposit.interestCapitalization);
    double tax = calculateTax(interest, deposit.taxRate);
    
    totalAmount += interest - tax;
    
    for (double addition : deposit.additions) {
        totalAmount += addition;
    }
    
    for (double withdrawal : deposit.partialWithdrawals) {
        totalAmount -= withdrawal;
    }
    
    return totalAmount;
}

int main() {
    Deposit deposit;
    deposit.amount = 10000;
    deposit.term = 12;
    deposit.interestRate = 5;
    deposit.taxRate = 13;
    deposit.paymentPeriod = 1;
    deposit.interestCapitalization = true;
    deposit.additions = {500, 1000};
    deposit.partialWithdrawals = {300};
    
    double interest = calculateInterest(
        deposit.amount, deposit.interestRate, deposit.term, deposit.paymentPeriod, deposit.interestCapitalization);
    double tax = calculateTax(interest, deposit.taxRate);
    double totalAmount = calculateTotalAmount(deposit);
    
    std::cout << "Accrued interest: " << interest << std::endl;
    std::cout << "Tax amount: " << tax << std::endl;
    std::cout << "Total amount at the end of term: " << totalAmount << std::endl;
    
    return 0;
}
