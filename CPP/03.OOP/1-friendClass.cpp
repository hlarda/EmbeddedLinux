#include<iostream>
using namespace std;
/*not preferred to use*/
class friendClass;  //*forward decleration: as happens in fuction prototype

class mnna
{
private:
    friend class friendClass;   //?gives permission for friend class to access and manuplate private members 
    int nono{};
public:
    mnna(){
        cout<< nono<<endl;
    };
    ~mnna(){};
};

class friendClass
{
private:
    mnna obj;
public:
    friendClass(){
        obj.nono={10};
        cout<<obj.nono<<endl;
    }
    ~friendClass()=default;
};

int main(int argc, char const *argv[])
{
    friendClass lulu;
    return 0;
}