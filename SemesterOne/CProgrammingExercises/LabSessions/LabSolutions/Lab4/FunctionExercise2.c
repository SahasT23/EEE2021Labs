/*
 * Program: Student Marks Analysis Application
 * -------------------------------------------
 * Demonstrates:
 *  - Using functions to organize logic
 *  - Loops for multiple inputs
 *  - Calculating statistics: average, highest, lowest
 *  - Array usage for storing marks
  - Input validation
  - Clear and modular code structure
  * Each function handles a specific task for clarity and maintainability.
  * you can expand this program further by adding features like grade distribution, saving/loading from files, etc or by adding user input to determine the number of students.

 * Steps:
  *  1. Greet the user
  *  2. Input marks for a set number of students
  *  3. Display the entered marks
  *  4. Calculate and display statistics
  *  5. Exit the program
 */

#include <stdio.h>

// Function prototypes, you don't actually need these if functions are defined before main, but I am showing you how it would look.
void greetUser(void); // void type means no parameters and no return value
void enterMarks(float marks[], int count); // array parameter and count of elements
void displayMarks(float marks[], int count); // You can start to see a pattern here... 
void calculateStats(float marks[], int count);

int main(void) {

    const int NUM_STUDENTS = 5;
    float marks[NUM_STUDENTS];

    greetUser();
    enterMarks(marks, NUM_STUDENTS);
    displayMarks(marks, NUM_STUDENTS);
    calculateStats(marks, NUM_STUDENTS);

    return 0;
}

// 1 Greet the user
void greetUser(void) {
    printf("======================================\n");
    printf(" Welcome to the Student Marks Analyser\n");
    printf("======================================\n\n");
}

// 2️ Input marks using a loop
void enterMarks(float marks[], int count) {
    for (int i = 0; i < count; i++) {
        printf("Enter mark #%d (0–100): ", i + 1);
        scanf("%f", &marks[i]);

        // Validate input range
        if (marks[i] < 0 || marks[i] > 100) {
            printf("Invalid mark! Setting to 0.\n");
            marks[i] = 0;
        }
    }
}

// 3️ Display marks
void displayMarks(float marks[], int count) {
    printf("\nEntered Marks:\n");
    for (int i = 0; i < count; i++) {
        printf("Student %d: %.2f\n", i + 1, marks[i]);
    }
}

// 4️ Calculate and display statistics
void calculateStats(float marks[], int count) {
    float sum = 0, avg, highest, lowest;

    highest = lowest = marks[0];

    for (int i = 0; i < count; i++) {
        sum += marks[i];
        if (marks[i] > highest) highest = marks[i];
        if (marks[i] < lowest)  lowest = marks[i];
    }

    avg = sum / count;

    printf("\n--- Statistics ---\n");
    printf("Average Mark: %.2f\n", avg);
    printf("Highest Mark: %.2f\n", highest);
    printf("Lowest Mark:  %.2f\n", lowest);
}
