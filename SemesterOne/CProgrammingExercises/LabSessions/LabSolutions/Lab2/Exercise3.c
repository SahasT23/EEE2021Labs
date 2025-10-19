/*
 * Program: Split a two-digit number into tens and units digits
 * ------------------------------------------------------------
 * This program demonstrates how to use:
 *  - integer division (/) to get the tens digit
 *  - modulus operator (%) to get the ones (units) digit
 *
 * Example: for number 42 -> tens = 4, units = 2
 */

#include <stdio.h>

int main(void) { // Can use int main() as well. 

    int number, tens, units;

    printf("Enter a two-digit number: ");
    scanf("%d", &number);

    // Extract digits
    tens = number / 10;  // Integer division gives the tens digit
    units = number % 10; // Modulus gives the last (units) digit

    printf("Tens digit: %d, Units digit: %d\n", tens, units);

    return 0;
}
