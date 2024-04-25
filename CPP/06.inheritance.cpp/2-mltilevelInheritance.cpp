#include<iostream>
using namespace std;

class base{
    public:
    void function (void){
        cout << "base" << endl;
    }
    void Parent (void){
        cout << "parent" << endl;
    }
};
class child : public base{
    public:
    void function (void){
        cout << "child" << endl;
    }
    void Child (void){
        cout << "child" << endl;
    }
};
class grandchild : public child{
    public:
    void function (void){
        cout << "grandchild" << endl;
    }
    void Grandchild (void){
        cout << "grandchild" << endl;
    }
};
int main(int argc, char const *argv[])
{
    grandchild lilo;
    lilo.function();
    lilo.child::function();
    lilo.base::function();
    lilo.Child();
    lilo.Parent();
    lilo.Grandchild();
    return 0;
}

