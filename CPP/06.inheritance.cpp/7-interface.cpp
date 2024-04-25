/**
 * ? pure virtual function
 * a virtual function that the base class declares 
 * but does not define. 
 * It's a way to ensure that the base class cannot be instantiated 
 * and to enforce that derived classes provide an implementation for this function.
 * *is declared by assigning 0 in its declaration.
 * ? difference between abstract class and interface
 * !An abstract class
 * is a class that has at least one pure virtual function, 
 * and therefore, cannot be instantiated. 
 * It can have implemented methods (concrete methods) as well as 
 * pure virtual methods (methods without implementation).
 * !An interface
 * is an abstract class where all the methods are pure virtual.
 * This means that the class only declares the methods 
 * but doesn't provide any implementation for them. 
 * The classes that inherit from this interface must provide the implementation for all the methods.
*/
#include <iostream>
using namespace std;

class AbstractClass {
public:
    virtual void pureVirtualFunction() = 0; // Pure virtual function
    void concreteFunction() {
        cout << "Concrete function in AbstractClass." << endl;
    }
};
class Interface {
public:
    virtual void pureVirtualFunction1() = 0; // Pure virtual function
    virtual void pureVirtualFunction2() = 0; // Pure virtual function
};
class shape {
    public:
        virtual void draw() = 0; // pure virtual function
};

class circle : public shape {
    public:
        void draw() override {
            cout << "drawing circle..." << endl;
        }
};

class rectangle : public shape {
    public:
        void draw() override {
            cout << "drawing rectangle..." << endl;
        }
};

int main(int argc, char const *argv[])
{
    circle c;
    rectangle r;

    c.draw();
    r.draw();

    shape * shapes[] = {&c, &r};
    for(auto shape : shapes) {
        shape->draw();
    }
    return 0;
}
