#include <iostream>
#include <memory>
#include <stdexcept>
#include <vector>

class BankAccount {
protected:
    double balance;

public:
    explicit BankAccount(double balance) : balance(balance) {}
    virtual ~BankAccount() = default;

    virtual void deposit(double amount) {
        balance += amount;
        std::cout << "Deposited $" << amount << ", balance: $" << balance << "\n";
    }

    virtual void withdraw(double amount) {
        balance -= amount;
        std::cout << "Withdrew $" << amount << ", balance: $" << balance << "\n";
    }
};

class SavingsAccount : public BankAccount {
public:
    using BankAccount::BankAccount;
};

class FixedDepositAccount : public BankAccount {
public:
    using BankAccount::BankAccount;

    void withdraw(double) override {
        throw std::logic_error("Withdrawal is not allowed for fixed deposits!");
    }
};

void withdrawFromAll(const std::vector<std::shared_ptr<BankAccount>>& accounts, double amount) {
    for (const auto& account : accounts) {
        account->withdraw(amount);
    }
}

int main() {
    std::vector<std::shared_ptr<BankAccount>> accounts;
    accounts.push_back(std::make_shared<SavingsAccount>(500.0));
    accounts.push_back(std::make_shared<FixedDepositAccount>(1000.0));

    try {
        withdrawFromAll(accounts, 100.0);
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << "\n";
    }

    return 0;
}
