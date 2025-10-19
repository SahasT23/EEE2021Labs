/*
 * Program: Calculate the sum and average of 10 numbers
 * ----------------------------------------------------
 * Uses a do…while loop to repeat input 10 times.
 * Steps:
 *  1. Initialize count and sum.
 * 2. In each iteration, read a number and add to sum.
 * 3. After loop, calculate average and display results.
 */

#include <stdio.h>

int main(void) {

    int count = 0, num, sum = 0;
    float average;

    do {
        printf("Enter integer #%d: ", count + 1);
        scanf("%d", &num);

        sum += num; // accumulate the sum
        count++;
    } while (count < 10); // run loop 10 times

    average = (float) sum / 10.0;

    printf("\nSum = %d\n", sum);
    printf("Average = %.2f\n", average);

    return 0;
}
