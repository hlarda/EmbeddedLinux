#include<iostream>
using namespace std;

int add(int a, int b, int  c){
    return a+b+c;
}
double add(double a, double b, double c){
    return a+b+c;
}

int main(){
    cout << add(5, 10) << endl;
    cout << add(3.14, 2.71) << endl;
}
