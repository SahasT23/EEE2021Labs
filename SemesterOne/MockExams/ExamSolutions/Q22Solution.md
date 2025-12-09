# C++ Annual_Saving Class - Step by Step Solution (Incremental Building & Testing)

## Overview

This guide walks you through solving Question 22 using an incremental approach. After each step, we add test code to verify it works before moving on.

---

## Step 1: Set Up the Basic Class Structure

Start with the include, class declaration, and private attributes:

```cpp
#include <iostream>

class Annual_Saving {
private:
    double raw_saving_data[12];
    double sorted_saving_data[12];

public:
    // We'll add member functions here
};

int main() {
    std::cout << "Program compiles!" << std::endl;
    return 0;
}
```

### Test It

Compile and run:
```bash
g++ -o test annual_saving.cpp && ./test
```

**Expected output:**
```
Program compiles!
```

 Basic structure works. Move on.

---

## Step 2: Add the Constructor

Add the constructor that copies input data into both arrays:

```cpp
#include <iostream>

class Annual_Saving {
private:
    double raw_saving_data[12];
    double sorted_saving_data[12];

public:
    Annual_Saving(double data[]) {
        for (int i = 0; i < 12; i++) {
            raw_saving_data[i] = data[i];
            sorted_saving_data[i] = data[i];
        }
    }
};

int main() {
    double data1[] = {3.6, 5.7, 2.3, 3.2, 2.5, 3.8, 5.2, 0.9, 1.1, 4.3, 2.7, 8.3};
    
    Annual_Saving Person1(data1);
    
    std::cout << "Object created successfully!" << std::endl;
    return 0;
}
```

### Test It

Compile and run.

**Expected output:**
```
Object created successfully!
```

 Constructor works. Move on.

---

## Step 3: Add show_raw_data Function

Add the function to display raw data so we can verify the constructor actually stored the values:

```cpp
#include <iostream>

class Annual_Saving {
private:
    double raw_saving_data[12];
    double sorted_saving_data[12];

public:
    Annual_Saving(double data[]) {
        for (int i = 0; i < 12; i++) {
            raw_saving_data[i] = data[i];
            sorted_saving_data[i] = data[i];
        }
    }
    
    void show_raw_data() {
        std::cout << "Raw saving data: ";
        for (int i = 0; i < 12; i++) {
            std::cout << raw_saving_data[i];
            if (i < 11) {
                std::cout << " ";
            }
        }
        std::cout << std::endl;
    }
};

int main() {
    double data1[] = {3.6, 5.7, 2.3, 3.2, 2.5, 3.8, 5.2, 0.9, 1.1, 4.3, 2.7, 8.3};
    
    Annual_Saving Person1(data1);
    
    std::cout << "Testing show_raw_data:" << std::endl;
    Person1.show_raw_data();
    
    return 0;
}
```

### Test It

Compile and run.

**Expected output:**
```
Testing show_raw_data:
Raw saving data: 3.6 5.7 2.3 3.2 2.5 3.8 5.2 0.9 1.1 4.3 2.7 8.3
```

 Data is stored correctly and displays properly. Move on.

---

## Step 4: Add show_sorted_data Function

Add the function to display sorted data (it will show unsorted values for now since we haven't implemented sorting yet):

```cpp
#include <iostream>

class Annual_Saving {
private:
    double raw_saving_data[12];
    double sorted_saving_data[12];

public:
    Annual_Saving(double data[]) {
        for (int i = 0; i < 12; i++) {
            raw_saving_data[i] = data[i];
            sorted_saving_data[i] = data[i];
        }
    }
    
    void show_raw_data() {
        std::cout << "Raw saving data: ";
        for (int i = 0; i < 12; i++) {
            std::cout << raw_saving_data[i];
            if (i < 11) {
                std::cout << " ";
            }
        }
        std::cout << std::endl;
    }
    
    void show_sorted_data() {
        std::cout << "Sorted saving data: ";
        for (int i = 0; i < 12; i++) {
            std::cout << sorted_saving_data[i];
            if (i < 11) {
                std::cout << " ";
            }
        }
        std::cout << std::endl;
    }
};

int main() {
    double data1[] = {3.6, 5.7, 2.3, 3.2, 2.5, 3.8, 5.2, 0.9, 1.1, 4.3, 2.7, 8.3};
    
    Annual_Saving Person1(data1);
    
    std::cout << "Testing both display functions:" << std::endl;
    Person1.show_raw_data();
    Person1.show_sorted_data();
    
    return 0;
}
```

### Test It

Compile and run.

**Expected output:**
```
Testing both display functions:
Raw saving data: 3.6 5.7 2.3 3.2 2.5 3.8 5.2 0.9 1.1 4.3 2.7 8.3
Sorted saving data: 3.6 5.7 2.3 3.2 2.5 3.8 5.2 0.9 1.1 4.3 2.7 8.3
```

 Both arrays contain the same data (as expected before sorting). Move on.

---

## Step 5: Add bubble_sort Function

Now add the sorting function:

```cpp
#include <iostream>

class Annual_Saving {
private:
    double raw_saving_data[12];
    double sorted_saving_data[12];

public:
    Annual_Saving(double data[]) {
        for (int i = 0; i < 12; i++) {
            raw_saving_data[i] = data[i];
            sorted_saving_data[i] = data[i];
        }
    }
    
    void show_raw_data() {
        std::cout << "Raw saving data: ";
        for (int i = 0; i < 12; i++) {
            std::cout << raw_saving_data[i];
            if (i < 11) {
                std::cout << " ";
            }
        }
        std::cout << std::endl;
    }
    
    void show_sorted_data() {
        std::cout << "Sorted saving data: ";
        for (int i = 0; i < 12; i++) {
            std::cout << sorted_saving_data[i];
            if (i < 11) {
                std::cout << " ";
            }
        }
        std::cout << std::endl;
    }
    
    void bubble_sort() {
        double temp;
        
        for (int i = 0; i < 11; i++) {
            for (int j = 0; j < 11 - i; j++) {
                if (sorted_saving_data[j] > sorted_saving_data[j + 1]) {
                    temp = sorted_saving_data[j];
                    sorted_saving_data[j] = sorted_saving_data[j + 1];
                    sorted_saving_data[j + 1] = temp;
                }
            }
        }
    }
};

int main() {
    double data1[] = {3.6, 5.7, 2.3, 3.2, 2.5, 3.8, 5.2, 0.9, 1.1, 4.3, 2.7, 8.3};
    
    Annual_Saving Person1(data1);
    
    std::cout << "Before sorting:" << std::endl;
    Person1.show_raw_data();
    Person1.show_sorted_data();
    
    std::cout << std::endl << "After bubble_sort:" << std::endl;
    Person1.bubble_sort();
    Person1.show_raw_data();
    Person1.show_sorted_data();
    
    return 0;
}
```

### Test It

Compile and run.

**Expected output:**
```
Before sorting:
Raw saving data: 3.6 5.7 2.3 3.2 2.5 3.8 5.2 0.9 1.1 4.3 2.7 8.3
Sorted saving data: 3.6 5.7 2.3 3.2 2.5 3.8 5.2 0.9 1.1 4.3 2.7 8.3

After bubble_sort:
Raw saving data: 3.6 5.7 2.3 3.2 2.5 3.8 5.2 0.9 1.1 4.3 2.7 8.3
Sorted saving data: 0.9 1.1 2.3 2.5 2.7 3.2 3.6 3.8 4.3 5.2 5.7 8.3
```

 Sorting works! Raw data unchanged, sorted data is in ascending order. Move on.

---

## Step 6: Add search_index Function

Add the search function:

```cpp
#include <iostream>

class Annual_Saving {
private:
    double raw_saving_data[12];
    double sorted_saving_data[12];

public:
    Annual_Saving(double data[]) {
        for (int i = 0; i < 12; i++) {
            raw_saving_data[i] = data[i];
            sorted_saving_data[i] = data[i];
        }
    }
    
    void show_raw_data() {
        std::cout << "Raw saving data: ";
        for (int i = 0; i < 12; i++) {
            std::cout << raw_saving_data[i];
            if (i < 11) {
                std::cout << " ";
            }
        }
        std::cout << std::endl;
    }
    
    void show_sorted_data() {
        std::cout << "Sorted saving data: ";
        for (int i = 0; i < 12; i++) {
            std::cout << sorted_saving_data[i];
            if (i < 11) {
                std::cout << " ";
            }
        }
        std::cout << std::endl;
    }
    
    void bubble_sort() {
        double temp;
        
        for (int i = 0; i < 11; i++) {
            for (int j = 0; j < 11 - i; j++) {
                if (sorted_saving_data[j] > sorted_saving_data[j + 1]) {
                    temp = sorted_saving_data[j];
                    sorted_saving_data[j] = sorted_saving_data[j + 1];
                    sorted_saving_data[j + 1] = temp;
                }
            }
        }
    }
    
    int search_index(double value) {
        for (int i = 0; i < 12; i++) {
            if (raw_saving_data[i] == value) {
                return i;
            }
        }
        return -1;
    }
};

int main() {
    double data1[] = {3.6, 5.7, 2.3, 3.2, 2.5, 3.8, 5.2, 0.9, 1.1, 4.3, 2.7, 8.3};
    
    Annual_Saving Person1(data1);
    
    std::cout << "Testing search_index:" << std::endl;
    Person1.show_raw_data();
    
    // Test searching for 5.7 (should be at index 1)
    std::cout << "Index of 5.7: " << Person1.search_index(5.7) << " (expected: 1)" << std::endl;
    
    // Test searching for 0.9 (should be at index 7)
    std::cout << "Index of 0.9: " << Person1.search_index(0.9) << " (expected: 7)" << std::endl;
    
    // Test searching for value not in array
    std::cout << "Index of 999: " << Person1.search_index(999) << " (expected: -1)" << std::endl;
    
    return 0;
}
```

### Test It

Compile and run.

**Expected output:**
```
Testing search_index:
Raw saving data: 3.6 5.7 2.3 3.2 2.5 3.8 5.2 0.9 1.1 4.3 2.7 8.3
Index of 5.7: 1 (expected: 1)
Index of 0.9: 7 (expected: 7)
Index of 999: -1 (expected: -1)
```

 Search works correctly for found and not-found cases. Move on.

---

## Step 7: Add Operator + Overload

Add the operator overloading:

```cpp
#include <iostream>

class Annual_Saving {
private:
    double raw_saving_data[12];
    double sorted_saving_data[12];

public:
    Annual_Saving(double data[]) {
        for (int i = 0; i < 12; i++) {
            raw_saving_data[i] = data[i];
            sorted_saving_data[i] = data[i];
        }
    }
    
    void show_raw_data() {
        std::cout << "Raw saving data: ";
        for (int i = 0; i < 12; i++) {
            std::cout << raw_saving_data[i];
            if (i < 11) {
                std::cout << " ";
            }
        }
        std::cout << std::endl;
    }
    
    void show_sorted_data() {
        std::cout << "Sorted saving data: ";
        for (int i = 0; i < 12; i++) {
            std::cout << sorted_saving_data[i];
            if (i < 11) {
                std::cout << " ";
            }
        }
        std::cout << std::endl;
    }
    
    void bubble_sort() {
        double temp;
        
        for (int i = 0; i < 11; i++) {
            for (int j = 0; j < 11 - i; j++) {
                if (sorted_saving_data[j] > sorted_saving_data[j + 1]) {
                    temp = sorted_saving_data[j];
                    sorted_saving_data[j] = sorted_saving_data[j + 1];
                    sorted_saving_data[j + 1] = temp;
                }
            }
        }
    }
    
    int search_index(double value) {
        for (int i = 0; i < 12; i++) {
            if (raw_saving_data[i] == value) {
                return i;
            }
        }
        return -1;
    }
    
    Annual_Saving operator+(Annual_Saving& other) {
        double sum_data[12];
        
        for (int i = 0; i < 12; i++) {
            sum_data[i] = this->raw_saving_data[i] + other.raw_saving_data[i];
        }
        
        return Annual_Saving(sum_data);
    }
};

int main() {
    double data1[] = {3.6, 5.7, 2.3, 3.2, 2.5, 3.8, 5.2, 0.9, 1.1, 4.3, 2.7, 8.3};
    double data2[] = {2.5, 7.2, 6.3, 8.3, 5.7, 3.4, 9.5, 0.3, 0.1, 0.9, 1.2, 6.1};
    
    Annual_Saving Person1(data1);
    Annual_Saving Person2(data2);
    
    std::cout << "Testing operator+:" << std::endl;
    std::cout << "Person1: ";
    Person1.show_raw_data();
    std::cout << "Person2: ";
    Person2.show_raw_data();
    
    Annual_Saving sum = Person1 + Person2;
    std::cout << "Sum:     ";
    sum.show_raw_data();
    
    // Verify first element: 3.6 + 2.5 = 6.1
    std::cout << std::endl << "Verification: 3.6 + 2.5 = 6.1 (check first element above)" << std::endl;
    
    return 0;
}
```

### Test It

Compile and run.

**Expected output:**
```
Testing operator+:
Person1: Raw saving data: 3.6 5.7 2.3 3.2 2.5 3.8 5.2 0.9 1.1 4.3 2.7 8.3
Person2: Raw saving data: 2.5 7.2 6.3 8.3 5.7 3.4 9.5 0.3 0.1 0.9 1.2 6.1
Sum:     Raw saving data: 6.1 12.9 8.6 11.5 8.2 7.2 14.7 1.2 1.2 5.2 3.9 14.4

Verification: 3.6 + 2.5 = 6.1 (check first element above)
```

 Operator overloading works correctly. Move on.

---

## Step 8: Final main() Function

Now write the final `main()` function exactly as specified in the question:

```cpp
#include <iostream>

class Annual_Saving {
private:
    double raw_saving_data[12];
    double sorted_saving_data[12];

public:
    Annual_Saving(double data[]) {
        for (int i = 0; i < 12; i++) {
            raw_saving_data[i] = data[i];
            sorted_saving_data[i] = data[i];
        }
    }
    
    void show_raw_data() {
        std::cout << "Raw saving data: ";
        for (int i = 0; i < 12; i++) {
            std::cout << raw_saving_data[i];
            if (i < 11) {
                std::cout << " ";
            }
        }
        std::cout << std::endl;
    }
    
    void show_sorted_data() {
        std::cout << "Sorted saving data: ";
        for (int i = 0; i < 12; i++) {
            std::cout << sorted_saving_data[i];
            if (i < 11) {
                std::cout << " ";
            }
        }
        std::cout << std::endl;
    }
    
    void bubble_sort() {
        double temp;
        
        for (int i = 0; i < 11; i++) {
            for (int j = 0; j < 11 - i; j++) {
                if (sorted_saving_data[j] > sorted_saving_data[j + 1]) {
                    temp = sorted_saving_data[j];
                    sorted_saving_data[j] = sorted_saving_data[j + 1];
                    sorted_saving_data[j + 1] = temp;
                }
            }
        }
    }
    
    int search_index(double value) {
        for (int i = 0; i < 12; i++) {
            if (raw_saving_data[i] == value) {
                return i;
            }
        }
        return -1;
    }
    
    Annual_Saving operator+(Annual_Saving& other) {
        double sum_data[12];
        
        for (int i = 0; i < 12; i++) {
            sum_data[i] = this->raw_saving_data[i] + other.raw_saving_data[i];
        }
        
        return Annual_Saving(sum_data);
    }
};

int main() {
    // Define two double arrays
    double data1[] = {3.6, 5.7, 2.3, 3.2, 2.5, 3.8, 5.2, 0.9, 1.1, 4.3, 2.7, 8.3};
    double data2[] = {2.5, 7.2, 6.3, 8.3, 5.7, 3.4, 9.5, 0.3, 0.1, 0.9, 1.2, 6.1};
    
    // Initialize two objects
    Annual_Saving Person1(data1);
    Annual_Saving Person2(data2);
    
    // Show raw data of Person1
    Person1.show_raw_data();
    
    // Sort Person1 and show sorted data
    Person1.bubble_sort();
    Person1.show_sorted_data();
    
    // Search for 9.5 in Person2 and print index
    int index = Person2.search_index(9.5);
    std::cout << "Index of 9.5 in Person2: " << index << std::endl;
    
    // Add Person1 + Person2 and show sum's raw data
    Annual_Saving sum = Person1 + Person2;
    sum.show_raw_data();
    
    return 0;
}
```

### Final Test

Compile and run.

**Expected output:**
```
Raw saving data: 3.6 5.7 2.3 3.2 2.5 3.8 5.2 0.9 1.1 4.3 2.7 8.3
Sorted saving data: 0.9 1.1 2.3 2.5 2.7 3.2 3.6 3.8 4.3 5.2 5.7 8.3
Index of 9.5 in Person2: 6
Raw saving data: 6.1 12.9 8.6 11.5 8.2 7.2 14.7 1.2 1.2 5.2 3.9 14.4
```

 All requirements complete!

---

## Summary Checklist

| Step | Requirement | Points | Status |
|------|-------------|--------|--------|
| 2 | Private attributes | 2 |  |
| 3-4 | Constructor + display functions | 4 |  |
| 5 | `bubble_sort` | 5 |  |
| 6 | `search_index` | 3 |  |
| 7 | Operator `+` overload | 6 |  |
| 8 | Main function | 10 |  |

**Total: 30 points**