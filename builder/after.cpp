#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

class BurgerBuilder;

class Burger {
private:
    friend class BurgerBuilder;

    std::string bun;
    std::string patty;
    std::string sauce = "None";
    std::vector<std::string> toppings;

    Burger() = default;

public:
    void show() const {
        std::cout << "Bun: " << bun << "\n";
        std::cout << "Patty: " << patty << "\n";
        std::cout << "Sauce: " << sauce << "\n";
        std::cout << "Toppings: ";
        if (toppings.empty()) {
            std::cout << "None";
        }
        for (std::size_t i = 0; i < toppings.size(); ++i) {
            std::cout << (i > 0 ? ", " : "") << toppings[i];
        }
        std::cout << "\n";
    }
};

class BurgerBuilder {
private:
    Burger burger;

public:
    BurgerBuilder& setBun(const std::string& bun) {
        burger.bun = bun;
        return *this;
    }
    BurgerBuilder& setPatty(const std::string& patty) {
        burger.patty = patty;
        return *this;
    }
    BurgerBuilder& setSauce(const std::string& sauce) {
        burger.sauce = sauce;
        return *this;
    }
    BurgerBuilder& addCheese() {
        burger.toppings.push_back("Cheese");
        return *this;
    }
    BurgerBuilder& addLettuce() {
        burger.toppings.push_back("Lettuce");
        return *this;
    }
    BurgerBuilder& addTomato() {
        burger.toppings.push_back("Tomato");
        return *this;
    }
    BurgerBuilder& addOnion() {
        burger.toppings.push_back("Onion");
        return *this;
    }
    Burger build() const {
        if (burger.bun.empty() || burger.patty.empty()) {
            throw std::invalid_argument("Burger needs a bun and a patty");
        }
        return burger;
    }
};

int main() {
    Burger classic = BurgerBuilder()
        .setBun("Sesame")
        .setPatty("Beef")
        .setSauce("Ketchup")
        .addCheese()
        .addLettuce()
        .addOnion()
        .build();

    Burger veggie = BurgerBuilder()
        .setBun("Whole wheat")
        .setPatty("Veggie")
        .addTomato()
        .addLettuce()
        .build();

    std::cout << "--- Classic Burger ---\n";
    classic.show();

    std::cout << "\n--- Veggie Burger ---\n";
    veggie.show();

    try {
        Burger broken = BurgerBuilder().setSauce("BBQ").build();
        broken.show();
    } catch (const std::exception& e) {
        std::cout << "\nError: " << e.what() << "\n";
    }

    return 0;
}
