/*
 * Program: Check whether a number is prime
 * ----------------------------------------
 * A prime number is divisible only by 1 and itself.
 * Steps:
 *  1. Loop through numbers from 2 to n/2.
 *  2. If any number divides n evenly, it's not prime.
 */

#include <stdio.h>

int main(void) {

    int n, i, isNotPrime = 0; // We have set isNotPrime to 0 (assume prime until proven otherwise). We can also set it to 1 and reverse the logic.
    // If you want to reverse the logic, change the condition in the final if statement to (isNotPrime == 1).
    // For efficiency, we only need to check up to n/2, as no factors larger than n/2 (except n itself) can divide n. (Thanks Abby for the suggestion!)

    printf("Enter a positive integer: ");
    scanf("%d", &n);

    if (n == 1) {
        printf("1 is neither prime nor composite.\n");
        return 0;
    }

    for (i = 2; i <= n / 2; i++) { // This for loop works by checking each number from 2 to n/2 (so we start at 2 and increment by 1 each time, stopping when we reach n/2)
        if (n % i == 0) {
            isNotPrime = 1; // flag to mark non-prime
            break; // no need to check further
        }
    }

    if (isNotPrime == 0)
        printf("%d is a prime number.\n", n);
    else
        printf("%d is not a prime number.\n", n);

    return 0;
}
