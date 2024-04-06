#include <iostream>

/*
Here are some key points about references:

A reference must be initialized when it's declared. For example: int &ref = num;

A reference always refers to the object it was initialized with. It cannot be changed to refer to another object.

A reference doesn't have its own memory address. When you take the address of a reference using the & operator, it returns the address of the object it refers to.

Modifying a reference modifies the original object. Similarly, modifying the original object modifies the reference.
*/
int main() {
    int num = 10;
    int& ref = num;

    std::cout << "Value of num: " << num << std::endl;
    std::cout << "Value of ref: " << ref << std::endl;
    std::cout << "Address of num: " << &num << std::endl;
    std::cout << "Address of ref: " << &ref << std::endl;

    ref = 20;

    std::cout << "Value of num after modifying ref: " << num << std::endl;
    std::cout << "Value of ref after modifying ref: " << ref << std::endl;
    std::cout << "Address of num: " << &num << std::endl;
    std::cout << "Address of ref: " << &ref << std::endl;
    return 0;
}