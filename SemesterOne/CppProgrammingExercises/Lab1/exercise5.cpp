#include <iostream>   // For printing output

int main() {
    const int size = 20;     // Define table size (20x20)
    int table[size][size];   // Declare a 2D array

    // Fill the multiplication table
    for (int i = 0; i < size; ++i) {           // Loop through rows
        for (int j = 0; j < size; ++j) {       // Loop through columns
            table[i][j] = (i + 1) * (j + 1);   // Fill cell with product
        }
    }

    // Print the table in a formatted grid
    std::cout << "20x20 Multiplication Table:\n";
    for (int i = 0; i < size; ++i) {           // Loop rows
        for (int j = 0; j < size; ++j) {       // Loop columns
            std::cout << table[i][j] << "\t";  // Print each cell with tab spacing
        }
        std::cout << std::endl;                // Newline after each row
    }

    // Demonstrate pointer traversal through the 2D array
    std::cout << "\nPointer traversal example:\n";

    // Pointer to the first element of the 2D array
    int* ptr = &table[0][0];

    // There are size * size total elements in the 2D array
    for (int k = 0; k < size * size; ++k) {
        std::cout << *(ptr + k) << " ";  // Access each element by pointer arithmetic
        if ((k + 1) % size == 0)         // New line after every 20 elements
            std::cout << std::endl;
    }

    return 0;
}
