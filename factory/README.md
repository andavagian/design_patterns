# Factory Method Pattern

> Define an interface for creating an object, but let subclasses decide which class to instantiate.

## Before

In `before.cpp`, the client code creates objects directly with `new` inside an `if / else if` chain.

* The client depends on **every** concrete class.
* Adding a new notification type means changing the client code.
* Memory is managed manually with `delete`.

## After

In `after.cpp`:

| Role | Class |
|---|---|
| Product | `Notification` |
| Concrete Products | `EmailNotification`, `SmsNotification`, `PushNotification` |
| Creator | `NotificationFactory` (has `createNotification()`) |
| Concrete Creators | `EmailFactory`, `SmsFactory`, `PushFactory` |

The client only works with `NotificationFactory` and `Notification`. Objects are returned as `std::unique_ptr`, so no manual `delete` is needed.
