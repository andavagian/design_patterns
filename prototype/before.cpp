#include <iostream>
#include <string>
#include <vector>

class Shape {
public:
    virtual ~Shape() = default;
    virtual void draw() const = 0;
};

class Circle : public Shape {
public:
    int radius;
    std::string color;

    Circle(int radius, std::string color) : radius(radius), color(std::move(color)) {}

    void draw() const override {
        std::cout << "Circle (radius: " << radius << ", color: " << color << ")\n";
    }
};

class Rectangle : public Shape {
public:
    int width, height;
    std::string color;

    Rectangle(int width, int height, std::string color)
        : width(width), height(height), color(std::move(color)) {}

    void draw() const override {
        std::cout << "Rectangle (" << width << "x" << height << ", color: " << color << ")\n";
    }
};

int main() {
    std::vector<Shape*> shapes = { new Circle(10, "Red"), new Rectangle(4, 6, "Blue") };
    std::vector<Shape*> copies;

    for (Shape* shape : shapes) {
        if (auto* c = dynamic_cast<Circle*>(shape)) {
            copies.push_back(new Circle(c->radius, c->color));
        } else if (auto* r = dynamic_cast<Rectangle*>(shape)) {
            copies.push_back(new Rectangle(r->width, r->height, r->color));
        }
    }

    for (Shape* copy : copies) copy->draw();

    for (Shape* s : shapes) delete s;
    for (Shape* c : copies) delete c;

    return 0;
}
