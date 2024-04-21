#include<iostream>
using namespace std;
/*
?what is cpy constructor
1. It is a special constructor that initializes a new object as a copy of an existing object
from another of the same type.
2.If a copy constructor is not defined in a class, the compiler itself creates one.
! what if uve pointer members 
1.copying an object also copies the pointers, not what they point to.
2.this is known as shallow copy.
3.now the source and the cpy both have pointers pointing to the same memory location and it leads to problems.
*For example:
if one object deletes the memory, the other will be left with a dangling pointer
that will cause the same effect to any kind of manipulation on the other object.
? Deep copy is the key.
not only copies the pointers but also the data they point to.
*/

class defaultWithPointerMembers{
private:
public:
    int x;
    char y;
    int *p;
    defaultWithPointerMembers()=default;
    defaultWithPointerMembers(int a, char b ,int *c):x(a),y(b),p(c){};
    void print(){
        cout << x << " " << y << " " << *p << endl;
    }
    ~defaultWithPointerMembers()=default;
};

class withCisCpyConstructor{
private:
public:
    int x;
    char y;
    withCisCpyConstructor()=default;
    /* cpy constructor*/
    withCisCpyConstructor(const withCisCpyConstructor& source):x(source.x),y(source.y){
        cout << "copy constructor called" << endl;
    }
    ~withCisCpyConstructor()=default;
    void print(){
        cout << x << " " << y << endl;
    }
};

class deepCpy{
private:
    /* data */
public:
    int x;
    int *p;
    deepCpy()=default;
    deepCpy(int a, int *b):x(a),p(b){}
    //copy constructor
    deepCpy(const deepCpy& source):x(source.x),p(new int(*source.p)){
        cout<<"deep cpy"<<endl;
    };
    void print(){
        cout << x << " " << *p << endl;
    }
    ~deepCpy()=default;
};

int main(int argc, char const *argv[])
{
    defaultWithPointerMembers obj1(1, 'a', new int(10));
    //copy constructor is not defined, the compiler itself creates one then calls it.
    defaultWithPointerMembers obj2(obj1);
    // changing the values of obj doesn't affect the cpy as these members are not pointers
    obj1.x = 0;     
    obj1.y = 'b';
    //but this affacts the cpy
    *(obj1.p)=15;
    obj1.print();
    obj2.print();

    withCisCpyConstructor obj3{};
    withCisCpyConstructor obj4(obj3);
    obj3.x = 1;
    obj3.y = 'a';
    obj3.print();
    obj4.print();

    deepCpy obj5(1, new int(20));
    deepCpy obj6(obj5);
    obj1.x = 0;     
    obj1.y = 'b';
    // now new assignment doesn't affect the cpy
    *(obj5.p)=15;
    obj5.print();
    obj6.print();
    return 0;
}
