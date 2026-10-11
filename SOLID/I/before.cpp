#include <iostream>
#include <stdexcept>

class IMachine {
public:
    virtual ~IMachine() = default;
    virtual void print() = 0;
    virtual void scan() = 0;
    virtual void fax() = 0;
};

class MultiFunctionPrinter : public IMachine {
public:
    void print() override { std::cout << "MFP: printing document...\n"; }
    void scan() override { std::cout << "MFP: scanning document...\n"; }
    void fax() override { std::cout << "MFP: sending fax...\n"; }
};

class SimplePrinter : public IMachine {
public:
    void print() override { std::cout << "SimplePrinter: printing document...\n"; }

    void scan() override {
        throw std::logic_error("SimplePrinter cannot scan!");
    }

    void fax() override {
        throw std::logic_error("SimplePrinter cannot fax!");
    }
};

int main() {
    MultiFunctionPrinter mfp;
    SimplePrinter simple;

    mfp.print();
    mfp.scan();
    simple.print();

    try {
        simple.scan();
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << "\n";
    }

    return 0;
}
