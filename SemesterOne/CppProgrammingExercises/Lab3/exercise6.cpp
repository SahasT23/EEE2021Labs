
#include <iostream>
#include <string>

/*
 * =============================================================
 * LAB 3 - PROBLEM 6: BOOK CLASS
 * =============================================================
 * THEORY:
 * Demonstrates simple class encapsulation with a constructor
 * and a display() member function.
 */

class Book {
private:
    std::string title;
    std::string author;
    int year;

public:
    Book(std::string t, std::string a, int y)
        : title(t), author(a), year(y) {}

    void display() const {
        std::cout << "Title: " << title
                  << "\nAuthor: " << author
                  << "\nYear: " << year << "\n";
    }
};

int main() {
    Book b("1984", "George Orwell", 1949);
    b.display();
    return 0;
}
