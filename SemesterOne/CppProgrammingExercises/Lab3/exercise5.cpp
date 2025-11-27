
#include <iostream>
#include <string>

/*
 * =============================================================
 * LAB 3 - PROBLEMS 5 & 6: BANK ACCOUNT CLASS
 * =============================================================
 * THEORY:
 * Demonstrates encapsulation and class methods for modifying private data.
 * - deposit(): increases balance
 * - withdraw(): decreases balance safely
 * - display(): prints account info
 */

class BankAccount {
private:
    std::string accountNumber;
    std::string accountHolder;
    double balance;

public:
    BankAccount(std::string accNo, std::string holder)
        : accountNumber(accNo), accountHolder(holder), balance(0.0) {}

    void deposit(double amount) {
        balance += amount;
    }

    void withdraw(double amount) {
        if (amount <= balance)
            balance -= amount;
        else
            std::cout << "Insufficient funds!\n";
    }

    void display() const {
        std::cout << "Account: " << accountNumber
                  << "\nHolder: " << accountHolder
                  << "\nBalance: " << balance << "\n\n";
    }
};

int main() {
    BankAccount acc("12345", "Alice");
    acc.deposit(500);
    acc.withdraw(100);
    acc.display();
    return 0;
}
