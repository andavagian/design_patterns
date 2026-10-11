#include <iostream>
#include <string>

class EmailSender {
public:
    void sendEmail(const std::string& message) {
        std::cout << "Email: " << message << "\n";
    }
};

class NotificationService {
private:
    EmailSender sender;

public:
    void notify(const std::string& message) {
        sender.sendEmail(message);
    }
};

int main() {
    NotificationService service;
    service.notify("Your order has been shipped!");

    return 0;
}
