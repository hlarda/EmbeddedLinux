#include<iostream>
using namespace std;
class a
{
private:
    int x;
public:
    a(int _x){x=_x;}
    int get(){return x;}
};

class b
{
static a a1;
public:
    static int get(){return a1.get();}
};
int main(int argc, char const *argv[])
{
    b b1;
    cout<<b1.get();
    return 0;
}

