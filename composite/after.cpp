#include <iostream>
#include <memory>
#include <string>
#include <vector>

class FileSystemItem {
public:
    virtual ~FileSystemItem() = default;
    virtual int getSize() const = 0;
    virtual void print(int indent = 0) const = 0;
};

class File : public FileSystemItem {
private:
    std::string name;
    int size;

public:
    File(std::string name, int size) : name(std::move(name)), size(size) {}

    int getSize() const override { return size; }

    void print(int indent = 0) const override {
        std::cout << std::string(indent, ' ') << name << " (" << size << " KB)\n";
    }
};

class Folder : public FileSystemItem {
private:
    std::string name;
    std::vector<std::unique_ptr<FileSystemItem>> items;

public:
    explicit Folder(std::string name) : name(std::move(name)) {}

    void add(std::unique_ptr<FileSystemItem> item) {
        items.push_back(std::move(item));
    }

    int getSize() const override {
        int total = 0;
        for (const auto& item : items) total += item->getSize();
        return total;
    }

    void print(int indent = 0) const override {
        std::cout << std::string(indent, ' ') << name << "/ [" << getSize() << " KB]\n";
        for (const auto& item : items) item->print(indent + 2);
    }
};

int main() {
    auto docs = std::make_unique<Folder>("Documents");
    docs->add(std::make_unique<File>("cv.pdf", 120));
    docs->add(std::make_unique<File>("notes.txt", 5));

    auto projects = std::make_unique<Folder>("Projects");
    projects->add(std::make_unique<File>("main.cpp", 12));
    projects->add(std::make_unique<File>("Makefile", 2));

    Folder root("root");
    root.add(std::move(docs));
    root.add(std::move(projects));
    root.add(std::make_unique<File>("photo.png", 900));

    root.print();
    std::cout << "Total size: " << root.getSize() << " KB\n";

    return 0;
}
