/*
 * Program: Identify if a character is a letter, digit, or special symbol
 * ---------------------------------------------------------------------
 * Based on ASCII values:
 *   - 'A'–'Z' → 65–90
 *   - 'a'–'z' → 97–122
 *   - '0'–'9' → 48–57
 */

#include <stdio.h>

int main(void) {

    char ch; // Variable to store user input

    printf("Enter any character: ");
    scanf(" %c", &ch);

    if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
        printf("'%c' is an alphabet letter.\n", ch);
    else if (ch >= '0' && ch <= '9')
        printf("'%c' is a digit.\n", ch);
    else
        printf("'%c' is a special character.\n", ch);

    return 0;
}
