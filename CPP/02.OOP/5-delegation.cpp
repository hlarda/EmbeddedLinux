#include<iostream>  
using namespace std;
/*
* with delegation we cant intilize with intilizer list in the constructor
*/
class delegation
{
private:
    /* data */
public:
    delegation();
    delegation(int arg1);
    delegation(int arg1, int arg2);
    ~delegation();

};

delegation::delegation(){
    cout << "default constructor" << endl;
}
delegation :: delegation(int arg1):delegation(){
    cout << "constructor with arg1" << endl;
}
delegation :: delegation(int arg1, int arg2):delegation(arg1){
    cout << "constructor with arg1 and arg2" << endl;
}
delegation::~delegation(){
}

int main(int argc, char const *argv[])
{
    delegation obj(1, 2);
    return 0;
}
