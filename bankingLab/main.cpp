/* Ellia Morse EECS 348 Sunday Nov 26th
Design a simple banking system that utilizes inheritance and operator overloading to handle transactions 
between different types of bank accounts

*/

#include <iostream>
#include <string>

class Account {
    protected:
        int accountNumber;
        std::string accountHolder;
        double balance;

    public:
        // Constructor
        Account(int number, const std::string& holder, double initialBalance = 0.0)
            : accountNumber(number), accountHolder(holder), balance(initialBalance) {}

        // Display account details
        virtual void displayDetails() const {
            std::cout << "Account Number: " << accountNumber << std::endl;
            std::cout << "Account Holder: " << accountHolder << std::endl;
            std::cout << "Balance: $" << balance << std::endl;
        }

        // Deposit money into the account
        void deposit(double amount) {
            if (amount > 0) {
                balance += amount;
                std::cout << "Deposited $" << amount << " into the account." << std::endl;
            } else {
                std::cout << "Invalid deposit amount." << std::endl;
            }
        }
        // Withdraw money from the account (ensure sufficient balance)
        virtual void withdraw(double amount) {
            if (amount > 0 && amount <= balance) {
                balance -= amount;
                std::cout << "Withdrawn $" << amount << " from the account." << std::endl;
            } else {
                std::cout << "Invalid withdrawal amount or insufficient balance." << std::endl;
            }
        }
        
    Account& operator+(std::pair<Account&, double> transfer) {
        double amount = transfer.second;
        Account& to = transfer.first;

        if (amount > 0 && amount <= balance) {
            balance -= amount;
            to.balance += amount;
            std::cout << "Transferred $" << amount << " from account " << accountNumber
                      << " to account " << to.accountNumber << "." << std::endl;
        } else {
            std::cout << "Invalid transfer amount or insufficient balance in the source account." << std::endl;
        }

        return *this; // Return the current account for possible chaining
    }
    // Overload the << operator to display account details
    friend std::ostream& operator<<(std::ostream& os, const Account& acc);
    
};

// Implementation of the << operator to display account details
std::ostream& operator<<(std::ostream& os, const Account& acc) {
    os << "Account Number: " << acc.accountNumber << std::endl;
    os << "Account Holder: " << acc.accountHolder << std::endl;
    os << "Balance: $" << acc.balance << std::endl;
    return os;
}

class SavingsAccount : public Account {
    private:
        double interestRate;

    public:
        // Constructor
        SavingsAccount(int number, const std::string& holder, double initialBalance = 0.0, double rate = 0.0)
            : Account(number, holder, initialBalance), interestRate(rate) {}

        // Display savings account details
        void displayDetails() const override {
            std::cout << "Savings Account Details:" << std::endl;
            Account::displayDetails();  // Call the base class displayDetails method
            std::cout << "Interest Rate: " << interestRate << "%" << std::endl;
        }

        // Apply interest to the account balance
        void applyInterest() {
            double interest = balance * (interestRate / 100);
            balance += interest;
            std::cout << "Interest of $" << interest << " applied to the account." << std::endl;
        }
         // Withdraw money from the account (ensure sufficient balance)
        virtual void withdraw(double amount) override{
            if (amount > 0 && amount <= balance) {
                balance -= amount;
                std::cout << "Withdrawn $" << amount << " from the account." << std::endl;
            } else {
                std::cout << "Invalid withdrawal amount or insufficient balance." << std::endl;
            }
    }

};

class CurrentAccount : public Account {
    private:
        double overdraftLimit;

    public:
        // Constructor
        CurrentAccount(int number, const std::string& holder, double initialBalance = 0.0, double overdraft = 0.0)
            : Account(number, holder, initialBalance), overdraftLimit(overdraft) {}

        // Display current account details
        void displayDetails() const override {
            std::cout << "Current Account Details:" << std::endl;
            Account::displayDetails();  // Call the base class displayDetails method
            std::cout << "Overdraft Limit: $" << overdraftLimit << std::endl;
        }

        // Override the withdraw method to allow overdrafts up to the specified limit
        void withdraw(double amount) override {
            double availableBalance = balance + overdraftLimit;

            if (amount > 0 && amount <= availableBalance) {
                balance -= amount;
                std::cout << "Withdrawn $" << amount << " from the current account." << std::endl;
            } else {
                std::cout << "Invalid withdrawal amount or exceeded overdraft limit." << std::endl;
            }
        }
};



int main() {
    // Create instances of SavingsAccount and CurrentAccount
    SavingsAccount savingsAccount(123, "Saver", 1000.0, 2.5);
    CurrentAccount currentAccount(456, "Spender", 500.0, 200.0);

    // Display initial account details
    std::cout << "Initial Account Details:" << std::endl;
    std::cout << "------------------------" << std::endl;
    std::cout << savingsAccount << std::endl;
    std::cout << currentAccount << std::endl;

    // Deposit money into SavingsAccount
    savingsAccount.deposit(500.0);
    std::cout << "\nAfter Deposit:" << std::endl;
    std::cout << "------------------------" << std::endl;
    std::cout << savingsAccount << std::endl;

    // Withdraw money from CurrentAccount
    currentAccount.withdraw(300.0);
    std::cout << "\nAfter Withdrawal:" << std::endl;
    std::cout << "------------------------" << std::endl;
    std::cout << currentAccount << std::endl;


    // Apply interest to SavingsAccount
    savingsAccount.applyInterest();
    std::cout << "\nAfter Interest:" << std::endl;
    std::cout << "------------------------" << std::endl;
    std::cout << savingsAccount << std::endl;

    // Attempt to withdraw more than the overdraft limit from CurrentAccount
    currentAccount.withdraw(800.0);
    std::cout << "\nAttempted Overdraft:" << std::endl;
    std::cout << "------------------------" << std::endl;
    std::cout << currentAccount << std::endl;

    return 0;
}