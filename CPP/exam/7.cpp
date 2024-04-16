#include<iostream>

using namespace std;
class test
{
static int a;
public:
    test(/* args */){a++;}
    static int getA()
    {
        return a;
    }
};

int test::a = 0;
int main()
{
    cout << test::getA() << endl;
    test t[5];
    cout << test::getA() << endl;
    return 0;
}