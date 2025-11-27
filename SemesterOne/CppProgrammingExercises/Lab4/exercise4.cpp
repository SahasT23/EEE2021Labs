#include <iostream>
#include <cstring>

/*
  Why move semantics?
  -------------------
  Copying large data (like strings or arrays) is slow.
  Move semantics allow *transferring ownership* of memory
  instead of copying the entire buffer.

  What does std::move do?
  -----------------------
  - It DOES NOT move anything.
  - It simply tells the compiler:
      "Treat this object as a temporary (rvalue). It is safe to steal from it."

  Move constructor:
  -----------------
  - Copies the pointer only.
  - Does NOT allocate new memory.
  - Sets source pointer to nullptr to avoid double deletion.

  This is extremely fast, compared to the previous methods.
*/

class MyString {
private:
    char* data;
    std::size_t size; // size_t is from C++ version C++23, you might need to write your own method. 

public:
    MyString() : data(nullptr), size(0) { // default constructor
        std::cout << "Default Constructor\n";
    }

    MyString(const char* str) : size(std::strlen(str)) { // parameterised constructor, which allocates memory
        data = new char[size + 1];
        std::strcpy(data, str);
        std::cout << "Parameterized Constructor\n";
    }

    // Deep copy constructor
    MyString(const MyString& other) : size(other.size) { // The deep copy constructor is needed because we are allocating new memory.
        data = new char[size + 1];
        std::strcpy(data, other.data);
        std::cout << "Copy Constructor\n";
    }

    // Move constructor (steals the pointer)
    MyString(MyString&& other) noexcept : data(other.data), size(other.size) { // The move constructor works by reallocating the pointer from the source object.
        other.data = nullptr;
        other.size = 0;
        std::cout << "Move Constructor\n";
    }

    ~MyString() {
        delete[] data;
        std::cout << "Destructor\n";
    }

    void display() const {
        std::cout << "Data: " << (data ? data : "null")
                  << ", Size: " << size << "\n";
    }
};

int main() {
    MyString a("Hello");
    MyString b = a;             // copy constructor
    MyString c = std::move(a);  // move constructor
}

/*
Why the output looks like this:
-------------------------------

1. MyString str1("Hello, World!");
      -> Calls the PARAMETERIZED constructor.
        Prints: "Parameterized Constructor"

2. MyString str2 = str1;
      -> Uses the COPY CONSTRUCTOR because str1 is an lvalue.
        Prints: "Copy Constructor"

   Printing str1 and str2 shows they BOTH contain:
        Data: Hello, World!, Size: 13
   because the deep copy duplicated the string.

3. MyString str3 = std::move(str1);
      -> std::move tells the compiler str1 can be "stolen from".
      -> Calls the MOVE CONSTRUCTOR.
        Prints: "Move Constructor"

   After moving:
      - str3 now owns the string
      - str1 has been emptied (data = nullptr)

   So printing them shows:
      str3 -> "Hello, World!"
      str1 -> "null" (because its pointer was reset)

4. At the end of main(), all THREE objects are destroyed.
   Each destructor prints:
        "Destructor"

   The order of destructor messages may vary, but there are always three.
*/
