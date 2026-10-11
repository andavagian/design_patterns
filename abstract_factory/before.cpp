#include <iostream>
#include <string>

class LightButton {
public:
    void render() const { std::cout << "Light button\n"; }
};
class LightCheckbox {
public:
    void render() const { std::cout << "Light checkbox\n"; }
};

class DarkButton {
public:
    void render() const { std::cout << "Dark button\n"; }
};
class DarkCheckbox {
public:
    void render() const { std::cout << "Dark checkbox\n"; }
};

int main() {
    std::string theme = "dark";

    if (theme == "light") {
        LightButton button;
        LightCheckbox checkbox;
        button.render();
        checkbox.render();
    } else {
        DarkButton button;
        LightCheckbox checkbox;
        button.render();
        checkbox.render();
    }

    return 0;
}
