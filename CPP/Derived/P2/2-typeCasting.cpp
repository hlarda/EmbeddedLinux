/*
casting styles
1. static_cast
2. dynamic_cast
3. const_cast
4. reinterpret_cast
5. C-style cast 
*/
int main(int argc, char const *argv[])
{
    // * static_cast * //
    /*whenever u want to use c cast use static_cast*/
    int x = 10;
    double y = 3.14;

    int *z = ( int * ) &y;  // runtime error: invalid conversion due to uncompatible sizes
    /*more safely use static_cast as it gives error during compilation*/
    //int *z = static_cast<int *> (&y);   // compile time error: invalid conversion due to uncompatible sizes
    double *j = static_cast<double *> (&y);   // compile time error: invalid conversion due to uncompatible sizes
    
    // * const_cast * //
    /*  used with constant expressions 
        used to remove the const or volatile from a pointer so it can be modified
    */

    const int a = 10;
    const int *b = &a; 

    //int * c = b;     //!error as uncompitable types//
    int *c = const_cast<int *> (b);
    int *c = (int*)  (b);  // compile time error: invalid conversion due to uncompatible types
    
    // * reinterpret_cast * //
    /*used to cast from one type to another*/
    int * ptr = new int(10);
    char * ch = reinterpret_cast<char *> (ptr);
    /*dont use with classes*/
    /*but the opposite is not true >> how to cast from the smaller type to the larger*/
    /*avoid using reinterpret and const cast >> lw 7sal a3raf aked bt3mel 7aga 3'lat*/
    return 0;
}
