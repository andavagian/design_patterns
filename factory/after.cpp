#include <iostream>
#include <memory>
#include <string>
#include <vector>

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

class Train : public Transport {
public:
    void deliver(const std::string& cargo) const override {
        std::cout << "Train delivers " << cargo << " by rail\n";
    }
};

class Logistics {
public:
    virtual ~Logistics() = default;
    virtual std::unique_ptr<Transport> createTransport() const = 0;

    void planDelivery(const std::string& cargo) const {
        std::unique_ptr<Transport> transport = createTransport();
        transport->deliver(cargo);
    }
};

class RoadLogistics : public Logistics {
public:
    std::unique_ptr<Transport> createTransport() const override {
        return std::make_unique<Truck>();
    }
};

class SeaLogistics : public Logistics {
public:
    std::unique_ptr<Transport> createTransport() const override {
        return std::make_unique<Ship>();
    }
};

class RailLogistics : public Logistics {
public:
    std::unique_ptr<Transport> createTransport() const override {
        return std::make_unique<Train>();
    }
};

int main() {
    std::vector<std::unique_ptr<Logistics>> companies;
    companies.push_back(std::make_unique<RoadLogistics>());
    companies.push_back(std::make_unique<SeaLogistics>());
    companies.push_back(std::make_unique<RailLogistics>());

    std::vector<std::string> cargo = {"furniture", "containers", "coal"};

    for (std::size_t i = 0; i < companies.size(); ++i) {
        companies[i]->planDelivery(cargo[i]);
    }

    return 0;
}
