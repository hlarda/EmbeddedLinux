#include<iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    string str = "123.5";

    //? converts from string to long
    auto lng = stol(str);
    cout << lng << endl;    
    cout << typeid(lng).name() << endl;

    //? converts from string to double
    auto dbl = stod(str);
    cout << dbl << endl;
    cout << typeid(dbl).name() << endl;

    //? converts from string to int
    auto intg = stoi(str);
    cout << intg << endl;
    cout << typeid(intg).name() << endl;

    return 0;
}

