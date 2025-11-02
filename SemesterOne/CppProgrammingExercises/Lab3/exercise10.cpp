
#include <iostream>

/*
 * =============================================================
 * LAB 3 - PROBLEM 10: OVERLOAD '++' OPERATOR (COUNTER CLASS)
 * =============================================================
 * THEORY:
 * Prefix ++: increments first, then returns new value.
 * Postfix ++: returns old value, then increments (requires dummy int).
 */

class Counter {
private:
    int count;

public:
    Counter(int c = 0) : count(c) {}

    // Prefix increment (++obj)
    Counter& operator++() {
        ++count;
        return *this;
    }

    // Postfix increment (obj++)
    Counter operator++(int) {
        Counter temp = *this;
        ++count;
        return temp;
    }

    void display() const {
        std::cout << "Count = " << count << std::endl;
    }
};

int main() {
    Counter c(5);
    ++c; // prefix
    c.display();

    c++; // postfix
    c.display();
    return 0;
}
