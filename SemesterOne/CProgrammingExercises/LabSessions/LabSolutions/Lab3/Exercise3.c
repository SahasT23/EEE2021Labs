/*
 * Program: Check if a < b < c
 * ----------------------------
 * Demonstrates nested 'if' statements.
 * We must check 'a < b' first, then check 'b < c'.
 */

#include <stdio.h>

int main(void) {

    int a, b, c;

    printf("Enter first number: ");
    scanf("%d", &a);
    printf("Enter second number: ");
    scanf("%d", &b);
    printf("Enter third number: ");
    scanf("%d", &c);

    if (a < b) { // checking first condition
        if (b < c) // checking second condition. It is done this way because C does not support chained comparisons, so we can't do it all in one step.
            printf("True\n");
        else
            printf("False\n");
    } else {
        printf("False\n");
    }

    return 0;
}

/* 
 * Explanation:
 * 1. We first check if 'a' is less than 'b'.
 * 2. If true, we then check if 'b' is less than 'c'.
 * 3. If both conditions are true, we print "True".
 * 4. If either condition fails, we print "False".
 * C does not allow chained comparisons like a < b < c directly, because a < b produces either 0 (false) or 1 (true), which is then compared to c.
 */