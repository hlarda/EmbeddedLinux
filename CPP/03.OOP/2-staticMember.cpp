/*
? static member is static for class not for each instance
used for example to count how many instances created  
*1. defined outside the class
*2. can be accessed through the class or any instance of it
*/
#include<iostream>
using namespace std;

class koko
{
private:
public:
    static int counter;
    koko(){
        counter++;
        cout<<counter<<endl;
    };
    ~koko()=default;
};

int koko::counter=0;

int main(int argc, char const *argv[])
{
    koko obj;
    koko obj1;
    koko obj2;
    koko obj3;

    cout << obj . counter <<endl;
    cout << koko::counter<<endl;

    return 0;
}
