#include<iostream>
using namespace std;

class dddddd
{
private:
    int mem = 5;
public:
    dddddd() {};
    ~dddddd();
    void conFun(int x)const;
    void conFun(int x);
    void fun(void){}
};
void dddddd::conFun(int x) const {
    //* cant modify member variables but access
    //* to have the ability of modifying
    //just add mutable to variable decleration>> mutable int x;
    //! ERROR:   mem = x;
    cout << mem << endl;

    //* can access and manupulate its local variables
    x=30;
    cout << x << endl;
}
void dddddd::conFun(int x){
    cout <<"im the non-const with the same name"<<endl;
}
dddddd::~dddddd(){}

int main(int argc, char const *argv[])
{
    //* normal instance can access const and non-const fumctions
    //* but constant instance can only access const functions
    dddddd obj;
    const dddddd objj;
    //!ERROR: objj.fun();
    objj.conFun(5);

    //* incase having 2 methods with the same name 
    //*the const instance calls the const method
    //*the normal instance calls the nrmal method
    obj.conFun(5);
    objj.conFun(5);
    return 0;
}
