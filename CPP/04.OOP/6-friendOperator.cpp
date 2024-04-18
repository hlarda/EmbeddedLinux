#include<iostream>
using namespace std;

/*
?in case the need to perform 5+c (c is an instance of class complex)
it is not possible to use operator + for 5+c as 5 is not an instance of class complex
it is not 5.operator+(c) 
* so we gonna create a friend operator
it is regular operator overloading but with the advantage of friend keyword- acessing private members-
*/

class complx
{
private:
    float real, img;
public:
    complx(/* args */)=default;
    complx(float r, float i):real(r),img(i){}
    ~complx()=default;
    friend float operator+(float f, complx c);
    void print(){
        cout << real << " + " << img<< "i" << endl;
    }
};
float operator+(float f, complx c){
    return f+c.real;
}

int main(int argc, char const *argv[]){
    complx c(1.5,3.5);
    float x = 1+c;
    cout << x << endl;
    c.print();
    return 0;
}