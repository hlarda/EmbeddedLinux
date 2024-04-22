#ifndef STR_HPP
#define STR_HPP

#include<iostream>
#include<vector>
using namespace std;

class str{
private:
    vector<char> strr{};
public:
    str();
    str(const char* strPtr );

    str             (const str& strSource);
    str& operator=  (const str& strSource);

    str             (str&& expiredSource);
    str& operator=  (str&& expiredSource);

    void print();

    int length  ();
    int size    ();

    char& operator[](int i);
    char& at        (int i);

    str operator+ (const str& strAdd);
    str& append    (const str& strAdd);
    str operator+ (const char* strPtr);
    str& append    (const char* strPtr);
    
    /*
    bool compare    (const str& str);
    bool operator!= (const str& str);

    int find        (const str& str , char c);
    bool findIf     (const str& str , char c);
    */
    ~str();
};

#endif