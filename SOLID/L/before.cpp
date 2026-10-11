#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
#include <vector>

class Bird {
protected:
    std::string name;

public:
    explicit Bird(std::string name) : name(std::move(name)) {}
    virtual ~Bird() = default;

    virtual void fly() const {
        std::cout << name << " is flying\n";
    }
};

class Eagle : public Bird {
public:
    using Bird::Bird;

    void fly() const override {
        std::cout << name << " is soaring high\n";
    }
};

class Sparrow : public Bird {
public:
    using Bird::Bird;
};

class Penguin : public Bird {
public:
    using Bird::Bird;

    void fly() const override {
        throw std::logic_error(name + " cannot fly!");
    }
};

void letBirdsFly(const std::vector<std::unique_ptr<Bird>>& birds) {
    for (const auto& bird : birds) {
        bird->fly();
    }
}

int main() {
    std::vector<std::unique_ptr<Bird>> birds;
    birds.push_back(std::make_unique<Eagle>("Eagle"));
    birds.push_back(std::make_unique<Sparrow>("Sparrow"));
    birds.push_back(std::make_unique<Penguin>("Penguin"));

    try {
        letBirdsFly(birds);
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << "\n";
    }

    return 0;
}
