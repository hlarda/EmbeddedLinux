#include<iostream>
using namespace std;

class base
{

public:
    base(/* args */){
        cout<<"base";
    }
    ~base(){
        cout<<"~base";
    }
};
class der:public base
{
public:
    der(/* args */){
        cout<<"der";
    }
    ~der
    (){
        cout<<"~der";
    }
};

int main(int argc, char const *argv[])
{
    der *n = new der;
    base *b = n;
    delete b;
    return 0;
}


