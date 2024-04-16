/*
*cout << *searchItirator<< endl;
*cout << typeid(searchItirator).name() << endl;
If you want to print the iterator itself, you need to convert it to a type that is printable. 
Iterators are typically not printable directly 
because they are pointers or objects that represent positions within a container.
One way to print the iterator itself is to cast it to a printable type, 
such as a pointer or an integer. For example, you could cast it to a pointer:
*cout << "Iterator: " << static_cast<void*>(&(*searchItirator)) << endl;
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <typeinfo>

using namespace std;

void search(vector<string> str, string x){
    auto searchItirator = find(str.begin(), str.end(), x);
    if (searchItirator == str.end()){
        cout << x <<"is not found" << endl;
    }else{
        cout << x <<"is found and its index is: " << distance(str.begin(), searchItirator) << endl;
    }
}

int main(int argc, char const *argv[])
{
    vector<string> str ={
        "hla",
        "lilo",
        "mrim"
    };
    string x = "lilo";

    search(str, x);
    return 0;
}
