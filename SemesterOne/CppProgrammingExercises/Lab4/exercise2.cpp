#include <iostream>

/*
  What is a constructor?
  ----------------------
  - A special function with the SAME NAME as the class.
  - Called AUTOMATICALLY when an object is created.
  - Used to initialise internal data safely.

  Why use constructors instead of manually assigning values?
  ----------------------------------------------------------
  - Ensures every object starts in a valid and predictable state.
  - Prevents uninitialised memory bugs.

  What is an "initialisation list"?
  ---------------------------------
  - A special syntax ( : length(x), width(y) )
  - Runs BEFORE the constructor body.
  - More efficient and recommended for initializing variables.
*/

class Rectangle {
private:
    double length;
    double width;

public:
    // Default constructor -> provides safe, predictable defaults
    Rectangle() : length(0.0), width(0.0) {}

    // Parameterized constructor -> lets user set values immediately
    Rectangle(double len, double wid) : length(len), width(wid) {}

    double calculateArea() const {
        return length * width;
    }

    void displayArea() const {
        std::cout << "Area: " << calculateArea() << std::endl;
    }
};

int main() {
    Rectangle rect;             // default constructor
    Rectangle rect2(5.0, 3.0);  // parameterised constructor

    rect.displayArea();
    rect2.displayArea();
}

/*
Why the output looks like this:
-------------------------------

There are TWO Rectangle objects:

1. 'rect' uses the DEFAULT constructor.
      -> The default constructor sets:
            length = 0
            width = 0
   So its area is:
            0 * 0 = 0
   This produces:
      Area of the rectangle: 0

2. 'rect_2' uses the PARAMETERIZED constructor:
            Rectangle(5.0, 3.0)
      -> So length = 5, width = 3
   Its area is:
            5 * 3 = 15
   This produces:
      Area of the rectangle: 15

That is why two lines appear:
      0
      15
*/
