/*
 *a inherits from b and c*
*/
#include <iostream>
using namespace std;

class base1{
    public:
        void function (void){   
            cout << "base1" << endl;    
        }
};
class base2{
    public:
        void function (void){   
            cout << "base2" << endl;    
        }
};
class child: public base1, public base2{
    public:
};
int main(){
    child obj;
    obj.base1::function();
    obj.base2::function();
    return 0;
}