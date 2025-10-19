/*
 * Program: Print table of N, 10*N, 100*N, 1000*N
 * ----------------------------------------------
 * Demonstrates using '\t' (tab) to align columns.
 */

#include <stdio.h>

int main(void) {

    int n = 1; // start from 1

    printf("N\t10*N\t100*N\t1000*N\n");
    printf("-----------------------------------\n");

    while (n <= 10) {
        printf("%d\t%d\t%d\t%d\n", n, n * 10, n * 100, n * 1000); // the tab character '\t' creates spacing, makes the output look like a table
        n++;
    }

    return 0;
}
