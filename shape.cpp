#include <iostream>
#include <stdexcept>
#include <vector>

class Shape {
protected:
    int x;
    int y;

    Shape(int x, int y) : x(x), y(y)
    {
        if (x < 0 || y < 0)
        {
            throw std::invalid_argument("negative position");
        }
    }

public:
    virtual double area() = 0;  // classe abstraite

    void move(int dx, int dy)
    {
        x = x + dx;
        y = y + dy;
    }

    virtual ~Shape() {}
};

class Circle : public Shape
{
    int radius;

public: // toujours mettre en publique
    Circle(int x, int y, int r) : Shape(x, y), radius(r)
    {
        if (r < 0)
        {
            throw std::invalid_argument("negative radius");
        }
    }

    double area()
    {
        return 3.14159 * radius * radius;
    }
};


class Rectangle : public Shape
{
    int width;
    int height;

public:
    Rectangle(int x, int y, int w, int h)
        : Shape(x, y), width(w), height(h)
    {
        if (w < 0 || h < 0)
        {
            throw std::invalid_argument("negative size");
        }
    }

    double area()
    {
        return width * height;
    }
};

int main()
{
    try
    {
        Circle c1(100, 300, 56);
        Rectangle r1(100, 300, 56, 67);

        c1.move(8, 10);
        r1.move(8, 10);

        std::cout << c1.area() << std::endl;
        std::cout << r1.area() << std::endl;

        std::vector<Shape*> shapes;

        shapes.push_back(&c1);
        shapes.push_back(&r1);

        for (int i = 0; i < shapes.size(); i++)
        {
            std::cout << "Area: "
                      << shapes[i]->area() << std::endl;
        }

        Shape* ps1 = &c1;
        Shape& rs1 = c1;

        std::cout << "Via pointer: " << ps1->area() << std::endl;
        std::cout << "Via reference: " << rs1.area() << std::endl;
    }
    catch (std::invalid_argument &e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}