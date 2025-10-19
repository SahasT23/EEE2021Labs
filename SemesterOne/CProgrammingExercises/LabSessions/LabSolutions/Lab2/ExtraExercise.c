/*
 * Program: Greet the user and calculate their age
 * -----------------------------------------------
 * Demonstrates:
 *  - Reading strings (using scanf with %[^\n])
 *  - Date arithmetic (approximated)
 *  - Using multiple variables and formatted input
 */

#include <stdio.h>

int main(void) {

    char name[30]; // Stores user's name (as a string) (try to limit size to avoid overflow, here max 29 chars + null terminator, but also try going over to see what happens)
    int day, month, year; // Stores user's date of birth
    int currentDay, currentMonth, currentYear; // Stores current date
    int age;  // Stores calculated age. Kept it separate for clarity. 

    printf("What is your name? ");
    scanf(" %[^\n]", name); // Read a line including spaces until newline %[^\n] is the scanset format specifier
    // You can also use "%s" to read a single word (stops at whitespace)

    printf("Hello, %s!\n", name);

    printf("Enter your date of birth (dd/mm/yyyy): ");
    scanf("%d/%d/%d", &day, &month, &year);

    printf("Enter today's date (dd/mm/yyyy): ");
    scanf("%d/%d/%d", &currentDay, &currentMonth, &currentYear);

    // Approximate age calculation in years
    age = ((currentYear * 365 + currentMonth * 30 + currentDay)
         - (year * 365 + month * 30 + day)) / 365;

    printf("You are %d years old today!\n", age);

    return 0;
}
