# DIP - Dependency Inversion Principle

> High-level modules should not depend on low-level modules. Both should depend on **abstractions**.

## Before

In `before.cpp`, `NotificationService` (high-level) creates and uses `EmailSender` (low-level) directly.

To send SMS instead of email, we have to rewrite `NotificationService`.

## After

In `after.cpp`, we introduce the `IMessageSender` abstraction.

`NotificationService` receives any `IMessageSender` through its constructor (**dependency injection**).

```text
Before:  NotificationService -> EmailSender

After:   NotificationService -> IMessageSender <- EmailSender
                                               <- SmsSender
                                               <- TelegramSender
```

**DIP = depend on abstractions, not on concrete classes.**
