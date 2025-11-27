#include <iostream>
#include <string>

/*
  Encapsulation in action:
  ------------------------
  - accountNumber, accountHolder, and balance are PRIVATE.
  - No external code can modify balance directly.
  - All changes must go through deposit() or withdraw(), ensuring safety.

  Why encapsulation matters:
  --------------------------
  Without encapsulation:
    myAccount.balance = -9999;
  would be possible, which is dangerous (unless you're in a lot of debt).

  With encapsulation:
    - Only safe, meaningful operations are allowed.
    - The user cannot put the object into an invalid state.
*/

class BankAccount { // BankAccount class definition
private: // Private attributes 
    int accountNumber; // Unique account identifier
    std::string accountHolder; // Name of the account holder
    double balance; // Current balance in the account

public:
    BankAccount(int number, const std::string& holder) // Constructor
        : accountNumber(number), accountHolder(holder), balance(0.0) {} // Initialise balance to 0

    void deposit(double amount) { // Deposit Method
        balance += amount;
    }

    void withdraw(double amount) { // Withdraw Method
        if (amount <= balance)
            balance -= amount;
        else
            std::cout << "Insufficient funds\n"; // Handles edge case or if insufficient balance.
    }

    void display() const {
        std::cout << "Account Number: " << accountNumber << "\n"
                  << "Account Holder: " << accountHolder << "\n"
                  << "Balance: £" << balance << "\n";
    }
};

int main() {
    BankAccount acc(1234, "John Smith");
    acc.deposit(500);
    acc.withdraw(200);
    acc.display();
}

/*
Why the output looks like this:
-------------------------------

1. A BankAccount is created with:
      accountNumber = 12345
      accountHolder = "John Smith"
      balance = 0

2. deposit(1000.0) adds £1000 to the balance:
      balance = 1000

3. display() prints:
      Account Number: 12345
      Account Holder: John Smith
      Balance: £1000

4. withdraw(500.0) subtracts £500:
      balance = 500

5. display() prints the updated information:
      Account Number: 12345
      Account Holder: John Smith
      Balance: £500

So the output shows the balance changing from £1000 -> £500.
*/
