# Factory Method Pattern

> Define an interface for creating an object, but let subclasses decide which class to instantiate.

## Before

In `before.cpp`, `planDelivery()` creates transports directly with `new` inside an `if / else if` chain.

* The delivery code depends on **every** concrete transport (`Truck`, `Ship`).
* Adding rail delivery means changing `planDelivery()`, so `"rail"` currently fails.
* Memory is managed manually with `delete`.

## After

In `after.cpp`:

| Role | Class |
|---|---|
| Product | `Transport` |
| Concrete Products | `Truck`, `Ship`, `Train` |
| Creator | `Logistics` (has the factory method `createTransport()`) |
| Concrete Creators | `RoadLogistics`, `SeaLogistics`, `RailLogistics` |

`Logistics::planDelivery()` works only with the `Transport` interface. Every subclass decides which transport to create.

Rail delivery was added with two **new** classes (`Train` and `RailLogistics`), without changing existing code. Objects are returned as `std::unique_ptr`, so no manual `delete` is needed.
