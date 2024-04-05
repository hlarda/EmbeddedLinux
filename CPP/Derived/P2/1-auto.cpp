#include <iostream>
#include <typeinfo>
int main() {
    auto x = 10;  // x is deduced as int
    auto y = 3.14;  // y is deduced as double
    auto z = "Hello";  // z is deduced as const char*

    /*auto is not smart enough to deduce const int. u must explicitly specify it.*/
    const int   a = 10;
    const auto  b = a;  // b is deduced as const int
    auto        &c = a;  // b is deduced as int&
    auto        ptr = &a;  // b is deduced as const int*
    auto        intializerList = { 1, 2, 3 };  // b is deduced as std::initializer_list<int>

    

    std::cout << "x: " << x << ", type: " << typeid(x).name() << std::endl;
    std::cout << "y: " << y << ", type: " << typeid(y).name() << std::endl;
    std::cout << "z: " << z << ", type: " << typeid(z).name() << std::endl;
    std::cout << "a: " << a << ", type: " << typeid(a).name() << std::endl;
    std::cout << "b: " << b << ", type: " << typeid(b).name() << std::endl;
    std::cout << "c: " << c << ", type: " << typeid(c).name() << std::endl;
    std::cout << "ptr: " << ptr << ", type: " << typeid(ptr).name() << std::endl;

    /*types of intilization*/
    int x = 4;
    int y = { 4 };
    int z{ 4 };
    int w = int{ 4 };
    int v = int(4);
    
    return 0;
}
