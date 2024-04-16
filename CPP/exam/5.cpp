#include<iostream>
using namespace std;
class A
{
    ~A(){
        cout<<"hello";
    }
};
int main(int argc, char const *argv[])
{
    A *d=new A();
    A*k=new A();
    return 0;
}
