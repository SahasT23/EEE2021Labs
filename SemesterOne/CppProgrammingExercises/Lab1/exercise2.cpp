#include <iostream>   // For std::cout and std::endl

// Function 1: Swaps by VALUE (no real effect outside function)
void swapByValue(int a, int b) {
    int t = a;  // Store a temporarily
    a = b;      // Assign b to a
    b = t;      // Assign temporary value to b
    // Changes only affect local copies, not the originals
}

// Function 2: Swaps by POINTER (changes actual variables via memory addresses)
void swapByPointer(int* a, int* b) {
    int t = *a;  // Dereference pointer a to get value
    *a = *b;     // Replace value at address of a
    *b = t;      // Replace value at address of b
}

// Function 3: Swaps by REFERENCE (changes affect original variables directly)
void swapByReference(int& a, int& b) {
    int t = a;  // Store a temporarily
    a = b;      // Swap values
    b = t;
}

int main() {
    int a = 5, b = 10;   // Initialize two integers

    std::cout << "Original values: a = " << a << ", b = " << b << std::endl;

    // Try swapping by VALUE (no actual effect)
    swapByValue(a, b);
    std::cout << "After swapByValue: a = " << a << ", b = " << b << std::endl;

    // Try swapping by POINTER (real swap)
    swapByPointer(&a, &b);
    std::cout << "After swapByPointer: a = " << a << ", b = " << b << std::endl;

    // Try swapping by REFERENCE (real swap again)
    swapByReference(a, b);
    std::cout << "After swapByReference: a = " << a << ", b = " << b << std::endl;

    return 0;
}
