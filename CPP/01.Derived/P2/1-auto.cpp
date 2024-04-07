#include <iostream>
#include <typeinfo>
using namespace std;
int main() {
    auto x = 10;  // x is deduced as int
    auto y = 3.14;  // y is deduced as double
    auto z = "Hello";  // z is deduced as const char*

    /*auto is not smart enough to deduce const int. u must explicitly specify it.*/
    const int   a = 10;
    auto        notSmart=a;     //  int 
    const auto  b = a;          //  const int
    /*
    !with reference and pointer auto is smart enough to know if it is const or not*/
    auto        &c = a;         //  const int &
    auto        ptr = &a;       //  const int *

    auto        intializerList = { 1, 2, 3 };  // std::initializer_list<int>

    

    std::cout << "x: " << x << ", type: " << typeid(x).name() << std::endl;
    std::cout << "y: " << y << ", type: " << typeid(y).name() << std::endl;
    std::cout << "z: " << z << ", type: " << typeid(z).name() << std::endl;
    std::cout << "a: " << a << ", type: " << typeid(a).name() << std::endl;
    std::cout << "b: " << b << ", type: " << typeid(b).name() << std::endl;
    std::cout << "c: " << c << ", type: " << typeid(c).name() << std::endl;
    std::cout << "ptr: " << ptr << ", type: " << typeid(ptr).name() << std::endl;

    /*forms of intilization*/
    int s = 4;
    int q = { 4 };
    int v{ 4 };
    int w = int{ 4 };
    int p = int(4);
    
    //* auto can be used in lamda function  as a return type and as a parameter*//
    //* without specifying the return type *//
    auto add = [](auto x, auto y) {
        return x + y;
    };

    std::cout << typeid(add(1, 2)).name() << std::endl;
    std::cout << typeid(add(2.5, 2)).name() << std::endl;
    std::cout << typeid(add(1, 2.5F)).name() << std::endl;
    return 0;
}
