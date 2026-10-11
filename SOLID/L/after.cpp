#include <iostream>
#include <memory>
#include <string>
#include <vector>

class Bird {
protected:
    std::string name;

public:
    explicit Bird(std::string name) : name(std::move(name)) {}
    virtual ~Bird() = default;

    virtual void move() const = 0;

    void layEgg() const {
        std::cout << name << " laid an egg\n";
    }
};

class FlyingBird : public Bird {
public:
    using Bird::Bird;

    virtual void fly() const {
        std::cout << name << " is flying\n";
    }

    void move() const override { fly(); }
};

class Eagle : public FlyingBird {
public:
    using FlyingBird::FlyingBird;

    void fly() const override {
        std::cout << name << " is soaring high\n";
    }
};

class Sparrow : public FlyingBird {
public:
    using FlyingBird::FlyingBird;
};

class Penguin : public Bird {
public:
    using Bird::Bird;

    void swim() const {
        std::cout << name << " is swimming\n";
    }

    void move() const override { swim(); }
};

void letBirdsFly(const std::vector<std::shared_ptr<FlyingBird>>& birds) {
    for (const auto& bird : birds) {
        bird->fly();
    }
}

void moveAllBirds(const std::vector<std::shared_ptr<Bird>>& birds) {
    for (const auto& bird : birds) {
        bird->move();
        bird->layEgg();
    }
}

int main() {
    auto eagle = std::make_shared<Eagle>("Eagle");
    auto sparrow = std::make_shared<Sparrow>("Sparrow");
    auto penguin = std::make_shared<Penguin>("Penguin");

    std::cout << "--- Flying birds ---\n";
    letBirdsFly({eagle, sparrow});

    std::cout << "\n--- All birds ---\n";
    moveAllBirds({eagle, sparrow, penguin});

    return 0;
}
