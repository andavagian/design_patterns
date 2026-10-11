#include <iostream>
#include <string>

class AppConfig {
private:
    std::string language = "en";

public:
    AppConfig() {
        std::cout << "AppConfig created\n";
    }

    void setLanguage(const std::string& lang) { language = lang; }
    std::string getLanguage() const { return language; }
};

int main() {
    AppConfig config1;
    AppConfig config2;

    config1.setLanguage("hy");

    std::cout << "config1 language: " << config1.getLanguage() << "\n";
    std::cout << "config2 language: " << config2.getLanguage() << "\n";
    std::cout << "Same object: " << (&config1 == &config2) << "\n";

    return 0;
}
