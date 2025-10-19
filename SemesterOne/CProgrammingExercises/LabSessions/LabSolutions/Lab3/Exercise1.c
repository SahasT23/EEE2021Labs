/*
 * Program: Compare two integers and display the largest one
 * ---------------------------------------------------------
 * Uses 'if' statements to compare values.
 * If both numbers are equal, prints a specific message.
 * Very simple, just a comparison exercise.
 */

#include <stdio.h>

int main(void) {

    int x, y;  // Variables to store the two numbers

    printf("Enter the first integer: ");
    scanf("%d", &x);

    printf("Enter the second integer: ");
    scanf("%d", &y);

    // == checks for equality
    if (x == y)
        printf("These numbers are equal.\n");

    // > checks if x is greater than y
    if (x > y)
        printf("%d is the largest.\n", x);

    // This last check only runs if y > x
    if (y > x)
        printf("%d is the largest.\n", y);

    return 0;
}
