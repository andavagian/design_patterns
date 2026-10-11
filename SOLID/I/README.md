# ISP - Interface Segregation Principle

> Clients should not be forced to depend on methods they do not use.

## Before

In `before.cpp`, `IMachine` is a **fat interface** with `print()`, `scan()` and `fax()`.

`SimplePrinter` can only print, but it is forced to implement `scan()` and `fax()` and throws exceptions there.

## After

In `after.cpp`, the big interface is split into small ones:

* `IPrinter`
* `IScanner`
* `IFax`

Every class implements only the interfaces it really needs:

| Class | Interfaces |
|---|---|
| `MultiFunctionPrinter` | `IPrinter`, `IScanner`, `IFax` |
| `SimplePrinter` | `IPrinter` |
| `Scanner` | `IScanner` |
