#include<iostream>
using namespace std;

#define Enter       cout << "Entered:     "<<__PRETTY_FUNCTION__ << endl;
#define EXIT         cout << "Terminated:    "<<__PRETTY_FUNCTION__ << endl;
/*
*Entered:     int main(int, const char**)
*Entered:     void fun()
*Terminated:    void fun()
*Terminated:    int main(int, const char**)

? __PRETTY_FUNCTION__ == __func__ == __FUNCTION__ 
?but the out would be alittle different
*Entered:     main
*Entered:     fun
*Terminated:    fun
*Terminated:    main
*/

void fun(void){
    Enter;
    EXIT;
}
int main(int argc, char const *argv[])
{
    Enter;
    fun();
    EXIT;
    return 0;
}
