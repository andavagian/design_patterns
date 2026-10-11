#include <iostream>
#include <memory>
#include <string>

class Button {
public:
    virtual ~Button() = default;
    virtual void render() const = 0;
};

class Checkbox {
public:
    virtual ~Checkbox() = default;
    virtual void render() const = 0;
};

class TextField {
public:
    virtual ~TextField() = default;
    virtual void render() const = 0;
};

class LightButton : public Button {
public:
    void render() const override { std::cout << "Light button\n"; }
};
class LightCheckbox : public Checkbox {
public:
    void render() const override { std::cout << "Light checkbox\n"; }
};
class LightTextField : public TextField {
public:
    void render() const override { std::cout << "Light text field\n"; }
};

class DarkButton : public Button {
public:
    void render() const override { std::cout << "Dark button\n"; }
};
class DarkCheckbox : public Checkbox {
public:
    void render() const override { std::cout << "Dark checkbox\n"; }
};
class DarkTextField : public TextField {
public:
    void render() const override { std::cout << "Dark text field\n"; }
};

class UIFactory {
public:
    virtual ~UIFactory() = default;
    virtual std::unique_ptr<Button> createButton() const = 0;
    virtual std::unique_ptr<Checkbox> createCheckbox() const = 0;
    virtual std::unique_ptr<TextField> createTextField() const = 0;
};

class LightThemeFactory : public UIFactory {
public:
    std::unique_ptr<Button> createButton() const override {
        return std::make_unique<LightButton>();
    }
    std::unique_ptr<Checkbox> createCheckbox() const override {
        return std::make_unique<LightCheckbox>();
    }
    std::unique_ptr<TextField> createTextField() const override {
        return std::make_unique<LightTextField>();
    }
};

class DarkThemeFactory : public UIFactory {
public:
    std::unique_ptr<Button> createButton() const override {
        return std::make_unique<DarkButton>();
    }
    std::unique_ptr<Checkbox> createCheckbox() const override {
        return std::make_unique<DarkCheckbox>();
    }
    std::unique_ptr<TextField> createTextField() const override {
        return std::make_unique<DarkTextField>();
    }
};

void renderLoginForm(const UIFactory& factory) {
    auto field = factory.createTextField();
    auto checkbox = factory.createCheckbox();
    auto button = factory.createButton();

    field->render();
    checkbox->render();
    button->render();
}

int main() {
    std::cout << "Light theme:\n";
    LightThemeFactory light;
    renderLoginForm(light);

    std::cout << "\nDark theme:\n";
    DarkThemeFactory dark;
    renderLoginForm(dark);

    return 0;
}
