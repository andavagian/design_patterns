# Builder Pattern

> Separate the construction of a complex object from its representation, so the same construction process can create different representations.

## Before

In `before.cpp`, `Computer` has one big constructor with 6 parameters (**telescoping constructor**):

```cpp
Computer office("Intel i5", 16, 512, "Integrated", true, false);
```

It is hard to remember the order of arguments, and `true, false` says nothing about their meaning.

## After

In `after.cpp`, `Computer::Builder` builds the object step by step:

* required fields (`cpu`, `ramGb`) are passed to the Builder constructor
* optional fields have default values and are set with methods
* every method returns `*this` -> **fluent interface** (method chaining)
* `build()` returns the finished `Computer`

The `Computer` constructor is `private`, so a computer can only be created through its Builder.
