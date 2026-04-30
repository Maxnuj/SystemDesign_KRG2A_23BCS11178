#include <bits/stdc++.h>
using namespace std;

class BankAccount {
private:
    string accountHolder;
    double balance;

public:
    BankAccount(string name, double initialBalance) {
        accountHolder = name;
        balance = initialBalance;
    }

    double getBalance() {
        return balance;
    }

    string getAccountHolder() {
        return accountHolder;
    }

    void deposit(double amount) {
        balance += amount;
    }

    void withdraw(double amount) {
        balance -= amount;
    }
};

class ValidationService {
public:
    static bool validateWithdraw(double balance, double amount) {
        if (amount <= 0) {
            cout << "Invalid amount!" << endl;
            return false;
        }
        if (amount > balance) {
            cout << "Insufficient balance!" << endl;
            return false;
        }
        return true;
    }

    static bool validateDeposit(double amount) {
        if (amount <= 0) {
            cout << "Invalid deposit amount!" << endl;
            return false;
        }
        return true;
    }
};

class NotificationService {
public:
    static void sendNotification(string message) {
        cout << "[Notification]: " << message << endl;
    }
};

class TransactionService {
public:
    static void deposit(BankAccount &account, double amount) {
        if (!ValidationService::validateDeposit(amount)) return;

        account.deposit(amount);
        NotificationService::sendNotification(
            "Deposited " + to_string(amount) +
            ". New Balance: " + to_string(account.getBalance())
        );
    }

    static void withdraw(BankAccount &account, double amount) {
        if (!ValidationService::validateWithdraw(account.getBalance(), amount)) return;

        account.withdraw(amount);
        NotificationService::sendNotification(
            "Withdrawn " + to_string(amount) +
            ". New Balance: " + to_string(account.getBalance())
        );
    }
};

int main() {
    BankAccount account("Manuj", 5000);

    TransactionService::deposit(account, 2000);
    TransactionService::withdraw(account, 3000);
    TransactionService::withdraw(account, 5000);

    return 0;
}