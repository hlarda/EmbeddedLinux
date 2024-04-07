#include<iostream>
/*error as y must be default argument as x */
/*once u wrote a defult the rest should be default*/
/*to resolve the error>> void function(int x, int y=5)*/
void function(int x=2, int y){
    std::cout << "x: " << x << " y: " << y << std::endl;
}

int main(){
    function(1, 2);
    function(1);
    return 0;
}