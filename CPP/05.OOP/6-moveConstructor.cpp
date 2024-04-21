#include<iostream>
using namespace std;

class str
{
private:
public:
    string strr;
    str()=default;
    str(const string strr):strr(strr){cout<<"param"<<endl;}
    str(str&& expiredSource){
        cout<<"move"<<endl;
        if(this!=&expiredSource){
            strr=move(expiredSource.strr);
        }
    }
    str& operator=(str&& expiredSource){
        if(this!=&expiredSource){
            strr=move(expiredSource.strr);
        }
    }
    ~str(){
        cout<<"destr"<<endl;}
};

class Intot
{
private:
    int* p;
public:
    Intot():p(new int(0)){
        cout<<"default"<<endl;
    }
    Intot(int x):p(new int(x)){
        cout <<"param"<<endl;
    }   
    Intot(Intot&& expiredSource) : p(expiredSource.p){
        cout << "move" << endl;
        expiredSource.p = nullptr; // Prevent deleting the memory in the destructor
    }
    Intot& operator=(Intot&& expiredSource){
        if(this!= &expiredSource){
            delete p;
            p=expiredSource.p;
            expiredSource.p=nullptr;
        }
        return *this;
    }
    ~Intot(){
        cout<<"destr"<<endl;
        if(p!=nullptr){
            delete p;
            p=nullptr;  
        }

    }
};

int main(int argc, char const *argv[])
{
    str strSource("hello");
    str strDest(move(strSource));

    Intot intotSource(10);
    Intot intotDest(move(intotSource));

    return 0;
}

