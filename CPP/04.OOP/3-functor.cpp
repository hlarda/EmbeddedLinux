#include <iostream>
#include <functional>
using namespace std;

class mnna
{
private:
public:
     mnna(){
        cout << "constructor called" << endl;
     }
    ~mnna(){
        cout << "destructor called" << endl;
    }
    int nono = 10;
    void operator()(void) {
        cout << "im in functor thing and its actually is an overload of ()"<< endl;
        cout << "called with instance of class obj()" << endl;
    }
};

int main(int argc, char const *argv[]){
    mnna obj;
    obj();

    // *OR* //
    /*
    *thid creates temp object of class and calls the operator()
    */
    function<void(void)> functor = obj;
    cout << "before functor" << endl;
    functor();
    cout << "after functor" << endl;
    //!ERROR:int y = functor.nono;      >>'class std::function<void()>' has no member named 'nono'
    // that proves that its temporary object an not actual instance
    // canstructor is not called only distructor is
    return 0;
}
