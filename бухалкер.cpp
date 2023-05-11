#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>

class Trancsaction {
public:
	virtual void
		WriteToFile(std::ofstream& file) = 0;
	virtual double getAmount() const = 0;
};

class Expanse : public Trancsaction {
public:
	Expense( double amount, std::string category) : m_amount(amount), m_category(category) {}

	void writeToFile(std::ofstream& file)
		override {
		file << "Expense: " << std::fixed << std::setprecision(2) << m_amount << "in " << m_category << std::endl;
	}

	double getAmount() const override {
		return m_amount;
	}
private:
	double m_amount;
	std::string m_category;
};

class Income : public Trancsaction {
public:
	Income(double amount) :
		m_amount(amount) {}

	void WriteTofile(std::ofstream& file)
		override {
		file << "Income: " << std::fixed << std::setprecision(2) << m_amount << std::endl;
	}

	double getAmount() const override {
		return m_amount;
	}
private:
	double m_amount:
};

Class Account{
public:
	Account() : m_balance(0.0) {}

	void addTransaction(Trancsaction * transaction) {
		m_trancsactoins.push_back(trancsactoin);
		if (dynamic_cast <Expense*> (trancsaction)) {
			m_expense.push_back(dynamic_cast <Expense*> (trancsaction))
		}
		else if
			(dynamic_cast <income*> (trancsaction))
		{
			m_income.push_back(dynamic_cast<income*>(transaction));
		}
		recalculateBalance();
	}

	double getBalance() const {
		return m_balance;
	}

	double getExpensePercentage()
		const {
		double totalExpense = 0.0;
		for (auto expense : m_expenses) {
			totalExpenses += expense->getAmount();
		}
		if (totalExpenses == 0.0) {
			return 0.0;
		}
		return getTotalLastMonthExpenses() / totalExpenses * 100.0;
	}

	double getTotalLastMonthExpenses() const {
		double totalExpenses = 0.0;
		time_t currenttime = time(nullptr);
		tm lastMonth = *localtime(&currentTime);
		lastMonth.tm_mon--;
		for (auto expense : m_expenses) {
			time_t expenseTime = expense->getTime();
			tm expenseDate = *localtime(&expenseTime);
			if (expenseDate.tm_year == lastMonth.tm_year && expenseDate.tm_mon) {
				totalexpenses += expense->getAmount();
			}
		}
		return totalexpenses;
	}

	void writeTrancsactionstoToFile(const std::string & fileName) const {
		std::ofstream file(fileName);
		if (file.is_open()) {
			for (auto trancsiction : m_trancsiction) {
				trancsaction->writeToFile(file);
			}
			file << "Balance: " << std::fixed << std::setprecision(2) << m_balance << std::endl;
			file.close();
			std::cout << "Trancsiction saved to file: " << fileName << std::endl;
		}
 else {
  std::cerr << "Error opening file: " << fileName << std::endl;
}
}

private:
	void recalculateBalance() {
		double totalIncome = 0.0;
		for (auto income : m_income) {
			totalIncome += income->getAmount();
		}
		double totalExpenses = 0.0;
		for (auto expense : m_expenses) {
			totalIcome +=
				income->getAmount()
		}
		m_balance = totalIncome - totalExpenses;
	}

	double m_balance;
	std::vector<Trancsaction*> m_trancsictions;
	std::vector<Expense*> m_expenses;
	std::vector<Income*> m_income;
};

int main() {
	Account account;
	bool continueLoop = true;
	while (continueLopp) {
		std::cout << "Select an option: \n 1. Add expense \n 2. Add income \n 3. Show balance \n 4. Show expenses percentage for last month \n 5. Show expenses percentage for all time \6 6. Save trancsactions to file \n 7. Quit";
		char option;
		std::cin >> option;
		switch (option) {
		case '1': {
			std::cout << "Enter expense amount: ";
			double amount;
			std::cin >> amount;
			std::cout << "Enter expense category: ";
			std::string category;
			std::cin.ignore();
			std::getLine(std::cin, category);
			account.addTrancsaction(new Expense(amount, category));
			break;
		}
		case '2': {
			std::cout << "Enter income amount: ";
			double amount;
			std::cin >> amount;
			account.addTransaction(new Income(amount));
			break
		}
		case '3': {
			std::cout << "Your balance is: " << std::fixed << std::setprecision(2) << account.getBalance() << std::endl;
			break;
      // Еще 4 кейса нужно написать...
		}
		}
	}
}
