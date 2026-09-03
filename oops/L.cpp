#include <iostream>
using namespace std;

// Common base that only assumes things have an area

class Shape
{
public:
    virtual ~Shape() {}
    virtual int getArea() const = 0;
};

class Rectangle : public Shape
{
private:
    int width;
    int height;

public:
    Rectangle(int w, int h) : width(w), height(h) {}
    void setWidth(int w) { width = w; }
    void setHeight(int h) { height = h; };
    int getArea() const override
    {
        return width * height;
    }
};

class Square : public Shape
{
private:
    int side;

public:
    Square(int s) : side(s) {}
    void setSide(int s) { side = s; }
    int getArea() const override
    {
        return side * side;
    }
};

// Client function accepts any Shape safely
void printArea(const Shape& shape) {
    std::cout << "Shape Area: " << shape.getArea() << "\n";
}

int main() {
    Rectangle rect(3, 4);
    Square sq(5);

    printArea(rect); // Output: Shape Area: 12
    printArea(sq);   // Output: Shape Area: 25

    return 0;
}