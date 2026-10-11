#include <iostream>
#include <string>

class Transport {
public:
    virtual ~Transport() = default;
    virtual void deliver(const std::string& cargo) const = 0;
};

class Truck : public Transport {
public:
    void deliver(const std::string& cargo) const override {
        std::cout << "Truck delivers " << cargo << " by road\n";
    }
};

class Ship : public Transport {
public:
    void deliver(const std::string& cargo) const override {
        std::cout << "Ship delivers " << cargo << " by sea\n";
    }
};

void planDelivery(const std::string& type, const std::string& cargo) {
    Transport* transport = nullptr;

    if (type == "road") {
        transport = new Truck();
    } else if (type == "sea") {
        transport = new Ship();
    }

    if (transport == nullptr) {
        std::cout << "Unknown delivery type: " << type << "\n";
        return;
    }

    transport->deliver(cargo);
    delete transport;
}

int main() {
    planDelivery("road", "furniture");
    planDelivery("sea", "containers");
    planDelivery("rail", "coal");

    return 0;
}
