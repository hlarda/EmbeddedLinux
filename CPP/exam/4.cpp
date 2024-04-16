#include<iostream>
using namespace std;

class base
{
public:
base(){cout<<"base";};
~base(){cout<<"~base";}

class derived : public base
{ 
    public:
derived(){cout<<"derived";};
~derived(){cout<<"~derived";}};

int main(){
    derived *d = new derived();
    base *b = d;
    delete b;
    return 0;
}
