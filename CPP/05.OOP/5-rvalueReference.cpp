#include<iostream>
#include<vector>
using namespace std;
/*
?What is Rvalue reference 
1.a right value reference is a type of reference that can bind to temporary objects (rvalues)
2.Temporary objects- rvalues- are typically stored in the stack or the heap.
    When you declare an rvalue reference and bind it to a temporary object, 
    the reference essentially refers to the memory location where the temporary object is stored.
3.this improves performance by eliminating unnecessary copying.
*/


void printString(std::string&& str) {
    /*only rvalue is accepted as parameter*/
    std::cout <<"Rvalue reference " <<str << std::endl;
}
void printString(std::string& str) {

    std::cout << "Lvalue reference " <<str << std::endl;
}
int main() {
    
    string str="mmm";
    string stri="aaaa";
    printString("nnnnn");  // "nnnnn" is an rvalue
    printString(str);   
    printString(str+stri);  // rvalue as the output of concatination is temp

    //? how to assign lvalue to rvalue reference ?//
    int x=10;
    //int &&rvalueRef=x;  //!error
    /*move() transferes ownership of some resource from x to rvalueRef, 
    without making a copy of the resource.*/
    int && rvalueRef = move(x);
    cout << rvalueRef << endl;
    cout << "x is in a valid but unspecified state, and you should not use it again unless you first assign it a new value." << x << endl;

    vector<int> v = {1,2,3,4,5,6,7,8,9,10};
    vector<int> vv = move(v);
    cout << v.size() << endl;
    cout << vv.size() << endl;

    return 0;
}