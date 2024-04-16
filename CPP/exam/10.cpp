#include<iostream>
#include<cstring>
#include<string>
using namespace std;

int main(int argc, char const *argv[])
{
    const char *s = "hello\0world";
    cout << s;
    return 0;
}
