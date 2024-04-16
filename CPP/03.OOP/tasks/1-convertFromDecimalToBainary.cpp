#include <bitset>
#include <iostream>
using namespace std;

/*
*bitset<10> binary(decimal); 
*this is creating a bitset object named binary 
*that holds the 10-bit binary representation of the integer num.
*/
int main() {
    int decimal = 10;
    bitset<10> binary(decimal);
    cout << binary;
    return 0;
}