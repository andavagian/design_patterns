#include <iostream>
#include <memory>
#include <string>

class Notification {
public:
    virtual ~Notification() = default;
    virtual void send(const std::string& message) const = 0;
};

class EmailNotification : public Notification {
public:
    void send(const std::string& message) const override {
        std::cout << "Email: " << message << "\n";
    }
};

class SmsNotification : public Notification {
public:
    void send(const std::string& message) const override {
        std::cout << "SMS: " << message << "\n";
    }
};

class PushNotification : public Notification {
public:
    void send(const std::string& message) const override {
        std::cout << "Push: " << message << "\n";
    }
};

class NotificationFactory {
public:
    virtual ~NotificationFactory() = default;
    virtual std::unique_ptr<Notification> createNotification() const = 0;

    void notify(const std::string& message) const {
        auto notification = createNotification();
        notification->send(message);
    }
};

class EmailFactory : public NotificationFactory {
public:
    std::unique_ptr<Notification> createNotification() const override {
        return std::make_unique<EmailNotification>();
    }
};

class SmsFactory : public NotificationFactory {
public:
    std::unique_ptr<Notification> createNotification() const override {
        return std::make_unique<SmsNotification>();
    }
};

class PushFactory : public NotificationFactory {
public:
    std::unique_ptr<Notification> createNotification() const override {
        return std::make_unique<PushNotification>();
    }
};

int main() {
    std::unique_ptr<NotificationFactory> factory = std::make_unique<SmsFactory>();
    factory->notify("Your package is on the way!");

    factory = std::make_unique<EmailFactory>();
    factory->notify("Your package is on the way!");

    factory = std::make_unique<PushFactory>();
    factory->notify("Your package is on the way!");

    return 0;
}
