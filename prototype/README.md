# Prototype Pattern

> Create new objects by **copying an existing object** (the prototype) instead of creating them from scratch.

## Before

In `before.cpp`, to copy a `Shape*` the client must:

* check the real type with `dynamic_cast`
* know all fields of every concrete class
* update the copying code every time a new shape is added

## After

In `after.cpp`, every shape knows how to copy itself through a virtual `clone()` method:

```cpp
std::unique_ptr<Shape> clone() const override {
    return std::make_unique<Circle>(*this);
}
```

The client just calls `shape->clone()` and gets an independent copy, without knowing whether it is a `Circle` or a `Rectangle`.

Changing the color of a clone does **not** change the original.
