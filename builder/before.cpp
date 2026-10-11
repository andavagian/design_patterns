#include <iostream>
#include <string>

class Computer {
private:
    std::string cpu;
    int ramGb;
    int storageGb;
    std::string gpu;
    bool wifi;
    bool bluetooth;

public:
    Computer(std::string cpu, int ramGb, int storageGb, std::string gpu, bool wifi, bool bluetooth)
        : cpu(std::move(cpu)), ramGb(ramGb), storageGb(storageGb),
          gpu(std::move(gpu)), wifi(wifi), bluetooth(bluetooth) {}

    void showSpecs() const {
        std::cout << "CPU: " << cpu << "\n";
        std::cout << "RAM: " << ramGb << " GB\n";
        std::cout << "Storage: " << storageGb << " GB\n";
        std::cout << "GPU: " << gpu << "\n";
        std::cout << "WiFi: " << wifi << ", Bluetooth: " << bluetooth << "\n";
    }
};

int main() {
    Computer office("Intel i5", 16, 512, "Integrated", true, false);
    office.showSpecs();

    return 0;
}
