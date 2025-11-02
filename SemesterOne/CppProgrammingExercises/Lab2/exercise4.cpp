
#include <iostream>

/*
 * PROBLEM 4: DYNAMIC MEMORY MANAGEMENT (2D ARRAYS)
 *
 * Create a 2D array dynamically using 'new' and 'delete'.
 * Then assign values, print, and deallocate the memory.
 *
 * THEORY:
 *  - Static arrays (int arr[3][3]) have fixed size known at compile time.
 *  - Dynamic arrays are created at runtime using 'new'.
 *  - For 2D arrays, we use a pointer-to-pointer (int **arr).
 */

int main() {
    int rows = 3, cols = 4;

    // Step 1: Create a pointer to pointer (for a 2D array)
    int **array2D = new int*[rows]; // array of int pointers

    // Step 2: Allocate memory for each row
    for (int i = 0; i < rows; i++) {
        array2D[i] = new int[cols];
    }

    // Step 3: Assign values to the array
    int counter = 1;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            array2D[i][j] = counter++;
        }
    }

    // Step 4: Print the array
    std::cout << "2D Array values:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cout << array2D[i][j] << "\t";
        }
        std::cout << std::endl;
    }

    // Step 5: Deallocate memory (very important to avoid memory leaks)
    for (int i = 0; i < rows; i++) {
        delete[] array2D[i]; // delete each row
    }
    delete[] array2D; // delete row pointer array

    std::cout << "\nMemory successfully freed!" << std::endl;
    return 0;
}
