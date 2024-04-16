#include<iostream>
using namespace std;
int fun(int=0,int = 0);
int main(int argc, char const *argv[])
{
    cout<<fun(10);
    return 0;
}
int fun(int a,int b){
    return a+b;
}