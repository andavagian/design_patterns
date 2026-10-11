#include <iostream>
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

int main() {
    std::string type = "sms";

    Notification* notification = nullptr;
    if (type == "email") {
        notification = new EmailNotification();
    } else if (type == "sms") {
        notification = new SmsNotification();
    } else if (type == "push") {
        notification = new PushNotification();
    }

    if (notification) {
        notification->send("Your package is on the way!");
        delete notification;
    }

    return 0;
}
