# Builder Pattern

> Separate the construction of a complex object from its representation, so the same construction process can create different representations.

## Before

In `before.cpp`, `Burger` has one big constructor with 7 parameters (**telescoping constructor**):

```cpp
Burger classic("Sesame", "Beef", "Ketchup", true, true, false, true);
```

* It is hard to remember the order of arguments.
* `true, true, false, true` says nothing about which topping is which.
* Nothing stops us from creating a burger without a bun or a patty.

## After

In `after.cpp`, `BurgerBuilder` builds the burger step by step:

* `setBun()`, `setPatty()`, `setSauce()` set the main parts
* `addCheese()`, `addLettuce()`, `addTomato()`, `addOnion()` add toppings
* every method returns `*this` -> **fluent interface** (method chaining)
* `build()` checks that the burger has a bun and a patty, then returns it

The `Burger` constructor is `private` and `BurgerBuilder` is its `friend`, so a burger can only be created through the builder.

```cpp
Burger classic = BurgerBuilder()
    .setBun("Sesame")
    .setPatty("Beef")
    .setSauce("Ketchup")
    .addCheese()
    .addLettuce()
    .build();
```
