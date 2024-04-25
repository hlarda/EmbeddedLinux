/**
 * ? Function Overriding: 
 * Function overriding is a feature in OOP
 * where a subclass provides a different implementation for a function 
 * that is already defined in its superclass. 
 * The function in the subclass must have 
 * the same name, return type, and parameters as the one in the superclass.
 * ? virtual pointer:
 * when a class has a virtual function, 
 * the compiler creates a hidden member variable in the class, 
 * called a virtual pointer (vptr).
 * When you call a virtual function on an object 
 * through a base class pointer or reference, 
 * the compiler uses this virtual pointer to determine 
 * which version of the function to call 
 * based on the actual type of the object at runtime. 
 * This process is called dynamic dispatch or runtime polymorphism.
*/


#include <iostream>
using namespace std;

class shape {
    public:
        virtual void draw() {
            cout << "drawing..." << endl;
        }
};

class circle : public shape {
    public:
        void draw() {
            cout << "drawing circle..." << endl;
        }
};

class rectangle : public shape {
    public:
        void draw() {
            cout << "drawing rectangle..." << endl;
        }
};

void drawShape(shape &s) {
    s.draw();
}
int main(int argc, char const *argv[])
{
    circle c;
    rectangle r;
    drawShape(c);
    drawShape(r);

    shape *s ;
    s = &c;
    s->draw();
    s = &r;
    s->draw();

    return 0;
}
