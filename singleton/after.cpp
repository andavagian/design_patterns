#include <iostream>
#include <string>

class AppConfig {
private:
    std::string language = "en";

    AppConfig() {
        std::cout << "AppConfig created\n";
    }

public:
    AppConfig(const AppConfig&) = delete;
    AppConfig& operator=(const AppConfig&) = delete;

    static AppConfig& getInstance() {
        static AppConfig instance;
        return instance;
    }

    void setLanguage(const std::string& lang) { language = lang; }
    std::string getLanguage() const { return language; }
};

int main() {
    AppConfig& config1 = AppConfig::getInstance();
    AppConfig& config2 = AppConfig::getInstance();

    config1.setLanguage("hy");

    std::cout << "config1 language: " << config1.getLanguage() << "\n";
    std::cout << "config2 language: " << config2.getLanguage() << "\n";
    std::cout << "Same object: " << (&config1 == &config2) << "\n";

    return 0;
}
