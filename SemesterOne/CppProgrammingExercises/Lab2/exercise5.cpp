
#include <iostream>
#include <algorithm>  // For std::reverse, std::sort (if desired)

/*
 * PROBLEM 5: ARRAY MANIPULATION LIBRARY
 *
 * Implement basic array operations:
 *  1. Reverse an array
 *  2. Pivot (rotate) an array around a specific index
 *  3. Sort an array (bubble sort)
 *  4. Search in an unsorted array (linear search)
 *  5. Search in a sorted array (binary search)
 */

// Function to reverse an array
void reverseArray(int arr[], int size) {
    for (int i = 0; i < size / 2; i++) {
        std::swap(arr[i], arr[size - i - 1]);
    }
}

// Function to pivot (rotate) the array
void pivotArray(int arr[], int size, int pivot) {
    int* temp = new int[size];
    int index = 0;

    // Copy elements from pivot+1 to end
    for (int i = pivot + 1; i < size; i++) temp[index++] = arr[i];
    // Copy elements from start to pivot
    for (int i = 0; i <= pivot; i++) temp[index++] = arr[i];

    for (int i = 0; i < size; i++) arr[i] = temp[i];

    delete[] temp;
}

// Bubble sort implementation
void bubbleSort(int arr[], int size) {
    bool swapped;
    for (int i = 0; i < size - 1; i++) {
        swapped = false;
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break; // Optimization: stop if already sorted
    }
}

// Linear search (unsorted array)
int linearSearch(int arr[], int size, int key) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == key) return i;
    }
    return -1;
}

// Binary search (sorted array, recursive)
int binarySearch(int arr[], int left, int right, int key) {
    if (left <= right) {
        int mid = (left + right) / 2;

        if (arr[mid] == key) return mid;
        if (key < arr[mid]) return binarySearch(arr, left, mid - 1, key);
        else return binarySearch(arr, mid + 1, right, key);
    }
    return -1;
}

// Utility to print an array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) std::cout << arr[i] << " ";
    std::cout << std::endl;
}

int main() {
    int arr[] = {4, 1, 6, 2, 7, 10, 13, 8};
    int size = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Original array:\n";
    printArray(arr, size);

    std::cout << "\nReversed array:\n";
    reverseArray(arr, size);
    printArray(arr, size);

    std::cout << "\nPivot around index 3:\n";
    pivotArray(arr, size, 3);
    printArray(arr, size);

    std::cout << "\nSorting array (Bubble Sort):\n";
    bubbleSort(arr, size);
    printArray(arr, size);

    std::cout << "\nLinear search for 10:\n";
    int idx = linearSearch(arr, size, 10);
    if (idx != -1) std::cout << "Found at index " << idx << std::endl;
    else std::cout << "Not found.\n";

    std::cout << "\nBinary search for 7 (requires sorted array):\n";
    idx = binarySearch(arr, 0, size - 1, 7);
    if (idx != -1) std::cout << "Found at index " << idx << std::endl;
    else std::cout << "Not found.\n";

    return 0;
}
