#include<iostream>
using namespace std;

class baseSingleIn{
public:
    void print(void){
        cout << "base " << endl;
    }
    void parent (void){ }
    baseSingleIn(/* args */){
        cout << "base  constructor" << endl;
    }
    ~baseSingleIn(){
        cout << "base  destructor" << endl;
    }
};
class derivedSingleIn :public baseSingleIn{
private:
public:
    void print(void){
        cout << "derived " << endl;
    }
    void child (void){ }
    derivedSingleIn (/* args */){
        cout << "derived  constructor" << endl;
    }
    ~derivedSingleIn (){
        cout << "derived  destructor" << endl;
    }
};

int main(int argc, char const *argv[])
{
    derivedSingleIn d;
    d.child();
    d.parent();
    d.print();
    d.baseSingleIn::print();
    return 0;
}
