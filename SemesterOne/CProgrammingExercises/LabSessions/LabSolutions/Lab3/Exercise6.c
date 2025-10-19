/*
 * Program: Temperature conversion using switch-case
 * -------------------------------------------------
 * This is the same logic as Exercise 5, but we use a switch statement.
 * 'switch' checks a single variable (like type) and executes the matching case.
 * Switch is often cleaner than multiple 'if...else' for discrete values, because it avoids repeated evaluations of the same expression.
 * Note: Each 'case' must end with a 'break' to prevent fall-through to the next case.
 * If no case matches, the 'default' case is executed.
 * But be cautious: switch-case is less flexible than if-else for complex conditions.
 * For you exam, if in doubt, use if-else unless specifically asked for switch-case -- you can still get the same result, you will only lose some marks for not using switch-case.
 */

 /**
  * Formula:
  *   °F = (°C × 9/5) + 32 
  *  °C = (°F − 32) × 5/9
  * 
  * For macros, you can uncomment the following lines:
  * #define F1 9.0
  * #define F2 5.0
  * #define SHIFT 32.0
  * (For more information on macros, see Exercise 5.c)
  */

/**
 * For error handling you can use the default case in switch-case.
 * However, for simplicity, we only handle valid cases here.
 */

#include <stdio.h>

int main(void) {

    const float F1 = 9.0, F2 = 5.0, SHIFT = 32.0; // Constants for conversion, again can be defined as macros
    float tempC, tempF, tempInput;
    char type;

    printf("Enter the temperature type (C or F): ");
    scanf(" %c", &type);

    printf("Enter the temperature value: ");
    scanf("%f", &tempInput);

    switch (type) {
        case 'C':
        case 'c': // same logic for lowercase input
            tempC = tempInput;
            tempF = (tempC * F1 / F2) + SHIFT; 
            printf("Temperature in Fahrenheit: %.2f°F\n", tempF);
            break;

        case 'F': // You can also use error handling for invalid input here, but for simplicity, we just handle valid cases
        case 'f':
            tempF = tempInput;
            tempC = (tempF - SHIFT) * F2 / F1;
            printf("Temperature in Celsius: %.2f°C\n", tempC);
            break;

        default:
            printf("Error: Unknown temperature type!\n");
    }

    return 0;
}
