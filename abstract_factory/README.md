# Abstract Factory Pattern

> Provide an interface for creating **families of related objects** without specifying their concrete classes.

## Before

In `before.cpp`, the client creates every UI element itself (`LightButton`, `DarkCheckbox`, ...).

Nothing guarantees that elements belong to the same theme, and the example even mixes a `DarkButton` with a `LightCheckbox`.

## After

In `after.cpp`:

| Role | Classes |
|---|---|
| Abstract Products | `Button`, `Checkbox`, `TextField` |
| Concrete Products | `Light*`, `Dark*` |
| Abstract Factory | `UIFactory` |
| Concrete Factories | `LightThemeFactory`, `DarkThemeFactory` |

`renderLoginForm()` receives one factory and gets a **consistent family** of elements. To add a new theme, we just add a new factory and its products.

### Factory Method vs Abstract Factory

* **Factory Method** creates **one** product.
* **Abstract Factory** creates a **family** of related products.
