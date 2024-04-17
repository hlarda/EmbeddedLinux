#include<iostream>
using namespace std;

//* return type: reference to int *//
int& f(){
    static int x = 0;
    cout << x << endl;
    return x;    
}

int main(int argc, char const *argv[]){
    //* the value assigned to x after calling *//
    f() = 10;
    f() = 0;
    f() = 10;
    return 0;
}
