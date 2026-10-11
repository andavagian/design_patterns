# LSP - Liskov Substitution Principle

> Objects of a child class must be able to replace objects of the parent class **without breaking the program**.

## Before

In `before.cpp`, the `Bird` class has a `fly()` method, so it promises that **every** bird can fly.

`Penguin` inherits from `Bird`, but penguins cannot fly, so its `fly()` throws an exception.

`letBirdsFly()` expects every `Bird` to fly, and the program breaks on the penguin. **This is an LSP violation.**

## After

In `after.cpp`, the base class `Bird` contains only what **all** birds can do: `move()` and `layEgg()`.

`fly()` is moved to `FlyingBird`, and `Penguin` has its own `swim()`:

```text
            Bird
           /    \
   FlyingBird   Penguin
     /     \
  Eagle   Sparrow
```

* `letBirdsFly()` accepts only `FlyingBird`, so a penguin can never get there.
* `moveAllBirds()` accepts any `Bird`, and every bird moves in its own way (fly or swim).

Now every child can safely replace its parent.

## Main question

```cpp
Parent* obj = new Child();
```

> "If I put Child in place of Parent, does the program still work as expected?"
>
> Yes -> LSP is satisfied. No -> LSP violation.
