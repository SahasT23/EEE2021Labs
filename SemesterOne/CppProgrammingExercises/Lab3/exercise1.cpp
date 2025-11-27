
#include <iostream>

/*
 * =============================================================
 * LAB 3 - PROBLEM 1: CLASS DECLARATION (RECTANGLE)
 * =============================================================
 * THEORY:
 * A class is a user-defined data type that bundles data (attributes)
 * and functions (methods) together. The attributes are typically kept
 * private to enforce encapsulation (data hiding).
 *
 * In this example, we define a Rectangle class with private members:
 * - length
 * - width
 *
 * and public member functions to:
 * - set dimensions
 * - calculate area
 * - display area
 */

class Rectangle {
private:
    double length;
    double width;

public:
    void setDimensions(double l, double w) {
        length = l;
        width = w;
    }

    double calculateArea() const {
        return length * width;
    }

    void displayArea() const {
        std::cout << "Area of rectangle = " << calculateArea() << std::endl;
    }
};

int main() {
    Rectangle rect;
    rect.setDimensions(5.0, 3.0);
    rect.displayArea();
    return 0;
}
