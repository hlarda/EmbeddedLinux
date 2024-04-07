/*
? what is class?
* A class is a blueprint for creating objects. 
* It defines the attributes and methods that the objects of the class will have.
* encapsulates data and functions that operate on that data(data + functions).
* The elements are called members(data member and member function or method).
? difference between class and struct?
* all members in struct is public but in class members can be set to private and accessed only by methods in the same class.
* class has constructor and destructor.
*/

#include <iostream>
using namespace std;

class human
{
private:
    string name;
    int age;
public:
    void born(void){}
    void die(void){}
};

int main(int argc, char const *argv[])
{
    /* creating instance then calling public methods */
    human hla;
    hla.born();
    hla.die();

    /*
    ?creating a temporary object
    * it will be destroyed at the end of the statement.
    *not a common practice
    */
    human().born();
    /*
    ?size of an object
    *size of datatypes + virtual pointer if exists + padding
    */
   cout << sizeof(human) << endl;
   cout << sizeof(string) << endl;
    cout << sizeof(int) << endl;
    return 0;
}
/*
? is it better to write the function implementation inside the class or outside it?
* it better to be written in outside the class 
* to be providded all the time in the object table 
* but implementing it in the class wont make it provided in the object table utill it is called
* write the body inside the class when it's templete or adstraction class
*/