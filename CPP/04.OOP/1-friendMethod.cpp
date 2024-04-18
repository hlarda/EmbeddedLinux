#include <iostream>
using namespace std;

/*
?friend method: 
1. method that can access private members of a class
2. it's invoked without instance of the class
3. it's not a member method
*/

class soso{
private:
    int x = 10;
public:
    soso()=default;
    ~soso()=default;
    friend void print();
};

void print(){
    soso s;
    cout << "accessing private member 3ade:   "<<s.x<<endl;
}

int main(int argc, char const *argv[]){
    print();
    return 0;
}

