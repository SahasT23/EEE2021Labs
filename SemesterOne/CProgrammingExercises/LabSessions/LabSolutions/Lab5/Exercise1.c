/*
 * Program: Find the length of a string without using strlen()
 * You will need some understanding of arrays for this exercise and how strings are represented in C.
 * ------------------------------------------------------------
 * We define our own function `myStringLength()` that counts
 * characters in a string until it reaches the null terminator '\0'.
 * Steps:
 *  1. Initialize a counter to zero.
 *  2. Loop through each character in the string until '\0' is encountered.
 *  3. Increment the counter for each character.
 *  4. Return the counter as the length of the string.
 * 
 * Note: We use fgets() to read the string safely, avoiding buffer overflow.
 * If you want, use the library function strlen() instead of writing your own function, then compare the two results and how much less code you have to write.
 */

#include <stdio.h>

#define MAX 100 // maximum string length (macro definition)

// Function to calculate string length manually
int myStringLength(const char str[]) {
    int count = 0;

    // Loop until we hit the null terminator (the null character marks the end of a string in C, so we have to consider an extra character)
    while (str[count] != '\0') {
        count++;
    }

    // fgets() includes '\n' if user presses Enter, so we can adjust
    if (str[count - 1] == '\n')
        count--; // counting down by 1.

    return count;
}

int main(void) {

    char str[MAX]; // array to store input string

    printf("Find the length of a string:\n");
    printf("---------------------------------\n");
    printf("Input the string: ");
    fgets(str, MAX, stdin); // safer alternative to gets()

    int length = myStringLength(str);

    printf("Length of the string is: %d\n", length);
    return 0;
}
