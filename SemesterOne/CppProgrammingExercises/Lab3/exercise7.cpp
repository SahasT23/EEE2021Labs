
#include <iostream>

/*
 * =============================================================
 * LAB 3 - PROBLEM 7: OVERLOAD '+' OPERATOR (COMPLEX NUMBERS)
 * =============================================================
 * THEORY:
 * Operator overloading allows defining custom behavior for
 * built-in operators (e.g., +, -, ==) for user-defined classes.
 */

class Complex {
private:
    double real;
    double imag;

public:
    Complex() : real(0), imag(0) {}
    Complex(double r, double i) : real(r), imag(i) {}

    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }

    void display() const {
        std::cout << real << " + " << imag << "i\n";
    }
};

int main() {
    Complex c1(3, 4), c2(1, 2);
    Complex result = c1 + c2;
    std::cout << "Result: ";
    result.display();
    return 0;
}
