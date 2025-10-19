/*
 * Program: Simple Student Marks Manager (More advanced, I would come back to this later)
 * -------------------------------------
 * Demonstrates:
 *  - Function decomposition (enterMarks, displayMarks)
 *  - Conditional validation (0 <= mark <= 100)
 *  - Menu-driven system using switch-case
 * If you haven't used pointers yet, don't worry; they are included here for practice.
 * If you want to, instead of using pointers, you can modify the functions to return values directly.
 */

#include <stdio.h>

// Function to input marks with validation
void enterMarks(float *mark1, float *mark2) { // Pointers to store marks. You might not have seen pointers yet; they are used here for practice.
    printf("Enter first mark (0-100): ");
    scanf("%f", mark1);

    if (*mark1 < 0 || *mark1 > 100)
        printf("Invalid input! Marks should be between 0 and 100.\n");

    printf("Enter second mark (0-100): ");
    scanf("%f", mark2);

    if (*mark2 < 0 || *mark2 > 100)
        printf("Invalid input! Marks should be between 0 and 100.\n");
}

// Function to display marks and average
void displayMarks(float mark1, float mark2) {
    printf("\n--- Marks Summary ---\n");
    printf("Mark 1: %.2f\n", mark1);
    printf("Mark 2: %.2f\n", mark2);
    printf("Average: %.2f\n", (mark1 + mark2) / 2);
    printf("---------------------\n");
}

int main(void) {

    float mark1 = 0, mark2 = 0;
    int choice;

    do {
        printf("\nMenu:\n");
        printf("1. Enter marks\n");
        printf("2. Display marks\n");
        printf("3. Exit\n");
        printf("Choose an option (1-3): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                enterMarks(&mark1, &mark2);
                break;
            case 2:
                displayMarks(mark1, mark2);
                break;
            case 3:
                printf("Exiting program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please select 1, 2, or 3.\n");
        }
    } while (choice != 3);

    return 0;
}
