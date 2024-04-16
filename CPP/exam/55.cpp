#include<iostream>
#include<string>
using namespace std;

class test
{
private:
    static int count;
public:
    test& fun();
};
int test :: count = 0;
test& test :: fun()
{
    test::count++;
    cout << test::count << endl;
    return *this;
}
int main(int argc, char const *argv[])
{
    test t;
    t.fun().fun().fun().fun();
    return 0;
}
