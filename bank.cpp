#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

class BankAccount {
private:
    string accountHolder;
    double balance;

public:
    BankAccount(const string& name, double initialBalance = 0.0)
        : accountHolder(name), balance(initialBalance) {
        if (initialBalance < 0)
            throw invalid_argument("Initial balance cannot be negative");
    }

    void deposit(double amount) {
        if (amount <= 0)
            throw invalid_argument("Deposit amount must be positive");
        balance += amount;
    }

    void withdraw(double amount) {
        if (amount <= 0)
            throw invalid_argument("Withdrawal amount must be positive");
        if (amount > balance)
            throw runtime_error("Insufficient balance");
        balance -= amount;
    }

    double getBalance() const {
        return balance;
    }

    string getHolderName() const {
        return accountHolder;
    }

    bool hasSufficientFunds(double amount) const {
        return balance >= amount;
    }
};

int main() {
    BankAccount acc("Prajwal", 1000.0);

    acc.deposit(500.0);
    acc.withdraw(200.0);

    cout << "Account Holder: " << acc.getHolderName() << endl;
    cout << "Current Balance: " << acc.getBalance() << endl;
    cout << "Has Sufficient Funds (500): " 
         << (acc.hasSufficientFunds(500) ? "Yes" : "No") << endl;

    return 0;
}
