#include<iostream>
using namespace std;

/*
?constexpr declares that it is possible to evaluate the value of the function or variable at compile time. 
This can be used to improve performance, as it allows some computations to be done at compile time rather than at runtime.
*/

constexpr int square(int x) {
    return x * x;
}

int main(){
/*
?constexpr variables: 
A constexpr variable must be initialized with a constant expression. 
Its value is computed at compile time.
*/
constexpr int a = 10;  
constexpr int b = a * 2;  
/*
?constexpr functions: 
A constexpr function can be used in constant expressions, 
The function must have a non-void return type and 
must consist of a single return statement that returns a constant expression.
*/
constexpr int c = square(10);  

/*
!Remember that constexpr specifies that something can be computed at compile time, 
but it doesn't require it. 
!If a constexpr function or variable is used with values that are not known at compile time, 
!it will be evaluated at runtime like a regular function or variable.
*/
int d = 10;
//*This is computed at compile time 
//*as the argument and the return value 
//*are constant expression known at compile time
constexpr int b = square(3);  
//*This is computed at runtime
//*as the argument and the return value 
//*are not constant expression known at compile time
int c = square(d);  
}
