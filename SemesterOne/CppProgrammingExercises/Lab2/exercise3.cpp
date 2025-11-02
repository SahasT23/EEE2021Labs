
#include <iostream>
#include <cstdarg>  // For variadic functions (va_list, va_start, va_arg, va_end)

/*
 * PROBLEM 3: VARIADIC FUNCTION
 *
 * Write a function that accepts a variable number of arguments
 * and calculates their average. The number of arguments will be specified first.
 *
 * THEORY:
 *  - Variadic functions allow functions with variable-length argument lists.
 *  - The <cstdarg> library provides macros to handle them:
 *       va_list: holds the information needed to retrieve arguments
 *       va_start: initializes the va_list
 *       va_arg: fetches the next argument
 *       va_end: cleans up
 */

double average(int count, ...) {
    va_list args;
    va_start(args, count);  // Initialize argument list

    double sum = 0;
    for (int i = 0; i < count; i++) {
        double num = va_arg(args, double);  // Retrieve argument (must match type)
        sum += num;
    }

    va_end(args);  // Clean up
    return sum / count;
}

int main() {
    std::cout << "Average of 3 numbers (2.0, 3.5, 4.5): " << average(3, 2.0, 3.5, 4.5) << std::endl;
    std::cout << "Average of 5 numbers (1, 2, 3, 4, 5): " << average(5, 1.0, 2.0, 3.0, 4.0, 5.0) << std::endl;
    return 0;
}
