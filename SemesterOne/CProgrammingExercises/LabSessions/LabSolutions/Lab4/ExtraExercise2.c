/*
 * Program: Count number of digits in an integer
 * ---------------------------------------------
 * Uses division by 10 repeatedly until the number becomes 0.
 */

#include <stdio.h>

int main(void) {

    int n, count = 0;

    printf("Enter a positive integer: ");
    scanf("%d", &n);

    // Handle case where number is 0
    if (n == 0) // zero has 1 digit
        count = 1; // special case for 0
    else { // for positive integers
        while (n != 0) { // loop until n becomes 0
            n /= 10;  // remove last digit
            count++;  // increment counter
        }
    }

    printf("Number of digits: %d\n", count);
    return 0;
}
