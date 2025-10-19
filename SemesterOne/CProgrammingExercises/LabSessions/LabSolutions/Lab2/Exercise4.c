/*
 * Program: Calculate the average of two floating-point numbers
 * ------------------------------------------------------------
 * Floating-point numbers allow decimals.
 * The average is computed using: (num1 + num2) / 2
 */

#include <stdio.h>

int main(void) {

    float num1, num2, avg; // Declare floating-point variables, which is the point of this exercise.

    printf("Enter first number: ");
    scanf("%f", &num1);

    printf("Enter second number: ");
    scanf("%f", &num2);

    // Calculate the average, note the use of float variables to get decimal results. Try changing to int and see what happens.
    avg = (num1 + num2) / 2;

    // Print result with two decimal places using %.2f. Experiment with %.3f, %.4f etc, and see what happens.
    printf("Average of %.2f and %.2f is %.2f\n", num1, num2, avg);

    return 0;
}
