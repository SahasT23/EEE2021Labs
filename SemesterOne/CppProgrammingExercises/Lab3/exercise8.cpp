
#include <iostream>

/*
 * =============================================================
 * LAB 3 - PROBLEM 8: OVERLOAD '==' OPERATOR (POINT CLASS)
 * =============================================================
 * THEORY:
 * The '==' operator can be overloaded to compare object equality
 * based on internal data rather than memory addresses.
 */

class Point {
private:
    int x, y;

public:
    Point(int xVal = 0, int yVal = 0) : x(xVal), y(yVal) {}

    bool operator==(const Point& other) const {
        return (x == other.x && y == other.y);
    }

    void display() const {
        std::cout << "(" << x << ", " << y << ")\n";
    }
};

int main() {
    Point p1(2, 3), p2(2, 3), p3(4, 5);
    std::cout << "p1 == p2: " << (p1 == p2 ? "true" : "false") << std::endl;
    std::cout << "p1 == p3: " << (p1 == p3 ? "true" : "false") << std::endl;
    return 0;
}
