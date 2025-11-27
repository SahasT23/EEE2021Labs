
#include <iostream>
#include <cstring>

/*
 * =============================================================
 * LAB 3 - PROBLEM 4: MYSTRING CLASS (COPY & MOVE CONSTRUCTORS)
 * =============================================================
 * THEORY:
 * A move constructor allows efficient transfer of resources (like heap memory)
 * from one object to another without deep copying. It's part of modern C++'s
 * "Rule of Five" for resource-managing classes.
 */

class MyString {
private:
    char* data;

public:
    // Default constructor
    MyString() {
        data = new char[1];
        data[0] = '\0';
    }

    // Parameterised constructor
    MyString(const char* str) {
        data = new char[strlen(str) + 1];
        strcpy(data, str);
    }

    // Copy constructor (deep copy)
    MyString(const MyString& other) {
        data = new char[strlen(other.data) + 1];
        strcpy(data, other.data);
    }

    // Move constructor (steals ownership)
    MyString(MyString&& other) noexcept { // && means rvalue reference. rvalue references can bind to temporary objects (rvalues) that are about to be destroyed.
        data = other.data;
        other.data = nullptr;
    }

    void display() const {
        std::cout << (data ? data : "(null)") << std::endl;
    }

    ~MyString() {
        delete[] data;
    }
};

int main() {
    MyString s1("Hello");
    MyString s2 = s1; // Copy constructor
    MyString s3 = MyString("World"); // Move constructor

    std::cout << "s1: "; s1.display();
    std::cout << "s2: "; s2.display();
    std::cout << "s3: "; s3.display();

    return 0;
}
