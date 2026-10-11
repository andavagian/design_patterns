#include <iostream>
#include <memory>
#include <string>
#include <vector>

class Shape {
protected:
    std::string color;

public:
    explicit Shape(std::string color) : color(std::move(color)) {}
    virtual ~Shape() = default;

    void setColor(const std::string& newColor) { color = newColor; }

    virtual std::unique_ptr<Shape> clone() const = 0;
    virtual void draw() const = 0;
};

class Circle : public Shape {
private:
    int radius;

public:
    Circle(int radius, const std::string& color) : Shape(color), radius(radius) {}

    std::unique_ptr<Shape> clone() const override {
        return std::make_unique<Circle>(*this);
    }

    void draw() const override {
        std::cout << "Circle (radius: " << radius << ", color: " << color << ")\n";
    }
};

class Rectangle : public Shape {
private:
    int width, height;

public:
    Rectangle(int width, int height, const std::string& color)
        : Shape(color), width(width), height(height) {}

    std::unique_ptr<Shape> clone() const override {
        return std::make_unique<Rectangle>(*this);
    }

    void draw() const override {
        std::cout << "Rectangle (" << width << "x" << height << ", color: " << color << ")\n";
    }
};

int main() {
    std::vector<std::unique_ptr<Shape>> shapes;
    shapes.push_back(std::make_unique<Circle>(10, "Red"));
    shapes.push_back(std::make_unique<Rectangle>(4, 6, "Blue"));

    std::vector<std::unique_ptr<Shape>> copies;
    for (const auto& shape : shapes) {
        copies.push_back(shape->clone());
    }

    copies[0]->setColor("Green");

    std::cout << "--- Originals ---\n";
    for (const auto& shape : shapes) shape->draw();

    std::cout << "\n--- Clones ---\n";
    for (const auto& copy : copies) copy->draw();

    return 0;
}
