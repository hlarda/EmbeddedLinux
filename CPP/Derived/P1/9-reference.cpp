#include <iostream>

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