#include<iostream>
#include<vector>
using namespace std;

#define NUM 10  // 10 is rvalue
int x = 10;     //x is lvalue
int &ref = x;   //ref is lvalue reference

void funLvalueRefArgument(int &ref) {
    cout << "ref is lvalue reference" << endl;
}

void funLvalueArgument(int x){
    cout << "x is lvalue" << endl;
}

void funConstLvalueRefArgument(const int &y) {
    cout << "y is const lvalue reference" << endl;
}

int funWithReturnIsRValue(){}

int global_var = 0;

int& getGlobalVar() {
    return global_var;
}

class String
{
private:
    string data;
public:
    String()=default;
    String(string data):data(data){}
    
    ~String();
};

int main(int argc, char const *argv[])
{
    int x = 20;
    int &ref = x;
    //*lvalue = rvalue | lvalue | lvalue reference*//
    funLvalueArgument(1);
    funLvalueArgument(x);
    funLvalueArgument(ref);

    //*lvalueref = lvalue | lvalue reference*//
    //funLvalueRefArgument(1);    //!error must be lvalue 
    funLvalueRefArgument(x);
    funLvalueRefArgument(ref);

    //*constLvalueref = const rvalue | lvalue | lvalue reference*//
    funConstLvalueRefArgument(1);
    funConstLvalueRefArgument(x);
    funConstLvalueRefArgument(ref);

    //* lvalue | const lvalue reference | const lvalue = rvalue
    int y = funWithReturnIsRValue();
    const int z = funWithReturnIsRValue();
    const int &ref = funWithReturnIsRValue();
    //int &ref = funWithReturnIsRValue();     //!error must be const lvalue reference or lvalue
    
//? however the return from function is Rvalue how to return Lvalue?//
    getGlobalVar() = 5;  // Assigns 5 to global_var
    int x = getGlobalVar();
    int &ref = getGlobalVar();
    const int &ref = getGlobalVar();



    return 0;
}
