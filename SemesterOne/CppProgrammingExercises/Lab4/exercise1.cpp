#include <iostream>

/*
  This code demonstrates basic OOP concepts in C++ using a Rectangle class.

  1. Encapsulation:
     - The idea that a class should HIDE its internal data and expose ONLY the
       operations that are safe and meaningful.
     - Here, `length` and `width` are PRIVATE, meaning code outside this class
       cannot modify them directly.
     - This prevents accidental or unsafe modification.
     - Instead, the class exposes public functions (e.g., setDimensions) that
       CONTROL how the internals are changed.

  2. Member Functions:
     - Functions that belong to an object and can access its private attributes.
     - For example, calculateArea() uses length and width even though they are private.

  3. Objects:
     - An instance of a class. Each Rectangle has its own length and width.

*/

class Rectangle {
private:
    double length;  // PRIVATE -> part of encapsulation
    double width;   // PRIVATE -> cannot be directly accessed outside the class

public:
    /*
      setDimensions:
        - A "setter" function.
        - Allows SAFE modification of private attributes.
        - Demonstrates how encapsulation gives controlled access.
    */
    void setDimensions(double len, double wid) {
        length = len;
        width = wid;
    }

    /*
      calculateArea:
        - Computes area.
        - Marked `const` because it does NOT change object state.
        - Shows how logic is grouped WITHIN the class that stores the data.
    */
    double calculateArea() const {
        return length * width;
    }

    /*
      displayArea:
        - Prints the result.
        - Demonstrates that an object can perform useful work with its own data.
    */
    void displayArea() const {
        std::cout << "Area of the rectangle: "
                  << calculateArea() << std::endl;
    }
};

int main() {
    Rectangle rect;              // object created
    rect.setDimensions(5.0, 3.0); // setting attributes
    rect.displayArea();           // internal function used
    return 0;
}

/*
Why the output looks like this:
-------------------------------

1. We create a Rectangle object called 'rect'.
2. We call rect.setDimensions(5.0, 3.0)
      -> This sets length = 5 and width = 3.
3. Then rect.displayArea() is called.
4. displayArea() calls calculateArea(), which multiplies:
         5 * 3 = 15
5. This value is printed.

So the final output is simply:
    Area of the rectangle: 15
*/

