#include <iostream>

class Shape {
    public:
        Shape() {
            std::cout << "Shape created." << std::endl;
        }

        virtual ~Shape() {
            std::cout << "Shape destroyed." << std::endl;
        }

        virtual void draw() const = 0;

        virtual void info() const {
            std::cout << "This is a shape." << std::endl;
        }
};


class Circle: public Shape {
    public:     
        Circle() {
            std::cout << "Circle created." << std::endl;
        }

        ~Circle() {
            std::cout << "Circle destroyed." << std::endl;
        }

        void draw() const override {
            std::cout << "Drawing a circle." << std::endl;
        }

        void info() const override {
            std::cout << "This is a circle." << std::endl;
        }
};


class Square: public Shape {
    public:
        Square() {
            std::cout << "Square created." << std::endl;
        }

        ~Square() {
            std::cout << "Square destroyed." << std::endl;
        }

        void draw() const override {
            std::cout << "Drawing a square." << std::endl;
        }

        void info() const override {
            std::cout << "This is a square." << std::endl;
        }
};

int main() {
    Shape* shape1 = new Circle();
    Shape* shape2 = new Square();

    shape1->draw();
    shape1->info();

    shape2->draw();
    shape2->info();

    delete shape1;
    delete shape2;

    return 0;
}