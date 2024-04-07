
#include<iostream>
using namespace std;

enum Color{ 
    RED, 
    YELLOW, 
    GREEN };

enum class Colorr { RED, GREEN, BLUE };
enum class Alert { RED, YELLOW, GREEN };  // No error: RED is only visible within the scope of the enum

int main(int argc, char const *argv[]){
/*
!problems of using enum with c style in cpp
*there is no code abstraction or safety
u can access the enumerators from without scope operator anywhere in the code
*/
   Color objj;
   cout << objj << endl;
   cout << RED << endl;
/* 
*what if i has multiple enums with the same name in the same scope?: 
enum Color { RED, GREEN, BLUE };
enum Alert { RED, YELLOW, GREEN };  // Error: RED is already defined in this scope
*size-wise, enum is 4 bytes 
specifing size is not optinal
*u can convert from enum to int without casting 
but the other way is not possible and static cast is needed
Color obj3 = 3; 
error: a value of type "int" cannot be used to initialize an entity of type "Color"
*/
   int i = YELLOW;
   cout << i << endl;

   Color obj2 = static_cast<Color>(2);
   cout << obj2 << endl;
   cout << RED << endl;
/*
!To avoid these issues, you can use enum class
*what if i has multiple enums with the same name in the same scope?: 
that's accaptable as enum class is a scoped enumeration
the enumerators are only visible within the scope of the enum
*unlike enum, u have not direst access to the enumerators
only accessed through scope operator
*/
   Colorr obj4 = Colorr::RED;
   Alert alert = Alert::RED;
/*
*u cant convert from int to enum or the other way without casting
*/
    int x = static_cast<int>(Colorr::RED);
    Colorr obj = static_cast<Colorr>(5);
/*
*cant simply cout the enumerators without casting to int
*/
    cout << static_cast<int>(obj4) << endl;
    cout << static_cast<int>(Alert::RED) << endl;

/*
*adjustable size
*/
    enum class Colorrr : char { RED, GREEN, BLUE };
    cout << sizeof(Colorrr) << endl;  // 1
    cout << sizeof(Colorr) << endl;   // 4
    return 0; 
}
