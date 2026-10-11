# SRP - Single Responsibility Principle

> A class should have only one reason to change.

## Before

In `before.cpp`, the `Order` class does everything:

* calculates the total price
* saves the order to the database
* sends a confirmation email
* prints the invoice

If the email format, the database or the invoice layout changes, we have to modify the same `Order` class.

## After

In `after.cpp`, every responsibility has its own class:

| Class | Responsibility |
|---|---|
| `Order` | holds order data |
| `OrderCalculator` | calculates the total |
| `OrderRepository` | saves to database |
| `EmailNotifier` | sends emails |
| `InvoicePrinter` | prints the invoice |

SRP does **not** mean "one method per class". A class can have many methods, as long as they all belong to the **same responsibility**.
