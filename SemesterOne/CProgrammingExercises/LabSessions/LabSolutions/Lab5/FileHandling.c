/*
 * Program: Search for a keyword in a text file
 * --------------------------------------------
 * Reads each line of a file and checks if the search
 * string is contained in that line.
 * 
 * Demonstrates:
 *  - File I/O using fopen(), fgets(), fclose()
 *  - Custom substring matching function
 */

#include <stdio.h>
#include <ctype.h>  // for toupper()

#define MAX 100 // Macro for maximum keyword length.

// Function to check if input string exists inside source string
int match(const char source[], const char input[]) {
    int i = 0, j = 0;

    while (source[i] != '\0') {
        int start = i;
        while (toupper(source[start]) == toupper(input[j]) && input[j] != '\0') { // I will add some better explanations for this.
            start++;
            j++;
        }

        if (input[j] == '\0') // found complete match
            return 1;

        i++;
        j = 0; // reset for next attempt
    }
    return 0; // not found
}

int main(void) {

    FILE *f = fopen("modules.txt", "r"); // open file in read mode (refer to Notes Set III (my notes))
    if (f == NULL) {
        printf("Error: cannot open file.\n"); // error checking, helps you when you're solving issues.
        return 1;
    }

    char source[MAX], input[MAX];
    int matches = 0;

    printf("Enter a search string: ");
    scanf("%s", input);

    // Read file line by line
    while (fgets(source, MAX, f)) {
        if (match(source, input)) {
            printf("%s", source);
            matches++;
        }
    }

    printf("\nNumber of matches: %d\n", matches);
    fclose(f);

    return 0;
}
