# LSP - Liskov Substitution Principle

> Objects of a child class must be able to replace objects of the parent class **without breaking the program**.

## Before

In `before.cpp`, `BankAccount` has a `withdraw()` method.

`FixedDepositAccount` inherits from `BankAccount`, but money cannot be withdrawn from a fixed deposit, so it throws an exception.

`withdrawFromAll()` expects every `BankAccount` to support `withdraw()`, so the program breaks. **This is an LSP violation.**

## After

In `after.cpp`, the base class contains only the behavior shared by all accounts (`deposit()`).

`withdraw()` is moved to `WithdrawableAccount`:

```text
            BankAccount
           /           \
WithdrawableAccount   FixedDepositAccount
     /        \
Savings     Checking
```

Now every child can safely replace its parent.

## Main question

```cpp
Parent* obj = new Child();
```

> "If I put Child in place of Parent, does the program still work as expected?"
>
> Yes -> LSP is satisfied. No -> LSP violation.
