#include <iostream>
#include <memory>
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
};

class WithdrawableAccount : public BankAccount {
public:
    using BankAccount::BankAccount;

    virtual void withdraw(double amount) {
        balance -= amount;
        std::cout << "Withdrew $" << amount << ", balance: $" << balance << "\n";
    }
};

class SavingsAccount : public WithdrawableAccount {
public:
    using WithdrawableAccount::WithdrawableAccount;
};

class CheckingAccount : public WithdrawableAccount {
public:
    using WithdrawableAccount::WithdrawableAccount;
};

class FixedDepositAccount : public BankAccount {
public:
    using BankAccount::BankAccount;
};

void withdrawFromAll(const std::vector<std::shared_ptr<WithdrawableAccount>>& accounts, double amount) {
    for (const auto& account : accounts) {
        account->withdraw(amount);
    }
}

void depositToAll(const std::vector<std::shared_ptr<BankAccount>>& accounts, double amount) {
    for (const auto& account : accounts) {
        account->deposit(amount);
    }
}

int main() {
    auto savings = std::make_shared<SavingsAccount>(500.0);
    auto checking = std::make_shared<CheckingAccount>(300.0);
    auto fixed = std::make_shared<FixedDepositAccount>(1000.0);

    withdrawFromAll({savings, checking}, 100.0);
    depositToAll({savings, checking, fixed}, 50.0);

    return 0;
}
