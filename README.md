# Design Patterns

Homework on SOLID principles and design patterns in C++.

## Structure

| Folder | Topic | Type |
|---|---|---|
| `SOLID/` | S, O, L, I, D principles | Principles |
| `singleton/` | Singleton | Creational |
| `factory/` | Factory Method | Creational |
| `abstract_factory/` | Abstract Factory | Creational |
| `builder/` | Builder | Creational |
| `prototype/` | Prototype | Creational |
| `composite/` | Composite | Structural |

Every folder contains:

* `before.cpp` - the problem without the pattern / principle
* `after.cpp` - the solution
* `README.md` - explanation

## Build and run

```bash
c++ -std=c++17 -Wall -Wextra -Werror singleton/after.cpp -o singleton_after
./singleton_after
```

Or build everything at once:

```bash
make
```
