/*
 * Program: Convert between Celsius and Fahrenheit
 * -----------------------------------------------
 * Formula:
 *   °F = (°C × 9/5) + 32
 *   °C = (°F − 32) × 5/9
 *
 * Demonstrates conditional branching using 'if...else'.
 */

#include <stdio.h>

/*
* A macro is a fragment of code which has been given a name.
* Whenever the name is used, it is replaced by the contents of the macro.
* Macros are defined using the #define directive.
* 
* If you want to define constants as macros, you can uncomment the following lines:
* #define F1 9.0
* #define F2 5.0
* #define SHIFT 32.0
* However, in this implementation, we use 'const' variables instead.
* You will need to remove the 'const' declarations in main() if you choose to use macros.
* Lines that you need to change are: 26, 27, and 28. 
*/

int main(void) {

    const float F1 = 9.0, F2 = 5.0, SHIFT = 32.0; // Constants for conversion, can actually be defined as macros
    float tempC, tempF, tempInput;
    char type;

    printf("Enter the temperature type (C or F): ");
    scanf(" %c", &type); // Space before %c skips leftover newline characters

    printf("Enter the temperature value: ");
    scanf("%f", &tempInput);

    if (type == 'C' || type == 'c') {
        tempC = tempInput;
        tempF = (tempC * F1 / F2) + SHIFT;
        printf("Temperature in Fahrenheit: %.2f°F\n", tempF);
    } else if (type == 'F' || type == 'f') {
        tempF = tempInput;
        tempC = (tempF - SHIFT) * F2 / F1;
        printf("Temperature in Celsius: %.2f°C\n", tempC);
    } else {
        printf("Invalid input! Please enter 'C' or 'F'.\n");
    }

    return 0;
}
