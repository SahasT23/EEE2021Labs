/*
 * Program: Find the square of any number using a function
 * --------------------------------------------------------
 * Demonstrates:
 *  - Function declaration, definition, and calling
 *  - Passing values as arguments and returning results
 */

#include <stdio.h>

// Function definition
double square(double num) {
    // Local variable used to hold calculation
    double sqr = num * num;
    return sqr;
}

/**
 * I know this is a simple program, but it demonstrates the key concepts of functions in C.
 * You can expand this by adding more functions for other mathematical operations.
 * We want to keep the main function clean and focused on high-level logic, and I like to keep the functions above main for better readability.
 * The compiler reads from top to bottom, so defining functions before main ensures they are recognized when called, and when it is compiled, it all works seamlessly.
 */

int main(void) {

    double num, result;

    printf("Enter a number to square: ");
    scanf("%lf", &num);

    // Call the function and store result
    result = square(num);

    printf("The square of %.2lf is %.2lf\n", num, result);
    return 0;
}
