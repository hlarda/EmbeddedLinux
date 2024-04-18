#include<iostream>
using namespace std;

class complx
{
private:
    float real, img;
public:
    complx(/* args */)=default;
    complx(float r, float i):real(r),img(i){}
    ~complx()=default;
    operator int(){
        return static_cast<int>(real);
    }
    operator string(){
        return to_string(real)+"+"+to_string(img)+"i";
    }
    void print(){
        cout << real << " + " << img<< "i" << endl;
    }
};

int main(int argc, char const *argv[]){
    complx c(1.5,3.5);
    int x = c;
    string y = c;

    c.print();
    cout << x << endl;
    cout << y << endl;
    return 0;
}
