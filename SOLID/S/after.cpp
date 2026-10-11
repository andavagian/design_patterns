#include <iostream>
#include <string>
#include <vector>

class Order {
private:
    std::string customerEmail;
    std::vector<double> itemPrices;

public:
    explicit Order(std::string email) : customerEmail(std::move(email)) {}

    void addItem(double price) { itemPrices.push_back(price); }

    const std::string& getCustomerEmail() const { return customerEmail; }
    const std::vector<double>& getItemPrices() const { return itemPrices; }
};

class OrderCalculator {
public:
    double calculateTotal(const Order& order) const {
        double total = 0.0;
        for (double price : order.getItemPrices())
            total += price;
        return total;
    }
};

class OrderRepository {
public:
    void save(const Order& order) const {
        std::cout << "Saving order of " << order.getCustomerEmail() << " to database...\n";
    }
};

class EmailNotifier {
public:
    void sendConfirmation(const Order& order) const {
        std::cout << "Sending confirmation email to " << order.getCustomerEmail() << "\n";
    }
};

class InvoicePrinter {
private:
    OrderCalculator calculator;

public:
    void print(const Order& order) const {
        std::cout << "=== INVOICE ===\n";
        std::cout << "Customer: " << order.getCustomerEmail() << "\n";
        std::cout << "Items: " << order.getItemPrices().size() << "\n";
        std::cout << "Total: $" << calculator.calculateTotal(order) << "\n";
    }
};

int main() {
    Order order("andranik@mail.com");
    order.addItem(19.99);
    order.addItem(5.50);

    OrderRepository repository;
    EmailNotifier notifier;
    InvoicePrinter printer;

    repository.save(order);
    notifier.sendConfirmation(order);
    printer.print(order);

    return 0;
}
