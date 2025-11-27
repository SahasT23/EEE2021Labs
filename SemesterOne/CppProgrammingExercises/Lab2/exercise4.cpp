<<<<<<< HEAD
#include <iostream>  // Needed for std::cout, std::cin, std::endl

// =============================================================
// EXERCISE 4: DYNAMIC MEMORY MANAGEMENT (2D ARRAY)
// =============================================================
//
// GOAL:
//   - Learn how to create a 2D array *dynamically* using pointers.
//   - Learn how to assign values, print them, and free memory.
//
// WHY DYNAMIC ALLOCATION?
//   - When we don’t know array size at compile time,
//     we must allocate memory while the program is running.
//
// STEPS:
//   1. Ask the user for number of rows and columns.
//   2. Allocate a 2D array using pointers.
//   3. Fill it with example values.
//   4. Print the array in grid form.
//   5. Deallocate memory properly.
//
// NO external libraries are used — only basic pointers and loops.
// =============================================================


// ------------------------------------------------------------
// FUNCTION: create2DArray
// PURPOSE : Dynamically allocate a 2D array of given size
// RETURN  : Pointer to the first element (float**)
// ------------------------------------------------------------
float** create2DArray(int rows, int cols)
{
    // STEP 1: Allocate memory for an array of row pointers.
    // Each pointer will point to one row.
    float** array = new float*[rows];

    // STEP 2: For each row, allocate memory for 'cols' floats.
    for (int i = 0; i < rows; ++i)
    {
        array[i] = new float[cols]; // Allocate memory for columns in this row

        // STEP 3: Fill each element with a simple formula.
        // You can change this formula to anything you like.
        for (int j = 0; j < cols; ++j)
        {
            array[i][j] = 1.5f * (i + 1) * (j + 1);
            // Example: (1.5 * rowIndex * columnIndex)
            // Produces a clear pattern to check visually.
        }
    }

    // STEP 4: Return the pointer to the newly created 2D array.
    return array;
}


// ------------------------------------------------------------
// FUNCTION: print2DArray
// PURPOSE : Display the contents of a 2D array neatly
// ------------------------------------------------------------
void print2DArray(float** array, int rows, int cols)
{
    std::cout << "\nDisplaying the 2D array (" << rows << " x " << cols << "):\n";

    for (int i = 0; i < rows; ++i) // Loop through each row
    {
        for (int j = 0; j < cols; ++j) // Loop through each column
        {
            std::cout << array[i][j] << " "; // Print each element
        }
        std::cout << std::endl; // Move to next row after each line
    }

    std::cout << "---------------------------------\n";
}


// ------------------------------------------------------------
// FUNCTION: delete2DArray
// PURPOSE : Free up the memory allocated for a 2D array
// ------------------------------------------------------------
void delete2DArray(float** array, int rows)
{
    // We must delete each sub-array (each row) first.
    for (int i = 0; i < rows; ++i)
    {
        delete[] array[i]; // Free memory of the i-th row
    }

    // Then delete the array of row pointers itself.
    delete[] array;

    // Always good practice: set pointer to nullptr (optional safety)
    array = nullptr;
}


// ------------------------------------------------------------
// MAIN FUNCTION
// ------------------------------------------------------------
int main()
{
    // Declare variables to hold user-defined sizes
    int rows = 0;
    int cols = 0;

    // STEP 1: Ask user for dimensions
    std::cout << "Enter number of rows: ";
    std::cin >> rows;
    std::cout << "Enter number of columns: ";
    std::cin >> cols;

    // Basic input validation (ensure positive sizes)
    if (rows <= 0 || cols <= 0)
    {
        std::cout << "Invalid size entered! Please run again.\n";
        return 1; // Exit program with error code 1
    }

    // STEP 2: Create the dynamic 2D array
    float** myArray = create2DArray(rows, cols);

    // STEP 3: Print the contents
    print2DArray(myArray, rows, cols);

    // STEP 4: Free up memory to avoid leaks
    std::cout << "Now deleting the array from memory...\n";
    delete2DArray(myArray, rows);

    std::cout << "Memory freed, Program complete.\n";

    return 0; // Successful exit
=======

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
>>>>>>> 3674cd796eef302c0fad4a47f195d13d4b1a35dd
}
