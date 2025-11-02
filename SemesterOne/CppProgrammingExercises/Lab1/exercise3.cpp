#include <iostream>   // For input/output

int main() {
    // Infinite FOR loop (prints 42 forever)
    // Uncomment to test (press Ctrl + C to stop)
    // for(;;)
    //     std::cout << 42 << std::endl;

    // Infinite WHILE loop (prints 42 forever)
    // Uncomment to test
    // while(true)
    //     std::cout << 42 << std::endl;

    // Factorial using infinite loop with break statement
    int n;  // Number input from user
    std::cout << "Enter a number to find factorial: ";
    std::cin >> n;  // Take user input

    long long factorial = 1;  // Use long long for large numbers
    int i = 1;                // Initialize counter

    // Infinite loop that stops when i > n
    while (true) {
        factorial *= i;  // Multiply by counter
        i++;              // Increment counter

        // Break when we have multiplied up to n
        if (i > n) break;
    }

    // Print the result
    std::cout << "Factorial of " << n << " = " << factorial << std::endl;

    return 0;
}
