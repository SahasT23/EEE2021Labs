#include <iostream>
#include <string>

/*
 * ================================================================
 *  PROBLEM 2: MATRIX OPERATIONS (WITHOUT std::vector)
 * ================================================================
 *
 * GOAL:
 *   - Perform Matrix Addition and Matrix Multiplication.
 *   - Use plain C++ dynamic memory (no <vector>).
 *   - Include a commented-out alternative using <vector> for comparison.
 *
 * THEORY RECAP:
 *   1️ Matrix Addition:
 *         C[i][j] = A[i][j] + B[i][j]
 *      Requires both matrices to have the same dimensions (rows × cols).
 *
 *   2️ Matrix Multiplication:
 *         If A = m×n and B = n×p, then result C = m×p where:
 *         C[i][j] = Σ (A[i][k] * B[k][j]) for k = 0 to n-1
 *
 * MEMORY MODEL:
 *   - We allocate a "pointer to pointer" (int **matrix).
 *   - Each pointer in the first array points to one row.
 *   - So matrix[i][j] gives access to the element in row i, column j.
 */

// Function to create a 2D matrix dynamically
int** createMatrix(int rows, int cols) {
    int** matrix = new int*[rows]; // Allocate memory for row pointers
    for (int i = 0; i < rows; i++) {
        matrix[i] = new int[cols]; // Allocate memory for each row
    }
    return matrix;
}

// Function to input values into a matrix
void inputMatrix(int** matrix, int rows, int cols, const std::string& name) {
    std::cout << "\nEnter elements for Matrix " << name << " (" << rows << "x" << cols << "):\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cout << name << "[" << i << "][" << j << "] = ";
            std::cin >> matrix[i][j];
        }
    }
}

// Function to print a matrix
void printMatrix(int** matrix, int rows, int cols, const std::string& name) {
    std::cout << "\nMatrix " << name << ":\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cout << matrix[i][j] << "\t";
        }
        std::cout << '\n';
    }
}

// Function to add two matrices
int** addMatrices(int** A, int** B, int rows, int cols) {
    int** result = createMatrix(rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = A[i][j] + B[i][j];
        }
    }
    return result;
}

// Function to multiply two matrices
int** multiplyMatrices(int** A, int** B, int rowsA, int colsA, int colsB) {
    int** result = createMatrix(rowsA, colsB);
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            result[i][j] = 0;
            for (int k = 0; k < colsA; k++) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return result;
}

// Function to free dynamic memory
void freeMatrix(int** matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

int main() {
    int rowsA, colsA, rowsB, colsB;

    std::cout << "Enter rows and columns for Matrix A: ";
    std::cin >> rowsA >> colsA;
    std::cout << "Enter rows and columns for Matrix B: ";
    std::cin >> rowsB >> colsB;

    // Basic dimension validation
    if (rowsA != rowsB || colsA != colsB) {
        std::cout << "\n⚠️ Note: Matrices must be same size for addition.\n";
    }

    if (colsA != rowsB) {
        std::cout << "⚠️ Multiplication not possible: Columns of A must equal rows of B.\n";
    }

    // Create and input matrices
    int** A = createMatrix(rowsA, colsA);
    int** B = createMatrix(rowsB, colsB);

    inputMatrix(A, rowsA, colsA, "A");
    inputMatrix(B, rowsB, colsB, "B");

    printMatrix(A, rowsA, colsA, "A");
    printMatrix(B, rowsB, colsB, "B");

    // Perform Addition (only if sizes match)
    if (rowsA == rowsB && colsA == colsB) {
        int** sum = addMatrices(A, B, rowsA, colsA);
        printMatrix(sum, rowsA, colsA, "A + B");
        freeMatrix(sum, rowsA);
    }

    // Perform Multiplication (only if valid)
    if (colsA == rowsB) {
        int** product = multiplyMatrices(A, B, rowsA, colsA, colsB);
        printMatrix(product, rowsA, colsB, "A * B");
        freeMatrix(product, rowsA);
    }

    // Free allocated memory
    freeMatrix(A, rowsA);
    freeMatrix(B, rowsB);

    return 0;
}

/* ================================================================
   COMMENTED-OUT VERSION USING <vector>
   ================================================================
   This version does the exact same thing, but uses the C++ Standard
   Template Library (STL) `std::vector` instead of manual memory.

   HOW std::vector WORKS:
   ---------------------------------------------------------------
   - `std::vector` is a template class from the <vector> header.
   - It’s a dynamic array that automatically manages memory.
   - You can resize it at runtime, and it cleans itself up when it
     goes out of scope (no need for delete).
   - Syntax:
         vector<int> v;            // 1D vector
         vector<vector<int>> m;    // 2D vector (matrix)
   - Elements are accessed via [] like normal arrays.
   - `v.size()` returns number of elements.
   - Advantages:
       No manual memory management
       Bounds checking (with at())
       Works with standard algorithms (e.g., sort, find, etc.)

   EXAMPLE USING std::vector:
   ---------------------------------------------------------------
   #include <iostream>
   #include <vector>

   vector<vector<int>> addMatrices(const vector<vector<int>>& A,
                                   const vector<vector<int>>& B) {
       int rows = A.size(), cols = A[0].size();
       vector<vector<int>> result(rows, vector<int>(cols));
       for (int i = 0; i < rows; i++) {
           for (int j = 0; j < cols; j++) {
               result[i][j] = A[i][j] + B[i][j];
           }
       }
       return result;
   }

   vector<vector<int>> multiplyMatrices(const vector<vector<int>>& A,
                                        const vector<vector<int>>& B) {
       int rowsA = A.size(), colsA = A[0].size(), colsB = B[0].size();
       vector<vector<int>> result(rowsA, vector<int>(colsB, 0));
       for (int i = 0; i < rowsA; i++) {
           for (int j = 0; j < colsB; j++) {
               for (int k = 0; k < colsA; k++) {
                   result[i][j] += A[i][k] * B[k][j];
               }
           }
       }
       return result;
   }

   void printMatrix(const vector<vector<int>>& M) {
       for (auto& row : M) {
           for (int val : row) std::cout << val << " ";
           std::cout << std::string;
       }
   }

   int main() {
       vector<vector<int>> A = {{1, 2}, {3, 4}};
       vector<vector<int>> B = {{5, 6}, {7, 8}};
       std::cout << "A + B:\n"; printMatrix(addMatrices(A, B));
       std::cout << "\nA * B:\n"; printMatrix(multiplyMatrices(A, B));
   }
   ================================================================
*/
