#include<iostream>
#include<vector>
using namespace std;

/*he's asked for class but i think there is no need*/
vector<string> backtrace;

#define Enter       cout << "Entered:     "<<__PRETTY_FUNCTION__ << endl;backtrace.push_back(__PRETTY_FUNCTION__);
#define EXIT        cout << "Terminated:    "<<__PRETTY_FUNCTION__ << endl;backtrace.push_back(__PRETTY_FUNCTION__);
#define PRINT_BT    cout << "Backtrace: " << endl;for(string s : backtrace){ cout << s << endl; }backtrace.clear();
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
    PRINT_BT;
    return 0;
}
