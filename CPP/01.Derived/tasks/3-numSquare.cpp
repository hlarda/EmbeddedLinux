#include<iostream>
using namespace std;

int main(){
    auto sqr = [](int x){return x*x;};
    int num;
    cout<<"Enter a number to square:    ";
    cin>>num;
    cout<<sqr(num)<<endl;
    return 0;
}
