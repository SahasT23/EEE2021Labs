
#include <iostream>

/*
 * =============================================================
 * LAB 3 - PROBLEM 2: CONSTRUCTORS
 * =============================================================
 * THEORY:
 * A constructor is a special member function automatically called when
 * an object is created. It has the same name as the class and no return type.
 *
 * Types:
 *  - Default constructor: called when no parameters are passed.
 *  - Parameterized constructor: initializes object with specific values.
 */

class Rectangle {
private:
    double length;
    double width;

public:
    // Default constructor
    Rectangle() {
        length = 1.0;
        width = 1.0;
    }

    // Parameterized constructor
    Rectangle(double l, double w) {
        length = l;
        width = w;
    }

    double calculateArea() const {
        return length * width;
    }

    void displayArea() const {
        std::cout << "Rectangle area = " << calculateArea() << std::endl;
    }
};

int main() {
    Rectangle rect1;          // Default constructor
    Rectangle rect2(4.5, 2.0); // Parameterized constructor

    rect1.displayArea();
    rect2.displayArea();
    return 0;
}
