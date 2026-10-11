#include <iostream>
#include <string>

enum class CustomerType { Regular, Student, VIP };

class DiscountCalculator {
public:
    double applyDiscount(CustomerType type, double price) const {
        if (type == CustomerType::Regular) {
            return price;
        } else if (type == CustomerType::Student) {
            return price * 0.85;
        } else if (type == CustomerType::VIP) {
            return price * 0.70;
        }
        return price;
    }
};

int main() {
    DiscountCalculator calculator;

    std::cout << "Regular: $" << calculator.applyDiscount(CustomerType::Regular, 100.0) << "\n";
    std::cout << "Student: $" << calculator.applyDiscount(CustomerType::Student, 100.0) << "\n";
    std::cout << "VIP:     $" << calculator.applyDiscount(CustomerType::VIP, 100.0) << "\n";

    return 0;
}
