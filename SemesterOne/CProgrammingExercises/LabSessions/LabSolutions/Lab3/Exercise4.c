/*
 * Program: Check if three integers are equal
 * ------------------------------------------
 * Uses logical OR (||) and inequality (!=) operators.
 * logical OR works by evaluating to true if at least one condition is true.
 * If any pair of numbers are not equal -> they are not all equal, making the program simple and efficient.
 */

#include <stdio.h>

int main(void) {

    int a, b, c;

    printf("Enter the first integer: ");
    scanf("%d", &a);
    printf("Enter the second integer: ");
    scanf("%d", &b);
    printf("Enter the third integer: ");
    scanf("%d", &c);

    // If any pair of numbers are not equal → they are not all equal
    if ((a != b) || (b != c)) // This works because if at least one of these conditions is true, then not all numbers are equal, so we can print "not equal".
        printf("They are not equal.\n");
    else
        printf("They are equal.\n");

    return 0;
}
