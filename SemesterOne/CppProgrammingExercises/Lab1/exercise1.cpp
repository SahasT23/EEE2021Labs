#include <iostream>   // For input/output functions
#include <typeinfo>   // For typeid() to display variable type

int main() {
    // Declare variable x using auto (compiler deduces the type)
    auto x = 42;

    // Print out the type of x (usually 'i' for int depending on compiler)
    std::cout << "Type of x: " << typeid(x).name() << std::endl;

    // Declare two integer variables for user input
    int a, b;

    // Ask the user to enter two integers
    std::cout << "Enter two integers: ";

    // Read the two integers from keyboard input
    std::cin >> a >> b;

    // Calculate and print their sum
    std::cout << "Sum = " << a + b << std::endl;

    // End of the program
    return 0;
}
