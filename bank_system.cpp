#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Account {
private:
    int accountNumber;
    string accountHolderName;
    double balance;

public:
    // Constructor to initialize a new account
    Account(int accNum, string name, double initialDeposit) {
        accountNumber = accNum;
        accountHolderName = name;
        if (initialDeposit >= 0) {
            balance = initialDeposit;
        } else {
            balance = 0.0;
            cout << "Initial deposit cannot be negative. Set balance to $0.00.\n";
        }
    }

    // Function to deposit money
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Successfully deposited $" << fixed << setprecision(2) << amount << "\n";
        } else {
            cout << "Invalid deposit amount!\n";
        }
    }

    // Function to withdraw money
    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Successfully withdrew $" << fixed << setprecision(2) << amount << "\n";
        } else if (amount > balance) {
            cout << "Error: Insufficient funds!\n";
        } else {
            cout << "Invalid withdrawal amount!\n";
        }
    }

    // Function to display account info
    void displayAccount() const {
        cout << "\n--- Account Details ---\n";
        cout << "Account Number: " << accountNumber << "\n";
        cout << "Holder Name: " << accountHolderName << "\n";
        cout << "Current Balance: $" << fixed << setprecision(2) << balance << "\n";
    }
};

int main() {
    int accNum;
    string name;
    double initialDeposit;

    cout << "=== Welcome to the Bank System ===\n";
    cout << "Create your account to begin.\n";
    cout << "Enter Account Number: ";
    cin >> accNum;
    cout << "Enter Account Holder Name: ";
    cin.ignore(); // Clear the input buffer
    getline(cin, name);
    cout << "Enter Initial Deposit ($): ";
    cin >> initialDeposit;

    // Create the account object dynamically with user input
    Account userAccount(accNum, name, initialDeposit);

    int choice;
    double amount;

    do {
        cout << "\n==============================\n";
        cout << "       BANK MENU              \n";
        cout << "==============================\n";
        cout << "1. View Account Details\n";
        cout << "2. Deposit Money\n";
        cout << "3. Withdraw Money\n";
        cout << "4. Exit\n";
        cout << "Enter your choice (1-4): ";
        cin >> choice;

        switch (choice) {
            case 1:
                userAccount.displayAccount();
                break;
            case 2:
                cout << "Enter amount to deposit: $";
                cin >> amount;
                userAccount.deposit(amount);
                break;
            case 3:
                cout << "Enter amount to withdraw: $";
                cin >> amount;
                userAccount.withdraw(amount);
                break;
            case 4:
                cout << "Thank you for banking with us. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice! Please choose between 1 and 4.\n";
        }
    } while (choice != 4);

    return 0;
}
