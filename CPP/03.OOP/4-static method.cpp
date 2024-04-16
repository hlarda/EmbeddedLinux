/*
*1.accessable through ththe class and not related to any instance
so it is not allowed to use "this" 
*2. only allowed to manuplate static members
*/
#include <iostream>
using namespace std; 

class lilo
{
private:
    int x = 12;
    static int y;
public:
    static void func(void);
    lilo(/* args */);
    ~lilo();
};
int lilo :: y = 10;
void lilo::func(void){
    int local=3;
    //*x = 3;           not allowed as it's nonstatic
    //a nonstatic member reference must be relative to a specific object
    
    y++;        //static member
}
lilo::lilo(/* args */)
{
}

lilo::~lilo()
{
}

int main(int argc, char const *argv[])
{
    lilo lyla;
    lilo::func();
    lyla.func();
    return 0;
}
