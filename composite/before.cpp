#include <iostream>
#include <string>
#include <vector>

class File {
public:
    std::string name;
    int size;

    File(std::string name, int size) : name(std::move(name)), size(size) {}
};

class Folder {
public:
    std::string name;
    std::vector<File> files;
    std::vector<Folder> subFolders;

    explicit Folder(std::string name) : name(std::move(name)) {}

    int getSize() const {
        int total = 0;
        for (const auto& file : files) total += file.size;
        for (const auto& folder : subFolders) total += folder.getSize();
        return total;
    }
};

int main() {
    Folder docs("Documents");
    docs.files.push_back(File("cv.pdf", 120));
    docs.files.push_back(File("notes.txt", 5));

    Folder root("root");
    root.files.push_back(File("photo.png", 900));
    root.subFolders.push_back(docs);

    std::cout << "Total size: " << root.getSize() << " KB\n";

    return 0;
}
