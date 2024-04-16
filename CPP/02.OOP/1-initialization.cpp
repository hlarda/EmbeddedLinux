#include<iostream>
#include<vector>
using namespace std;

int main(int argc, char const *argv[])
{
    //*Initialization of variables*//
    int a = 10;     //copy initialization
    int b(20);      //direct initialization
    int c{30};      //value initialization
    int d = {40};   //uniform initialization

    /*
    ? Narrowing conversion
    refers to a type conversion that might result in data loss or a compilation error. 
    This can occur when you try to convert a value of one type to a value of another type
    that cannot represent all the values of the original type.
    
    *for example
    if you try to convert a double to an int, 
    the fractional part of the double value will be lost. 
    This is a narrowing conversion because the int type cannot represent all the values that the double type can.
    */
    double  x = 3.14;
    int     y = x;   // Narrowing conversion: the fractional part of x is lost
    /*
    Similarly, if you try to convert a large int to a char, 
    the result might not fit in a char. This is also a narrowing conversion.
    */
    int  K = 300;
    char J = K;  // Narrowing conversion: y might not be able to hold the value of x
    /*
    !you can use list initialization (also known as brace initialization) 
    !to prevent narrowing conversions. 
    If you try to perform a narrowing conversion with list initialization, the code will not compile.
    */
    double o = 3.14;
    int p{o};  // warning: narrowing conversion from double to int

    /*
    ?zero initialization
    */
   int u=0;
   int v{}; //best practice
   int w(); // vexig parse error. the compiler deals with it as a function prototype.

    /*
    ! take care of the intialization form with vector
    */
    vector<int> vec1{2,10};
    vector<int> vec2(2, 10); //*this is direct constructor calling means initilize with 2 elements of 10
    return 0;
}
