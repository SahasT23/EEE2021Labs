/*
 * Program: Print numbers 1 to 10 on one line
 * ------------------------------------------
 * Uses a 'for' loop, which is ideal when the number of iterations is known.
 */

#include <stdio.h>

int main(void) {

    int i;

    // Start at 1, stop at 10, increment by 1 each time
    for (i = 1; i <= 10; i++) {
        printf("%d   ", i); // three spaces between numbers
    }

    printf("\n"); // move to next line after printing
    return 0;
}
