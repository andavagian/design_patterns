# Singleton Pattern

> Ensure that a class has only one instance and provide a global point of access to it.

## Before

In `before.cpp`, every `AppConfig` object is created separately.

Changing the language in `config1` does not affect `config2`, so the application has two different configurations.

## After

In `after.cpp`:

* `private` constructor -> nobody can create the object directly
* copy constructor and `operator=` are `delete`d -> nobody can copy it
* `static getInstance()` -> always returns the same object

### Meyers' Singleton

The instance is a local `static` variable inside `getInstance()`. It is created on the first call, and since C++11 its initialization is **thread-safe**.
