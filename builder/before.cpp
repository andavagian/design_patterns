#include <iostream>
#include <string>

class Burger {
private:
    std::string bun;
    std::string patty;
    std::string sauce;
    bool cheese;
    bool lettuce;
    bool tomato;
    bool onion;

public:
    Burger(std::string bun, std::string patty, std::string sauce,
           bool cheese, bool lettuce, bool tomato, bool onion)
        : bun(std::move(bun)), patty(std::move(patty)), sauce(std::move(sauce)),
          cheese(cheese), lettuce(lettuce), tomato(tomato), onion(onion) {}

    void show() const {
        std::cout << "Bun: " << bun << "\n";
        std::cout << "Patty: " << patty << "\n";
        std::cout << "Sauce: " << sauce << "\n";
        std::cout << std::boolalpha
                  << "Cheese: " << cheese << ", Lettuce: " << lettuce
                  << ", Tomato: " << tomato << ", Onion: " << onion << "\n";
    }
};

int main() {
    Burger classic("Sesame", "Beef", "Ketchup", true, true, false, true);
    classic.show();

    std::cout << "\n";

    Burger empty("", "", "", false, false, false, false);
    empty.show();

    return 0;
}
