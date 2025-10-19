/*
 * Program: Swap three numbers using call-by-reference
 * ----------------------------------------------------
 * Uses pointers so that changes made in the function
 * affect the original variables.
 * 
 * Refer to my notes for the full explanations and understanding of pointers. 
 */

#include <stdio.h>

// Function swaps values using pointer dereferencing
void swapNumbers(int *x, int *y, int *z) { // initialising pointers to memory locations for x, y and z.
    int temp = *y; // store value of y
    *y = *x;       // y = x
    *x = *z;       // x = z
    *z = temp;     // z = old y
}

int main(void) {

    int a, b, c;

    printf("Input the 1st value: ");
    scanf("%d", &a);
    printf("Input the 2nd value: ");
    scanf("%d", &b);
    printf("Input the 3rd value: ");
    scanf("%d", &c);

    printf("\nBefore swapping:\n");
    printf("a = %d, b = %d, c = %d\n", a, b, c); // Just outputting to a user 

    swapNumbers(&a, &b, &c); // passing addresses, dereferencing as well. 

    printf("\nAfter swapping:\n");
    printf("a = %d, b = %d, c = %d\n", a, b, c);

    return 0;
}
