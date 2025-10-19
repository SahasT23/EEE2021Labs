/*
 * Program: Display memory addresses of array elements
 * ---------------------------------------------------
 * Demonstrates how arrays are stored in contiguous memory.
 * a pointer very simply, tells you where something else is.
 * Imagine I was giving you guys sweets/pizza, I could do one of two things:
 * 1. Go out and hand it to you one by one, or 
 * 2. Tell you guys where the food is and you can go and pick it up. 
 * Now, if I was the compiler, which one would be easier for me?
 * It is much easier if I tell you guys where to go and pick up the food. The same concept applies to pointers here. 
 */

#include <stdio.h>

int main(void) {

    int values[7] = {11, 22, 33, 44, 55, 66, 77};

    printf("Index | Value | Address\n");
    printf("------------------------\n");

    for (int i = 0; i < 7; i++) {
        // %p is the correct format specifier for pointers (addresses)
        printf("%5d | %5d | %p\n", i, values[i], (void*)&values[i]);
    }

    return 0;
}
