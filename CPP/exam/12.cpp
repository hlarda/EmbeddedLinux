#include<iostream>
using namespace std;
class a
{
int j;
public:
    void print(int x){
        cout << x << endl;
    }
};
class b : public a{
    int i;
    public:
    void assign(int x){
        i = x;
    }
}

