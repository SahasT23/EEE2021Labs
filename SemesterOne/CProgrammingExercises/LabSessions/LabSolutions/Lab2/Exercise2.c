/*
 * Program: Perform basic arithmetic on two integers
 * -------------------------------------------------
 * This program asks the user for two integers, then calculates:
 *  - their sum (+)
 *  - their product (*)
 *  - their quotient (/)
 *  - their remainder (%)
 *
 * The division (/) and modulus (%) operators are used for integer arithmetic.
 * Note: Integer division discards the decimal part.
 */

#include <stdio.h>

int main(void) { // void means this function does not take any parameters, also acceptable to write as int main(). We will look at parameters later in the course.

    int x, y;                   // input integers
    int sum, product, quotient, remainder; // computed results, better to keep these separate for clarity. 

    // Input two integers from user
    printf("Enter the first integer: ");
    scanf("%d", &x); // &x means "store the input value in the variable x". "%d" is a format specifier for integers.

    printf("Enter the second integer: ");
    scanf("%d", &y); // &y means "store the input value in the variable y". "%d" is a format specifier for integers.

    // Perform calculations
    sum = x + y;
    product = x * y;
    quotient = x / y;     // Integer division (e.g. 7 / 3 = 2)
    remainder = x % y;    // Modulus gives remainder (e.g. 7 % 3 = 1) (3*2 + 1 = 7), with 1 being the remainder.

    // Display all results
    printf("\nThe sum is %d\n", sum);
    printf("The product is %d\n", product);
    printf("The quotient is %d\n", quotient);
    printf("The remainder is %d\n", remainder);

    return 0;
}
