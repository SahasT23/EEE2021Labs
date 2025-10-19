/*
 * Program: Determine if an integer is even or odd
 * -----------------------------------------------
 * The modulus operator (%) gives the remainder after division.
 * If number % 2 == 0 -> number is even, otherwise it's odd.
 * 
 * We want to keep it as simple as possible, because we could create a separate function
 * to determine even/odd, but that would be overcomplicating things for this exercise. Remember to keep it simple
 */

#include <stdio.h>

int main(void) {

    int num, remainder;

    printf("Enter an integer: ");
    scanf("%d", &num);

    remainder = num % 2; // Find remainder when dividing by 2

    if (remainder == 0)
        printf("The number is even.\n");
    else
        printf("The number is odd.\n");

    return 0;
}
