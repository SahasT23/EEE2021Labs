/*
 * Program: Sort a string in ascending (alphabetical) order
 * --------------------------------------------------------
 * Uses a simple selection sort algorithm to rearrange characters.
 */

#include <stdio.h>
#include <string.h>

#define MAX 100

// Function to sort characters (Selection Sort)
void myStringSort(char str[], int size) {

    for (int i = 0; i < size - 1; i++) { // this for loop selects each character, then finds the smallest character from the remaining string - 1
        int minIndex = i;

        // Find smallest character from remaining string
        for (int j = i + 1; j < size; j++) { // this for loop finds the index of the smallest character, so it is a nested loop
            if (str[j] < str[minIndex]) // this if statement compares characters, then updates minIndex if a smaller character is found
                minIndex = j; // Update index of smallest character
        }

        // Swap characters
        char temp = str[i]; // So we swap the smallest character with the character at index i, starting from 0
        str[i] = str[minIndex]; // this is done until the whole string is sorted
        str[minIndex] = temp; // Swap complete
    }
}


int main(void) {

    char str[MAX];
    printf("Sort a string array in ascending order:\n");
    printf("----------------------------------------\n");
    printf("Input the string: ");
    fgets(str, MAX, stdin);

    int length = strlen(str);

    // Remove newline character if present
    if (str[length - 1] == '\n') { 
        str[length - 1] = '\0';
        length--;
    }

    myStringSort(str, length);

    printf("After sorting, the string appears as: %s\n", str);
    return 0;
}
