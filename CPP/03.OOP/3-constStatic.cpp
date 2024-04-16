#include<iostream>
using namespace std; 

/*
*static const is used only with integral and enumeration type
*/

struct k
{
    //? it can be defined here or outside 
    //*but always define out as if u dont it will represented as const expr in assembly 
    //*and not represented as value with reference address
    const static int n = 1;
    const static int y ;

    const static int m{2};

    //! Error: static const string d = "jjk";
};
const int k::y = 30;

class defineOutside
{
private:
public:
    static const int h = 5;
    defineOutside(/* args */);
    ~defineOutside();
};
//const int defineOutside::h=5;
defineOutside::defineOutside(/* args */)
{
}

defineOutside::~defineOutside()
{
}

void fun(const int &a){
    cout <<a<<endl;
}

int main()
{
    cout<<defineOutside::h<<endl;
    fun(defineOutside::h);          //*undefined reference to `defineOutside::h'
    //?to resolve this error:  define the static const variable outside the class
    return 0;
}

