#include <iostream> // Required for std::cout and std::endl

// =============================================================
// EXERCISE 3: VARIADIC FUNCTIONS
// =============================================================
// GOAL:
//   1. Understand what a *variadic function* is in C++.
//   2. Write a recursive template function that can take
//      ANY number of numeric inputs and compute:
//         (a) their SUM
//         (b) their AVERAGE
//
// EXPLANATION:
//   - “Variadic” means “variable number of arguments.”
//   - In C++, this is implemented using *template parameter packs*.
//   - For example:
//        sum(1, 2, 3, 4) should return 10.
//        average(1, 2, 3, 4) should return 2.5.
//
// NO external libraries are used — only <iostream>.
// =============================================================


// ----------------------------------------------------------
// STEP 1: Base Case Function (sum of one number)
// ----------------------------------------------------------
// Every recursive variadic function needs a base case.
// This tells the compiler when to stop the recursion.
//
// Here, when there’s only ONE number left, we just return it.
double sum(double value)
{
    return value;
}


// ----------------------------------------------------------
// STEP 2: Recursive Case Function (sum of many numbers)
// ----------------------------------------------------------
// This version handles multiple arguments.
//
// For example, calling sum(1, 2, 3):
//   - First call: sum(1, 2, 3)
//   - It returns 1 + sum(2, 3)
//   - Next: sum(2, 3) = 2 + sum(3)
//   - Finally: sum(3) just returns 3
//   - So the result is 1 + 2 + 3 = 6
//
// The “...” means this function can take any number of arguments.
template <typename... Args>
double sum(double first, Args... rest)
{
    return first + sum(rest...); // Recursively add all values
}


// ----------------------------------------------------------
// STEP 3: Average Function (using sum)
// ----------------------------------------------------------
// This function computes the average by dividing
// the total sum by the number of arguments.
//
// sizeof...(values) gives the number of arguments passed in.
template <typename... Args>
double average(Args... values)
{
    // Count how many arguments were passed
    const int count = sizeof...(values);

    // Get total sum by calling our recursive sum() function
    double total = sum(values...);

    // Compute and return the average value
    return total / static_cast<double>(count);
}


// ----------------------------------------------------------
// STEP 4: MAIN FUNCTION
// ----------------------------------------------------------
// We will test the functions with multiple examples.
// ----------------------------------------------------------
int main()
{
    std::cout << "============================" << std::endl;
    std::cout << "VARIADIC FUNCTION DEMONSTRATION" << std::endl;
    std::cout << "============================" << std::endl;

    // Example 1: Basic integer input
    double result1 = sum(1, 2, 3, 4, 5);
    std::cout << "Sum(1, 2, 3, 4, 5) = " << result1 << std::endl;

    double avg1 = average(1, 2, 3, 4, 5);
    std::cout << "Average(1, 2, 3, 4, 5) = " << avg1 << std::endl;
    std::cout << "----------------------------" << std::endl;

    // Example 2: Using a mix of integers and floating-point numbers
    double result2 = sum(2.5, 3.5, 1, 5.0);
    std::cout << "Sum(2.5, 3.5, 1, 5.0) = " << result2 << std::endl;

    double avg2 = average(2.5, 3.5, 1, 5.0);
    std::cout << "Average(2.5, 3.5, 1, 5.0) = " << avg2 << std::endl;
    std::cout << "----------------------------" << std::endl;

    // Example 3: Single input (to test base case)
    double result3 = sum(10.0);
    std::cout << "Sum(10.0) = " << result3 << std::endl;

    double avg3 = average(10.0);
    std::cout << "Average(10.0) = " << avg3 << std::endl;
    std::cout << "----------------------------" << std::endl;

    // Example 4: Negative and zero values
    double result4 = sum(-5.0, 0.0, 5.0);
    std::cout << "Sum(-5.0, 0.0, 5.0) = " << result4 << std::endl;

    double avg4 = average(-5.0, 0.0, 5.0);
    std::cout << "Average(-5.0, 0.0, 5.0) = " << avg4 << std::endl;
    std::cout << "----------------------------" << std::endl;

    // Program end message
    std::cout << "All examples completed successfully!" << std::endl;

    return 0; // Program ran successfully
}
