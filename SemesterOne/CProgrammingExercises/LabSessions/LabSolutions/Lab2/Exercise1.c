/*
 * Program: Calculate the product of three integers
 * -----------------------------------------------
 * This simple program takes three integers as input from the user,
 * multiplies them together, and prints the result.
 * 
 * Concepts used:
 *  - printf() and scanf() for input/output
 *  - integer variables
 *  - basic arithmetic operator (*)
 */

#include <stdio.h> // Standard Input/Output library (this essentially allows us to use printf and scanf and lots of other functions rather than having to write them ourselves)

int main() { // Main function - execution starts here, compiler looks for this function to start running the program. Without it, the program won't run.

    // Step 1: Declare integer variables to store input and result. Can declare multiple variables of the same type in one line separated by commas, saves time and space.
    int x, y, z, result;

    // Step 2: Prompt user and read input values
    printf("Enter the first integer: ");
    scanf("%d", &x); // &x means "store the input value in the variable x". "%d" is a format specifier for integers.

    printf("Enter the second integer: ");
    scanf("%d", &y);

    printf("Enter the third integer: ");
    scanf("%d", &z);

    // Step 3: Compute the product using multiplication operator (*), which is provided by C language for multiplying numbers.
    result = x * y * z;

    // Step 4: Display the result
    printf("The product is: %d\n", result);

    // Return 0 means the program ended successfully. the main function should always return an integer.
    return 0;
}
