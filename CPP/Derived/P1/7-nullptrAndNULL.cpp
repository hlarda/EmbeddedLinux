#include <iostream>
/*
*`NULL` and `nullptr` are both used in C++ to represent null pointers, but there are some important differences between them:

1. `NULL` is a macro that is typically defined as either `0` or `(void*)0`. 
! This means that `NULL` can be used in places where an integer is expected, which can lead to some unexpected behavior.

2. `nullptr`, on the other hand, is a keyword introduced in C++11 that represents a null pointer value. 
It has its own type, `std::nullptr_t`, which can implicitly convert to any pointer type, 
but not to integers or other types. This makes `nullptr` safer and more predictable to use than `NULL` in most cases.
*/

void foo(int* ptr) {
    if (ptr == nullptr) {
        std::cout << "Pointer is nullptr" << std::endl;
    } else {
        std::cout << "Pointer is not nullptr" << std::endl;
    }
}
void foo(int ptr) {
    std::cout << "function of int argument" << std::endl;
}
int main() {
    int* ptr1 = nullptr; // Test with nullptr
    int* ptr2 = NULL; // Test with NULL (should be avoided in modern C++ and supposed to make error in C++11 and later versions)

    int value = 5;
    int* ptr3 = &value;         // Test with a pointer to an integer
    int* ptr4 = new int(10);     // Test with a pointer to a dynamically allocated integer

    foo(ptr1);
    foo(ptr2);  // ! might call foo(int ptr) instead of foo(int* ptr) depending on null defination
    foo(ptr3);
    foo(ptr4);

    delete ptr4; // Don't forget to delete dynamically allocated memory
    ptr4 = nullptr; // Reset the pointer to nullptr
    return 0;
}

/* 
*(*)raw pointers 
are not used in modern cpp. u may use it when using legacy code (integrating c with cpp code)*/

/* size of pointer = word size*/

/*ptr + 1 >> increments with size of pointee*/
