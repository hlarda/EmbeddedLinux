#include<iostream>
using namespace std;

class complex
{
private:
    int real, img;
public:
    complex(/* args */)=default;
    ~complex()=default;
    complex operator++(){
        real++;
        img++;
        return *this;
    }
    /*
    *extra parameter of postfix 'operator++' must be of type 'int'*/
    complex operator++(int){
        complex temp = * this;
        real++;
        img++;
        return temp;
    }

    void print(){
        cout << real << " " << img<< "i" << endl;
    
    }
};

int main(int argc, char const *argv[])
{
    complex c1{}, c2{};
    complex c3, c4;

    c3 = c1++;  // ?Post-increment:  c1 is incremented after the assignment
    c4 = ++c2;  // ?Pre-increment:   c2 is incremented before the assignment

    c1.print();  
    c2.print();  
    c3.print();  
    c4.print();  

    return 0;
}

