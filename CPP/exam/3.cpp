#include<iostream>
using namespace std;
 class a
 {
 public:
    a(/* args */){
        cout<<"hello";
    }
    ~a(){
        cout<<"world";
    }
 };

int main(int argc, char const *argv[])
{
    a *n = new a[5];
    delete n;
    return 0;
}
