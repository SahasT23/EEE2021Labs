#include <iostream>   // For I/O
#include <cmath>      // For sqrt() function

int main() {
    int n;  // Number to check
    std::cout << "Enter a number: ";
    std::cin >> n;  // Read user input

    bool isPrime = true;  // Assume number is prime initially

    // Numbers <= 1 are not prime
    if (n <= 1) {
        isPrime = false;
    } else {
        // Check divisibility from 2 up to sqrt(n)
        for (int i = 2; i <= std::sqrt(n); ++i) {
            if (n % i == 0) {   // If divisible, not prime
                isPrime = false;
                break;          // Stop checking
            }
        }
    }

    // Display results
    if (isPrime) {
        std::cout << n << " is a prime number." << std::endl;
    } else {
        std::cout << n << " is not a prime number." << std::endl;

        // Show prime factorization
        std::cout << "Prime factors: ";
        int temp = n;  // Copy n so we can modify it
        for (int i = 2; i <= temp; ++i) {
            while (temp % i == 0) {  // Divide as long as divisible
                std::cout << i << " ";  // Print factor
                temp /= i;              // Reduce the number
            }
        }
        std::cout << std::endl;
    }

    return 0;
}
