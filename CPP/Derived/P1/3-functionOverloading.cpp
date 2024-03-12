#include <iostream>
/*
**1. the return type is meaningless the difference should be in arguments
**2. the function name should be the same
**3. the difference should be in the number of arguments or the type of arguments
**4. the default arguments are not considered as a difference
**5. they are totally different functions in asembly code
**/
int add(int a, int b) {
    return a + b;
}

double add(double a, double b) {
    return a + b;
}

int main() {
    int result1 = add(5, 10);
    double result2 = add(3.14, 2.71);

    std::cout << "Result 1: " << result1 << std::endl;
    std::cout << "Result 2: " << result2 << std::endl;

    return 0;
}