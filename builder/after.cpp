#include <iostream>
#include <string>

class Computer {
public:
    class Builder;

private:
    std::string cpu;
    int ramGb;

    int storageGb = 256;
    std::string gpu = "Integrated";
    bool wifi = false;
    bool bluetooth = false;

    Computer(std::string cpu, int ramGb) : cpu(std::move(cpu)), ramGb(ramGb) {}

public:
    void showSpecs() const {
        std::cout << "CPU: " << cpu << "\n";
        std::cout << "RAM: " << ramGb << " GB\n";
        std::cout << "Storage: " << storageGb << " GB\n";
        std::cout << "GPU: " << gpu << "\n";
        std::cout << "WiFi: " << wifi << ", Bluetooth: " << bluetooth << "\n";
    }
};

class Computer::Builder {
private:
    Computer computer;

public:
    Builder(const std::string& cpu, int ramGb) : computer(cpu, ramGb) {}

    Builder& setStorage(int storageGb) {
        computer.storageGb = storageGb;
        return *this;
    }
    Builder& setGpu(const std::string& gpu) {
        computer.gpu = gpu;
        return *this;
    }
    Builder& addWifi() {
        computer.wifi = true;
        return *this;
    }
    Builder& addBluetooth() {
        computer.bluetooth = true;
        return *this;
    }
    Computer build() {
        return computer;
    }
};

int main() {
    Computer office = Computer::Builder("Intel i5", 16)
        .setStorage(512)
        .addWifi()
        .build();

    Computer gaming = Computer::Builder("AMD Ryzen 9", 32)
        .setStorage(2000)
        .setGpu("RTX 4080")
        .addWifi()
        .addBluetooth()
        .build();

    std::cout << "--- Office PC ---\n";
    office.showSpecs();

    std::cout << "\n--- Gaming PC ---\n";
    gaming.showSpecs();

    return 0;
}
