
#include <iostream>

/*
 * PROBLEM 1: CODE REFACTORING USING FUNCTIONS
 *
 * The goal: Take a longer program and split it into multiple smaller functions.
 * Each function should do exactly ONE thing (Single Responsibility Principle).
 * This improves readability, testing, and reuse.
 *
 * Example: A simple calculator that adds, subtracts, multiplies, and divides two numbers.
 */

// Function declarations (prototypes)
double add(double a, double b);
double subtract(double a, double b);
double multiply(double a, double b);
double divide(double a, double b);
void showMenu();
void performOperation();

int main() {
    std::cout << "=== SIMPLE CALCULATOR ===" << std::endl;
    performOperation(); // Main function that drives the calculator
    return 0;
}

// Function definitions

// Function to add two numbers
double add(double a, double b) {
    return a + b;
}

// Function to subtract two numbers
double subtract(double a, double b) {
    return a - b;
}

// Function to multiply two numbers
double multiply(double a, double b) {
    return a * b;
}

// Function to divide two numbers with error checking
double divide(double a, double b) {
    if (b == 0) {
        std::cout << "Error: Division by zero!" << std::endl;
        return 0;
    }
    return a / b;
}

// Function to display menu options
void showMenu() {
    std::cout << "\nChoose an operation:\n";
    std::cout << "1. Add\n";
    std::cout << "2. Subtract\n";
    std::cout << "3. Multiply\n";
    std::cout << "4. Divide\n";
    std::cout << "5. Exit\n";
}

// Function that performs the selected operation
void performOperation() {
    int choice;
    double num1, num2;

    while (true) {
        showMenu();
        std::cout << "Enter choice: ";
        std::cin >> choice;

        if (choice == 5) {
            std::cout << "Exiting calculator. Goodbye!" << std::endl;
            break;
        }

        std::cout << "Enter two numbers: ";
        std::cin >> num1 >> num2;

        double result = 0;
        switch (choice) {
            case 1: result = add(num1, num2); break;
            case 2: result = subtract(num1, num2); break;
            case 3: result = multiply(num1, num2); break;
            case 4: result = divide(num1, num2); break;
            default: std::cout << "Invalid choice!" << std::endl; continue;
        }

        std::cout << "Result: " << result << std::endl;
    }
}
