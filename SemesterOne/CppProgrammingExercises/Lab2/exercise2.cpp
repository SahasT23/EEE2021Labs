#include <iostream>  // Required for input/output (std::cout, std::endl)

// =============================================================
// EXERCISE 2: MATRIX OPERATIONS
// =============================================================
// In this program, we will:
//
// 1. Create two 2D matrices (using fixed-size arrays for simplicity)
// 2. Add the two matrices together
// 3. Multiply the two matrices
// 4. Print the results in a clear format
//
// No external libraries are used — everything is written from scratch.
// =============================================================

// -------------------------
// STEP 1: Define constants
// -------------------------
// We will work with 3x3 matrices here for simplicity.
// You can change 'SIZE' to any other number if you like.
const int SIZE = 3;

// ----------------------------------------------------------
// Function: addMatrices
// Purpose:  Add two matrices (A and B) and store the result in 'result'
// Formula:  result[i][j] = A[i][j] + B[i][j]
// ----------------------------------------------------------
void addMatrices(double A[SIZE][SIZE], double B[SIZE][SIZE], double result[SIZE][SIZE])
{
    for (int i = 0; i < SIZE; ++i) {          // Loop through each row
        for (int j = 0; j < SIZE; ++j) {      // Loop through each column
            result[i][j] = A[i][j] + B[i][j]; // Add corresponding elements
        }
    }
}

// ----------------------------------------------------------
// Function: multiplyMatrices
// Purpose:  Multiply two matrices (A and B) and store in 'result'
// Formula:  result[i][j] = sum of (A[i][k] * B[k][j]) for all k
// ----------------------------------------------------------
void multiplyMatrices(double A[SIZE][SIZE], double B[SIZE][SIZE], double result[SIZE][SIZE])
{
    // First, initialize the result matrix to all zeros
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            result[i][j] = 0.0; // Important: reset value before accumulation
        }
    }

    // Perform matrix multiplication
    for (int i = 0; i < SIZE; ++i) {           // Loop over rows of A
        for (int j = 0; j < SIZE; ++j) {       // Loop over columns of B
            for (int k = 0; k < SIZE; ++k) {   // Loop for the dot product
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

// ----------------------------------------------------------
// Function: printMatrix
// Purpose:  Display the contents of a matrix in a readable grid
// ----------------------------------------------------------
void printMatrix(double M[SIZE][SIZE])
{
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            std::cout << M[i][j] << " "; // Print each element with a space
        }
        std::cout << std::endl; // Move to the next line after each row
    }
    std::cout << "-------------------" << std::endl; // Separator line
}

// ----------------------------------------------------------
// MAIN FUNCTION
// ----------------------------------------------------------
// This is where the program starts running.
// ----------------------------------------------------------
int main()
{
    // ---------------------------
    // STEP 1: Define our matrices
    // ---------------------------
    // We’ll create two 3x3 matrices for demonstration.

    double A[SIZE][SIZE] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    double B[SIZE][SIZE] = {
        {9, 8, 7},
        {6, 5, 4},
        {3, 2, 1}
    };

    // This matrix will store the results (both addition and multiplication)
    double result[SIZE][SIZE];

    // ---------------------------
    // STEP 2: Matrix Addition
    // ---------------------------
    std::cout << "Matrix A:" << std::endl;
    printMatrix(A);

    std::cout << "Matrix B:" << std::endl;
    printMatrix(B);

    // Perform addition
    addMatrices(A, B, result);

    std::cout << "Result of A + B:" << std::endl;
    printMatrix(result);

    // ---------------------------
    // STEP 3: Matrix Multiplication
    // ---------------------------
    multiplyMatrices(A, B, result);

    std::cout << "Result of A * B:" << std::endl;
    printMatrix(result);

    // ---------------------------
    // STEP 4: End of program
    // ---------------------------
    std::cout << "Matrix operations complete!" << std::endl;

    return 0; // 0 means the program ended successfully
}
