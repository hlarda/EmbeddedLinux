#include <iostream>
/*
The following objdump command is used to display the symbol table entries of the 'a.exe' executable file.
This is particularly useful for debugging or analyzing the binary.

$ objdump -t a.exe | grep add
[116](sec  1)(fl 0x00)(ty   20)(scl   2) (nx 1) 0x0000000000000450 _Z3addii
[118](sec  1)(fl 0x00)(ty   20)(scl   2) (nx 0) 0x0000000000000464 _Z3adddd
[619](sec  1)(fl 0x00)(ty   20)(scl   2) (nx 0) 0x0000000000001000 ___w64_mingwthr_add_key_dtor

TO see the actual function names use the --demangle option
$ objdump -t a.exe --demangle | grep add
[116](sec  1)(fl 0x00)(ty   20)(scl   2) (nx 1) 0x0000000000000450 add(int, int)
[118](sec  1)(fl 0x00)(ty   20)(scl   2) (nx 0) 0x0000000000000464 add(double, double)
[619](sec  1)(fl 0x00)(ty   20)(scl   2) (nx 0) 0x0000000000001000 ___w64_mingwthr_add_key_dtor

_Z3addii >> stands for int add(int a, int b)
_Z3adddd >> double add(double a, double b)*/
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