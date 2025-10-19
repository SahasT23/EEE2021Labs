/*
 * Program: Calculate the sum of integers from 1 to n
 * --------------------------------------------------
 * Steps:
 *  1. Ask the user for a positive integer n.
 *  2. If n is not positive, ask again using a do…while loop.
 *  3. Use a while loop to add up all integers from 1 to n.
 *  4. Display the result.
 * 
 * Demonstrates:
 * - Input validation using do…while loop
 * - Iteration using while loop
 * - Basic arithmetic operations
 * Note: This program assumes the user inputs valid integers. You can add extra error handling if desired.
 */

#include <stdio.h>

int main(void) {

    int n, i = 1, sum = 0; // As they are all of type integer, we can declare them together.

    // Step 1: Ensure input is positive
    do {
        printf("Enter a positive integer: ");
        scanf("%d", &n);

        if (n <= 0)
            printf("Error: please enter a positive number!\n");
    } while (n <= 0); // Repeat if invalid input

    // Step 2: Calculate sum using while loop
    while (i <= n) {
        sum += i; // same as sum = sum + i
        i++; // Increment i by 1. ++i is different because it increments before use.
    }

    printf("Sum = %d\n", sum);
    return 0;
}
