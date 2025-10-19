/*
 * Program: Find the sum of all elements in an integer array
 * ----------------------------------------------------------
 * Demonstrates arrays, loops, and user-defined functions.
 * 
 * The array is a very simple data structure -- a contiguous block of memory (memory spaces stored right next to each other)
 */

#include <stdio.h>

#define MAX 100

// Function to calculate sum of array elements
int mySumArray(int arr[], int length) { // initialised an array that takes in integers, then length.
    int total = 0;

    for (int i = 0; i < length; i++) // This for loop allows for the iteration of the array
        total += arr[i];

    return total;
}

int main(void) {

    int arr[MAX], n;

    printf("Input the number of elements in the array: ");
    scanf("%d", &n);

    printf("Input %d elements:\n", n);
    for (int i = 0; i < n; i++) { // This loop iterates through input elements. 
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    int sum = mySumArray(arr, n);
    printf("\nSum of all elements = %d\n", sum);

    return 0;
}

