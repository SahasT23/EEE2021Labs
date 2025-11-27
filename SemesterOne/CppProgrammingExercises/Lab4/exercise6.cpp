#include <iostream>
#include <string>

/*
  This class demonstrates:
  ------------------------
  - Constructor initialisation
  - Encapsulation of book data
  - Simple data model for objects

  What is a data model?
  ---------------------
  A class that represents a real-world object using attributes.
  Here:
    - title
    - author
    - publicationYear
  represent the state of a `Book`.
*/

class Book {
private:
    std::string title; // Properties of the Book class
    std::string author;
    int publicationYear;

public:
    // Constructor initialises values immediately using an initialiser list
    // The initialiser list works by assigning values directly to the member variables.
    Book(const std::string& t, const std::string& a, int y)
        : title(t), author(a), publicationYear(y) {}

    void display() const {
        std::cout << "Title: " << title << "\n"
                  << "Author: " << author << "\n"
                  << "Year: " << publicationYear << "\n";
    }
};

int main() {
    Book b("1984", "George Orwell", 1949);
    b.display();
}

/*
Why the output looks like this:
-------------------------------

1. The Book object is created with:
       title = "1984"
       author = "George Orwell"
       publicationYear = 1949

2. display() simply prints these values exactly as they were provided.

So the program outputs:
      Title: 1984
      Author: George Orwell
      Publication Year: 1949
*/
