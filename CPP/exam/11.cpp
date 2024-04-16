#include<iostream>
using namespace std;
class point
{
int x,y;
public:
    point(int i = 0,int j = 0){
        x = i;
        y = j;
    }
    int getX() const{
        return x;
    }
    int getY() {
        return y;
    }
};
int main(int argc, char const *argv[])
{
    const point t;
    cout<<t.getX()<<" "<<t.getY();
    return 0;
}

