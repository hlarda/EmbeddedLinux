/*
? linkage of const
* cpp: internal linkage
that means that the variable is only visible within the file it's defined in 
and any access trials results in linker error
* c: external linkage
the const keyword does not affect linkage. 
By default, global variables (including const variables) have external linkage,
which means they are visible to all files by declaring with the extern.
*/

#include<iostream>
using namespace std;

int mm = 10;
const int a = 10;

int main(int argc, char const *argv[])
{
    //? used in switch statements//

    switch (mm){
        case a:
            cout << "euals" << endl;
            break;
    }

    //? with array as an index//
    int arr[a]{};

    //? cant be modified with non-const pointer//
    //*int* p = &a;     //not allowed because p is a non-const pointer
    const int* p = &a;  // This is allowed, because p is a const pointer pointer
    
    return 0;
}
