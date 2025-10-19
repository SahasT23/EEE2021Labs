/*
 * Program: Solve quadratic equation ax² + bx + c = 0
 * ---------------------------------------------------
 * Formula: x = (-b ± √(b² - 4ac)) / (2a)
 *
 * Uses conditional logic to check if roots are real.
 * If discriminant (b² - 4ac) is negative, roots are not real.
 * 
 * If you want to create your own sqrt() function (similar to how C does it), uncomment the following code:
 * ---------------------------------------------------
 * double custom_sqrt(double number) {
 *     if (number < 0) {  
 *        return -1; // Indicate error for negative input
 *    }
 *    double guess = number / 2.0;
 *    double epsilon = 0.00001; // Precision level
 *    while (fabs(guess * guess - number) > epsilon) {
 *        guess = (guess + number / guess) / 2.0;
 *    }
 *    return guess;
 * }
 * ---------------------------------------------------
 *
 * To use custom_sqrt, replace sqrt(discriminant) with custom_sqrt(discriminant) in the main code.
 * This implementation uses the Newton-Raphson method for square root calculation, which, again, you should know from ENG1001.
 */

#include <stdio.h>
#include <math.h> // For sqrt() function

int main(void) {

    float a, b, c, discriminant, x1, x2;

    // Input coefficients
    printf("Enter coefficients a, b, and c: ");
    scanf("%f %f %f", &a, &b, &c);

    // Calculate discriminant
    discriminant = b * b - 4 * a * c;

    if (discriminant >= 0) {
        // sqrt(discriminant) returns square root
        x1 = (-b + sqrt(discriminant)) / (2 * a);
        x2 = (-b - sqrt(discriminant)) / (2 * a);

        printf("The roots are real:\n");
        printf("x1 = %.2f, x2 = %.2f\n", x1, x2);
    } else {
        printf("The roots are not real.\n"); // Discriminant is negative, can think of this as error handling.
    }

    return 0;
}
