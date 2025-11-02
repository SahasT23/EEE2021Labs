
#include <iostream>

/*
 * =============================================================
 * LAB 3 - PROBLEM 9: OVERLOAD '<<' OPERATOR (TIME CLASS)
 * =============================================================
 * THEORY:
 * Overloading the output operator (<<) allows custom printing
 * of user-defined types directly with std::cout.
 */

class Time {
private:
    int hours;
    int minutes;

public:
    Time(int h = 0, int m = 0) : hours(h), minutes(m) {}

    friend std::ostream& operator<<(std::ostream& os, const Time& t) {
        os << (t.hours < 10 ? "0" : "") << t.hours << ":"
           << (t.minutes < 10 ? "0" : "") << t.minutes;
        return os;
    }
};

int main() {
    Time t1(9, 5), t2(14, 30);
    std::cout << "Time 1: " << t1 << "\nTime 2: " << t2 << std::endl;
    return 0;
}
