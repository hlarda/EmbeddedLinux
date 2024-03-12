#include <iostream>

// Function to add two numbers
int add(int a, int b) {
    return a + b;
}

// Function to subtract two numbers
int subtract(int a, int b) {
    return a - b;
}

int main() {
    // Declare a pointer to a function that takes two integers as arguments and returns an integer
    int (*operation)(int, int);

    // Assign the address of the add function to the pointer
    operation = add;

    // Call the function using the pointer
    int result = operation(5, 3);
    std::cout << "Result of addition: " << result << std::endl;

    // Assign the address of the subtract function to the pointer
    operation = subtract;

    // Call the function using the pointer
    result = operation(5, 3);
    std::cout << "Result of subtraction: " << result << std::endl;

    return 0;
}