/*
 * Program: Calculate the circumference and area of a circle
 * ---------------------------------------------------------
 * Formula:
 *   Circumference = 2 * π * r
 *   Area = π * r²
 *
 * π (Pi) is defined as a constant using #define
 */

#include <stdio.h>

#define PI 3.1415926 // Constant value for Pi, better to use a constant than hardcoding the value multiple times. Will be useful later when we learn about functions.

int main(void) {

    float radius, circumference, area; // Use float for decimal results, as radius can be a decimal number.

    printf("Enter the radius of the circle: ");
    scanf("%f", &radius);

    // Calculate using formulas
    circumference = 2 * PI * radius; // You should know this from ENG1001!
    area = PI * radius * radius; 

    printf("Circumference: %.2f\n", circumference);
    printf("Area: %.2f\n", area);

    return 0;
}
