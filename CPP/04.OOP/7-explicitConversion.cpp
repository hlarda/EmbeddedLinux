#include<iostream>
using namespace std;

/*
* complex c = 2;
this will implicitly call the constructor with single integer argument c = complex(2) bs not clean w bdan 
?so instead of that write "explicit" before the constructor with single argument safer
*/
class complx
{
private:
    float real, img;
public:
    complx(/* args */)=default;
    explicit complx(int r):real(r),img(0){}
    complx(float r, float i):real(r),img(i){}
    ~complx()=default;
    void print(){
        cout << real << " + " << img<< "i" << endl;
    }
};


int main(int argc, char const *argv[]){
    //! complx c=2;
    complx c = complx(2);
    c.print();
    return 0;
}