#include<iostream>
using namespace std;
class A
{
    public:

    A(/* args */){
        cout<<"hello";
    }
    ~A(){
        cout<<"world";
    }
};
int main(int argc, char const *argv[])
{
    A *n = new A[5];
    delete[] n;
    return 0;
}
