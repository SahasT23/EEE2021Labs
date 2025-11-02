
#include <iostream>

/*
 * =============================================================
 * LAB 3 - PROBLEM 3: COPY CONSTRUCTOR (DEEP COPY)
 * =============================================================
 * THEORY:
 * A copy constructor creates a new object as a copy of an existing one.
 * By default, C++ performs a shallow copy (copies pointer values only).
 * A DEEP COPY duplicates the data in new memory, preventing shared ownership.
 */

class DynamicArray {
private:
    int* data;
    int size;

public:
    // Constructor
    DynamicArray(int s) : size(s) {
        data = new int[size];
        for (int i = 0; i < size; i++)
            data[i] = i + 1;
    }

    // Deep Copy Constructor
    DynamicArray(const DynamicArray& other) {
        size = other.size;
        data = new int[size];
        for (int i = 0; i < size; i++)
            data[i] = other.data[i];
    }

    // Display function
    void display() const {
        for (int i = 0; i < size; i++)
            std::cout << data[i] << " ";
        std::cout << std::endl;
    }

    // Destructor
    ~DynamicArray() {
        delete[] data;
    }
};

int main() {
    DynamicArray arr1(5);
    std::cout << "Original array: ";
    arr1.display();

    DynamicArray arr2 = arr1; // Copy constructor invoked
    std::cout << "Copied array: ";
    arr2.display();

    return 0;
}
