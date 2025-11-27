#include <iostream>

/*

  Why do we need a deep copy constructor?
  ---------------------------------------
  Because this class uses a RAW POINTER (`int* data`) to store an array.

  What happens with a SHALLOW COPY?
  ---------------------------------
  - The pointer is copied -> BOTH objects point to the SAME memory.
  - When one object is destroyed, the other object now has a pointer to invalid memory.
  - Also: modifying one object's array modifies the other's array.

  A DEEP COPY:
  ------------
  - Allocates brand new memory.
  - Copies each element manually.
  - Ensures each object owns its own data.

  Destructor:
  -----------
  - Needed because we manually allocate memory using new[].
  - Ensures we don't leak memory.
*/

class DynamicArray {
private:
    int* data;  // dynamically allocated array
    int size;

public:
    // Constructor: allocate memory and initialise elements
    DynamicArray(int s) : size(s) {
        data = new int[size];
        for (int i = 0; i < size; ++i)
            data[i] = 0;
    }

    // Deep Copy Constructor
    DynamicArray(const DynamicArray& other) : size(other.size) {
        data = new int[size];  // allocate NEW memory

        // Copy each element individually to avoid sharing memory
        for (int i = 0; i < size; ++i)
            data[i] = other.data[i];
    }

    void display() const {
        for (int i = 0; i < size; ++i)
            std::cout << data[i] << " ";
        std::cout << "\n";
    }

    void modifyElement(int index, int value) {
        if (index >= 0 && index < size)
            data[index] = value;
        else
            std::cout << "Invalid index.\n";
    }

    // Destructor frees owned memory
    ~DynamicArray() {
        delete[] data;
    }
};

int main() {
    DynamicArray arr1(5);
    arr1.display();

    DynamicArray arr2 = arr1; // deep copy constructor

    arr1.modifyElement(2, 42);

    std::cout << "Original: ";
    arr1.display();
    std::cout << "Copy: ";
    arr2.display();
}

/*
Why the output looks like this:
-------------------------------

1. array1 is created with size = 5.
   Its constructor fills all 5 elements with 0.
   So display() prints:
        0 0 0 0 0

2. array2 = array1 uses the COPY CONSTRUCTOR.
   The copy constructor performs a DEEP COPY:
       -> New memory is allocated
       -> All values (0 0 0 0 0) are copied into array2

3. We modify array1 at index 2:
        array1[2] = 42
   So array1 becomes:
        0 0 42 0 0

4. array2 does NOT change, because it owns its own separate memory.
   So array2 stays:
        0 0 0 0 0

Therefore the printed lines are:
    Original: 0 0 0 0 0
    Modified Original: 0 0 42 0 0
    Copy: 0 0 0 0 0
*/
