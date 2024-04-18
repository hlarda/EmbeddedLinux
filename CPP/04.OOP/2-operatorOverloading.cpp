#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*
!some operators can't be overloaded
1. logical  && || 
2. &
3.scope operator ::
4. dot .
5. ternary ?:
6. pointer to member .*
7.sizeof 

? sometimes u may hve to overload some operators
such as < for sort in vector in STL 
*/
class complex
{
private:
public:
    int real, img;
    complex()=default;
    complex(int r, int i);
    ~complex()=default;
    complex operator+(complex comp);
    bool operator<(const complex& comp) const ;
};

complex complex::operator+(complex comp){
    complex temp;
    temp.real = real + comp.real;
    temp.img = img + comp.img;
    return temp;
}

complex::complex(int r, int i):real(r),img(i){}

bool complex::operator<(const complex& comp) const {
    return (real < comp.real)&&(img < comp.img);
}
int main(int argc, char const *argv[])
{
    complex x(1,2), y(3,4);
    complex z = x + y;
    cout << z.real << " + " << z.img << "i" << endl;

    vector<complex> v{x, y};
    sort(v.begin(), v.end());
    /*
    !ERROR: to resolve overload operator< for sort
    no match for 'operator<' (operand types are 'complex' and 'complex')   
    69 |       { return *__it < __val; }
       |                ~~~~~~^~~~~~~*/
    for(complex c : v){
        cout << c.real << " + " << c.img << "i" << endl;
    }
    return 0;
}

