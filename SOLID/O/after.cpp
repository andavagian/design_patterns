#include <iostream>
#include <memory>
#include <string>
#include <vector>

class Discount {
public:
    virtual ~Discount() = default;
    virtual double apply(double price) const = 0;
    virtual std::string name() const = 0;
};

class RegularDiscount : public Discount {
public:
    double apply(double price) const override { return price; }
    std::string name() const override { return "Regular"; }
};

class StudentDiscount : public Discount {
public:
    double apply(double price) const override { return price * 0.85; }
    std::string name() const override { return "Student"; }
};

class VIPDiscount : public Discount {
public:
    double apply(double price) const override { return price * 0.70; }
    std::string name() const override { return "VIP"; }
};

class BlackFridayDiscount : public Discount {
public:
    double apply(double price) const override { return price * 0.50; }
    std::string name() const override { return "Black Friday"; }
};

class DiscountCalculator {
public:
    void printPrices(const std::vector<std::unique_ptr<Discount>>& discounts, double price) const {
        for (const auto& discount : discounts) {
            std::cout << discount->name() << ": $" << discount->apply(price) << "\n";
        }
    }
};

int main() {
    std::vector<std::unique_ptr<Discount>> discounts;
    discounts.push_back(std::make_unique<RegularDiscount>());
    discounts.push_back(std::make_unique<StudentDiscount>());
    discounts.push_back(std::make_unique<VIPDiscount>());
    discounts.push_back(std::make_unique<BlackFridayDiscount>());

    DiscountCalculator calculator;
    calculator.printPrices(discounts, 100.0);

    return 0;
}
