#include <iostream>
#include <string>
#include <vector>

class Order {
private:
    std::string customerEmail;
    std::vector<double> itemPrices;

public:
    explicit Order(std::string email) : customerEmail(std::move(email)) {}

    void addItem(double price) {
        itemPrices.push_back(price);
    }

    double calculateTotal() const {
        double total = 0.0;
        for (double price : itemPrices)
            total += price;
        return total;
    }

    void saveToDatabase() const {
        std::cout << "Saving order of " << customerEmail << " to database...\n";
    }

    void sendConfirmationEmail() const {
        std::cout << "Sending confirmation email to " << customerEmail << "\n";
    }

    void printInvoice() const {
        std::cout << "=== INVOICE ===\n";
        std::cout << "Customer: " << customerEmail << "\n";
        std::cout << "Items: " << itemPrices.size() << "\n";
        std::cout << "Total: $" << calculateTotal() << "\n";
    }
};

int main() {
    Order order("andranik@mail.com");
    order.addItem(19.99);
    order.addItem(5.50);

    order.saveToDatabase();
    order.sendConfirmationEmail();
    order.printInvoice();

    return 0;
}
