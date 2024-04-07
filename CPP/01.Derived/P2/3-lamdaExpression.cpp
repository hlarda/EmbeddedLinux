#include <iostream>
#include <functional>
using namespace std;
/*
[ capture clause ] (parameter) -> return_type { body };
[ capture clause ] (parameter) { body };
[ capture clause ] { body };
*/

int j = 10;
int k = 20;

int main()
{
    // * differnt way for naming the return function in pointer *//
    auto f = [] (int x, int y)-> int{
        cout << "x: " << x << " y: " << y << endl;
        return x+y;
    };
    function<void(int, int)> f1 = [] (int x, int y){
        cout << "x: " << x << " y: " << y << endl;
    };
    void (*f2)(int, int) = [] (int x, int y){
        cout << "x: " << x << " y: " << y << endl;
    };

    auto returnValue = f(2,3);
    cout << "return value: " << returnValue << endl;
    f1(4,3);
    f2(5,3);

    //* only used once and not accessable in other scope *//
    [] (int x, int y){
        cout << "x: " << x << " y: " << y << endl;
    }(10,11);

    //* capture clause is used to specify which variables from the enclosing scope 
    //* should be accessible within the lambda body and how they should be captured.*//
    int x = 10;
    int y = 20;

    auto lambdaWithCapture = [x, &y] {
    // x is captured by value, y is captured by reference
    std::cout << "Captured value of x: " << x << std::endl;
    y++; // Modify the original variable y
    std::cout << "Modified value of y: " << y << std::endl;
    };
    lambdaWithCapture();

    //*  *//
    // Lambda captures nothing explicitly
    auto lambda = [] {
        // We can't access variables x and y here directly because they are not captured
        // std::cout << "x: " << x << std::endl; // Error: 'x' was not declared in this scope
        // std::cout << "y: " << y << std::endl; // Error: 'y' was not declared in this scope

        // However, we can access global variables or static variables
        static int z = 30;
        std::cout << "Accessing global variable: " << std::endl;
        std::cout << "Global x: " << j << std::endl;
        std::cout << "Global y: " << ::k << std::endl;      //! :: is used to access global variable //
        std::cout << "static z: " << z << std::endl;
    };
    lambda();

    [&] {
        // we can acess global and static variables the scope by reference
    };
    
    [=] {
     // we can acess global and static variables the scope by value
    };

    [=, &y] {
        
    };

    //* the mutable keyword is used to indicate that the lambda allowed to modify variables captured by value within its body*//
    //* as it is  treated as const *//
    int w = 5;
    auto lamdoda = [w] () mutable {
        // Modifying the captured variable x even though it's captured by value
        w++;
        cout << "Inside lambda: x = " << w << endl;
    };

    cout << "Before calling lambda: x = " << w << endl;
    lamdoda(); // Call the lambda
    cout << "After calling lambda: x = " << w << endl;

    //* U can create totally new references IN capture of lamda *//
    //* then make it refernece to already existing variable *//
    //* co u can manipulate it *//
    int zz = 100;
    auto mnna = [&ref = zz]{
        ref++;
    };
    mnna();
    cout << zz << endl;

    //* !when to use lamda expression *//
    //* 1-passing a function as an argument *// 
    //* 2-traceability *// 
    
    int arr[] = { 1, 2, 3, 4, 5 };
    int offset = 1;
    sort(begin(arr), end(arr), [](int a, int b) { return a > b; }); 
    for(int each : arr){
        cout << each << " ";
    }
    cout << endl;
    //* assume that u have afseted the sort how to pass this offset *//
    sort(begin(arr), end(arr), [offset](int a, int b) { return a + offset > b + offset; }); 
    for(int each : arr){
        cout << each << " ";
    }  
    cout << endl;
    return 0;
}
