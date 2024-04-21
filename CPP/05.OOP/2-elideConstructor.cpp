#include<iostream>
using namespace std;

/*
?elide constructor: 
it refers to "copy elision". 
Copy elision is an optimization implemented by most C++ compilers to eliminate unnecessary copying and constructing of objects.

*For example:
when returning an object from a function 
-without optimization-
a temporary object may be created and then copied to the location where the function's return value is stored.
With copy elision, 
the compiler is allowed to skip creating the temporary object and construct the return value directly in the location where it is stored. 
This can significantly improve performance, especially for large objects.
! to force the compiler to call it 
$ g++ 2-elideConstructor.cpp -O0 -fno-elide-constructors -std=c++14
*/

class ex
{
private:
public:
    ex(/* args */)=default;
    ex(const ex& cpy){
        cout<<"copy constructor called"<<endl;
    }
    ~ex()=default;
};

ex fun(){
    return ex();
}

int main(int argc, char const *argv[])
{
    ex obj(fun());
    return 0;
}
