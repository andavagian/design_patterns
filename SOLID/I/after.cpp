#include <iostream>

class IPrinter {
public:
    virtual ~IPrinter() = default;
    virtual void print() = 0;
};

class IScanner {
public:
    virtual ~IScanner() = default;
    virtual void scan() = 0;
};

class IFax {
public:
    virtual ~IFax() = default;
    virtual void fax() = 0;
};

class MultiFunctionPrinter : public IPrinter, public IScanner, public IFax {
public:
    void print() override { std::cout << "MFP: printing document...\n"; }
    void scan() override { std::cout << "MFP: scanning document...\n"; }
    void fax() override { std::cout << "MFP: sending fax...\n"; }
};

class SimplePrinter : public IPrinter {
public:
    void print() override { std::cout << "SimplePrinter: printing document...\n"; }
};

class Scanner : public IScanner {
public:
    void scan() override { std::cout << "Scanner: scanning document...\n"; }
};

void printDocument(IPrinter& printer) { printer.print(); }
void scanDocument(IScanner& scanner) { scanner.scan(); }

int main() {
    MultiFunctionPrinter mfp;
    SimplePrinter simple;
    Scanner scanner;

    printDocument(mfp);
    printDocument(simple);
    scanDocument(mfp);
    scanDocument(scanner);

    return 0;
}
