/*
 * Program: Final Student Marks Analyzer
 * -------------------------------------
 * Features:
 *  1. Input multiple marks (0–100)
 *  2. Display all entered marks
 *  3. Sort marks in ascending order
 *  4. Display sorted list
 *  5. Calculate and show average, highest, lowest
 *  6. Save results to a text file
 */

#include <stdio.h>

#define MAX 50

// Function declarations
void greetUser(void);
int enterMarks(float marks[]);
void displayMarks(float marks[], int count);
void sortMarks(float marks[], int count);
void calculateStats(float marks[], int count, float *avg, float *high, float *low);
void saveResults(float marks[], int count, float avg, float high, float low);

int main(void) {

    float marks[MAX], avg, high, low;
    int count;

    greetUser();
    count = enterMarks(marks);
    displayMarks(marks, count);
    sortMarks(marks, count);

    printf("\nSorted Marks:\n");
    displayMarks(marks, count);

    calculateStats(marks, count, &avg, &high, &low);

    printf("\nStatistics:\n");
    printf("Average = %.2f\nHighest = %.2f\nLowest = %.2f\n", avg, high, low);

    saveResults(marks, count, avg, high, low);
    printf("\nResults saved to 'results.txt'.\n");

    return 0;
}

// 1️⃣ Greet the user
void greetUser(void) {
    printf("======================================\n");
    printf(" Welcome to the Student Marks System!\n");
    printf("======================================\n\n");
}

// 2️⃣ Input marks with validation
int enterMarks(float marks[]) {
    int n;

    printf("Enter number of students (max %d): ", MAX);
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        do {
            printf("Enter mark for student %d (0–100): ", i + 1);
            scanf("%f", &marks[i]);
            if (marks[i] < 0 || marks[i] > 100)
                printf("Invalid mark! Please re-enter.\n");
        } while (marks[i] < 0 || marks[i] > 100);
    }
    return n;
}

// 3️⃣ Display marks
void displayMarks(float marks[], int count) {
    for (int i = 0; i < count; i++) {
        printf("Student %2d: %.2f\n", i + 1, marks[i]);
    }
}

// 4️⃣ Sort marks (ascending)
void sortMarks(float marks[], int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (marks[j] < marks[i]) {
                float temp = marks[i];
                marks[i] = marks[j];
                marks[j] = temp;
            }
        }
    }
}

// 5️⃣ Calculate statistics
void calculateStats(float marks[], int count, float *avg, float *high, float *low) {
    float sum = 0;
    *high = marks[0];
    *low = marks[0];

    for (int i = 0; i < count; i++) {
        sum += marks[i];
        if (marks[i] > *high) *high = marks[i];
        if (marks[i] < *low) *low = marks[i];
    }

    *avg = sum / count;
}

// 6️⃣ Save results to file
void saveResults(float marks[], int count, float avg, float high, float low) {
    FILE *file = fopen("results.txt", "w");
    if (file == NULL) {
        printf("Error: Could not save results!\n");
        return;
    }

    fprintf(file, "Sorted Marks:\n");
    for (int i = 0; i < count; i++) {
        fprintf(file, "Student %2d: %.2f\n", i + 1, marks[i]);
    }

    fprintf(file, "\nAverage: %.2f\nHighest: %.2f\nLowest: %.2f\n", avg, high, low);
    fclose(file);
}
