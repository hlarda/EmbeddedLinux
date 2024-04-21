#include<iostream>
using namespace std;
/*
!RSII
RAII stands for Resource Acquisition Is Initialization.
It's a programming idiom used in C++ where the lifetime of a resource (such as memory allocation, file handle, network socket, etc.) is tied to the lifetime of an object.

When an object is created (initialized), it acquires the resource. 
When the object is destroyed, it releases the resource. This is done in the constructor and destructor of the class, respectively.

In the constructor of toCpy, a resource (in this case, memory) is acquired with new. 
In the destructor of toCpy, the same resource is released with delete to prevent memory leak.

it provides automatic resource management.

? Assigning nullptr to a pointer after deleting it is a good practice 
to avoid what's known as a "dangling pointer".

*A dangling pointer: 
is a pointer that points to memory that has been deleted or deallocated. 
If you try to access the memory through a dangling pointer, undefined behavior can occur.*/
class toCpy
{
private:
public:
    int x;
    int* p;
    toCpy()=default;
    toCpy(int x, int* p):x(x),p(p){};
    toCpy(const toCpy& source):x(source.x),p(new int(*source.p)){
        cout << "cpy constructor" << endl;
    }
    toCpy& operator=(const toCpy& source){
        cout << "cpy assignment" << endl;
        if(this != &source){        /*to prevenent self assignment*/
            if( p ){
                delete p;
                p = nullptr;
            }
            x = source.x;
            p = new int(*source.p);
        }
        return *this;
    }
    ~toCpy(){
        if( p ){
            delete p;
            p = nullptr;
        }
    };
    void print(){cout << x << " " << *p << endl;}
};

int main(int argc, char const *argv[])
{
    toCpy obj1(1, new int(10));
    toCpy obj2(obj1);           //cpy constructor is called 
    toCpy obj3(2, new int(20));
    toCpy obj4 = obj3;          //cpy constructor is called

    obj1.print();
    obj2.print();
    obj3.print();

    obj3=obj1;      //cpy assignment is called
    obj3.print();
    
    return 0;
}

