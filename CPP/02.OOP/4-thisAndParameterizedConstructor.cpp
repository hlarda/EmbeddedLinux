#include<iostream>
using namespace std;

class human
{
private:
    string name;
    int age;
public:
    /* 
    ?incase u wont write implementation for the default constructor
    * human(){}; or human()=default;
    ?defult constructor is not mandatory as it is created by compiler
    *as long as u didnt define any other constructor.
    *if u did, implement it in the class
    !or u can just delete it
    * human()=delete;
    * or any other constructor
    */
    human();
    human(string n, int a);
    ~human();
};

human::human(){
    cout << "default constructor" << endl;  
}
human::~human(){
    cout << "destructor" << endl;
}
/*
! better to intailize the member variables with initializer list not in the constructor body
human::human(string name , int age):name(name), age(age){
    cout << "parameterized constructor" << endl;
}
* this provides fewer assembly instructions?? 
1. the initlization happends by default with grabge value like 
human::human(string name , int age):name(), age(){};
2.the intializer list is executed before the constructor body 
??? f tol ma kda kda hy7sl leh mktbosh w awfr w2t???
*/
human::human(string name , int age){
    this->name = name;
    this->age = age;
    cout << "parameterized constructor" << endl;
    cout << this << endl;

}

int main(int argc, char const *argv[])
{
    human lelo("lelo", 3);
    cout << &lelo << endl;
    return 0;
}
