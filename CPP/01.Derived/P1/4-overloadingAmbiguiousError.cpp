#include <iostream>

// Function to add two integers
void add(int a, int b=5) {
    std::cout << "Sum of two integers: " << a + b << std::endl;
}

// Function to add two floating-point numbers
void add(int a, float b=5) {
    std::cout << "Sum of an integer and a floating-point number: " << a + b << std::endl;   
}

int main() {
    /*NOW it cant decide wether to execute as both has int first argument*/
    /*To resolve the error>> pass the second argument*/
    add(5);
    return 0;
}