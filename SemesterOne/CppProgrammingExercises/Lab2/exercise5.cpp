#include <iostream>  // For std::cout, std::endl, std::cin only

// =============================================================
// EXERCISE 5: ARRAY MANIPULATION LIBRARY
// =============================================================
//
// GOAL:
//   Create a small "library" of basic array operations
//   implemented from scratch, including:
//
//     1. Reversing an array
//     2. Pivoting (rotating) an array around a point
//     3. Sorting (using simple Bubble Sort)
//     4. Searching for an element in an array
//
//   We'll then demonstrate all of them in main().
//
// =============================================================
//
// RULES:
//   - No external helper libraries
//   - No <algorithm> or built-in sort/swap
//   - Everything is written manually
//
//   We'll work with a fixed-size integer array for simplicity.
// =============================================================


// -------------------------------------------------------------
// FUNCTION: swapElements
// PURPOSE : Manually swap two elements in an array
// -------------------------------------------------------------
void swapElements(int& a, int& b)
{
    int temp = a; // Store 'a' temporarily
    a = b;        // Assign 'b' to 'a'
    b = temp;     // Assign stored value back to 'b'
}


// -------------------------------------------------------------
// FUNCTION: reverseArray
// PURPOSE : Reverse the order of elements in the array
// EXAMPLE : [4, 1, 6, 2] → [2, 6, 1, 4]
// -------------------------------------------------------------
void reverseArray(int array[], int size)
{
    // We only need to loop halfway since each swap fixes two elements
    for (int i = 0; i < size / 2; ++i)
    {
        swapElements(array[i], array[size - 1 - i]);
    }
}


// -------------------------------------------------------------
// FUNCTION: pivotArray
// PURPOSE : "Rotate" an array around a pivot position
// EXAMPLE : [4, 1, 6, 2, 7, 10, 13, 8], pivot = 3
// RESULT  : [2, 7, 10, 13, 8, 4, 1, 6]
// EXPLANATION:
//   - The first 3 elements are moved to the end.
// -------------------------------------------------------------
void pivotArray(int array[], int size, int pivot)
{
    if (pivot <= 0 || pivot >= size)
    {
        std::cout << "Invalid pivot point! Must be between 1 and " << size - 1 << ".\n";
        return;
    }

    // STEP 1: Create a temporary array to store the first part
    int* temp = new int[pivot]; // Holds first 'pivot' elements

    for (int i = 0; i < pivot; ++i)
    {
        temp[i] = array[i];
    }

    // STEP 2: Shift the remaining elements to the front
    for (int i = 0; i < size - pivot; ++i)
    {
        array[i] = array[i + pivot];
    }

    // STEP 3: Move the stored elements to the end
    for (int i = 0; i < pivot; ++i)
    {
        array[size - pivot + i] = temp[i];
    }

    // STEP 4: Free temporary memory
    delete[] temp;
}


// -------------------------------------------------------------
// FUNCTION: bubbleSort
// PURPOSE : Sort the array in ascending order using Bubble Sort
// EXAMPLE : [5, 2, 4] → [2, 4, 5]
// METHOD  : Repeatedly swap adjacent elements if they’re out of order.
// -------------------------------------------------------------
void bubbleSort(int array[], int size)
{
    bool swapped;

    // Keep iterating until no swaps are needed
    do
    {
        swapped = false; // Assume sorted
        for (int i = 0; i < size - 1; ++i)
        {
            if (array[i] > array[i + 1]) // If out of order
            {
                swapElements(array[i], array[i + 1]);
                swapped = true; // Found something to swap, keep looping
            }
        }
    } while (swapped); // Stop when one full pass had no swaps
}


// -------------------------------------------------------------
// FUNCTION: linearSearch
// PURPOSE : Search for a value in an UNSORTED array
// RETURNS : The index of the first occurrence or -1 if not found
// -------------------------------------------------------------
int linearSearch(int array[], int size, int value)
{
    for (int i = 0; i < size; ++i)
    {
        if (array[i] == value)
        {
            return i; // Found it
        }
    }
    return -1; // Not found
}


// -------------------------------------------------------------
// FUNCTION: binarySearch
// PURPOSE : Search for a value in a SORTED array efficiently
// METHOD  : Repeatedly check the middle of the current range
// RETURNS : Index of the found element or -1 if not found
// -------------------------------------------------------------
int binarySearch(int array[], int left, int right, int value)
{
    while (left <= right)
    {
        int mid = (left + right) / 2; // Find middle element

        if (array[mid] == value)
        {
            return mid; // Found the value
        }
        else if (array[mid] < value)
        {
            left = mid + 1; // Search upper half
        }
        else
        {
            right = mid - 1; // Search lower half
        }
    }

    // If we exit the loop, the value wasn’t found
    return -1;
}


// -------------------------------------------------------------
// FUNCTION: printArray
// PURPOSE : Print the contents of an integer array
// -------------------------------------------------------------
void printArray(int array[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}


// -------------------------------------------------------------
// MAIN FUNCTION — Demonstrates all of the above
// -------------------------------------------------------------
int main()
{
    // STEP 1: Define an example array
    int data[] = {4, 1, 6, 2, 7, 10, 13, 8};
    int size = sizeof(data) / sizeof(data[0]);

    std::cout << "Original Array:\n";
    printArray(data, size);
    std::cout << "---------------------------------\n";

    // STEP 2: Reverse the array
    std::cout << "Reversing array...\n";
    reverseArray(data, size);
    printArray(data, size);
    std::cout << "---------------------------------\n";

    // STEP 3: Pivot the array around index 3
    std::cout << "Pivoting array around position 3...\n";
    pivotArray(data, size, 3);
    printArray(data, size);
    std::cout << "---------------------------------\n";

    // STEP 4: Sort the array using bubble sort
    std::cout << "Sorting array using bubble sort...\n";
    bubbleSort(data, size);
    printArray(data, size);
    std::cout << "---------------------------------\n";

    // STEP 5: Search examples
    int searchValue = 7;
    std::cout << "Searching for " << searchValue << " using linear search...\n";
    int indexLinear = linearSearch(data, size, searchValue);
    if (indexLinear != -1)
        std::cout << "Value found at index: " << indexLinear << " (unsorted search)\n";
    else
        std::cout << "Value not found!\n";

    std::cout << "Searching for " << searchValue << " using binary search (sorted array)...\n";
    int indexBinary = binarySearch(data, 0, size - 1, searchValue);
    if (indexBinary != -1)
        std::cout << "Value found at index: " << indexBinary << " (sorted search)\n";
    else
        std::cout << "Value not found!\n";

    std::cout << "---------------------------------\n";
    std::cout << "Program completed successfully!\n";

    return 0; // Successful exit
}
