/*
* b and c inherit from a
* d inherits from b and c
*/

#include <iostream>
using namespace std;

class a{
    public:
        void display() { cout << "a"<<endl; }
};
class b : virtual public a{
    public:
        void display() { cout << "b"<<endl; }
};
class c : virtual public a{
    public:
        void display() { cout << "c"<<endl; }
};
class d : public b, public c{
    public:
        void display() { cout << "d"<<endl; }
};
int main()
{
    d d1;
    d1.display();
    d1.b::display();
    d1.c::display();
    //! d1.a::display();        base class "a" is ambiguous
    /*To resolve this, you can use virtual inheritance. 
    This ensures that only one copy of the base class a 
    is included in any object of class d. */
    //*after adding virtual*//
    d1.a::display();
    return 0;
}