# OCP - Open/Closed Principle

> Software entities should be **open for extension**, but **closed for modification**.

## Before

In `before.cpp`, `DiscountCalculator::applyDiscount()` uses an `if / else if` chain over `CustomerType`.

To add a new discount (for example *Black Friday*) we must:

1. change the `enum`
2. change the `applyDiscount()` function

Every change can break already tested code.

## After

In `after.cpp`, every discount is a separate class that implements the `Discount` interface.

`BlackFridayDiscount` was added as a **new class**, and `DiscountCalculator` was not changed at all.

```text
          Discount
     /    /     \      \
Regular Student  VIP  BlackFriday
```
