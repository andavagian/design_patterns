#include <iostream>
#include <memory>
#include <string>

class IMessageSender {
public:
    virtual ~IMessageSender() = default;
    virtual void send(const std::string& message) = 0;
};

class EmailSender : public IMessageSender {
public:
    void send(const std::string& message) override {
        std::cout << "Email: " << message << "\n";
    }
};

class SmsSender : public IMessageSender {
public:
    void send(const std::string& message) override {
        std::cout << "SMS: " << message << "\n";
    }
};

class TelegramSender : public IMessageSender {
public:
    void send(const std::string& message) override {
        std::cout << "Telegram: " << message << "\n";
    }
};

class NotificationService {
private:
    std::unique_ptr<IMessageSender> sender;

public:
    explicit NotificationService(std::unique_ptr<IMessageSender> sender)
        : sender(std::move(sender)) {}

    void notify(const std::string& message) {
        sender->send(message);
    }
};

int main() {
    NotificationService emailService(std::make_unique<EmailSender>());
    NotificationService smsService(std::make_unique<SmsSender>());
    NotificationService telegramService(std::make_unique<TelegramSender>());

    emailService.notify("Your order has been shipped!");
    smsService.notify("Your order has been shipped!");
    telegramService.notify("Your order has been shipped!");

    return 0;
}
