#include"str.hpp"

str::str (){
    cout<<"default"<<endl;
}
str::str(const char* strPtr ){
    cout<<"param"<<endl;
    /*couldnt use for(char c : strPtr) as strPtr is not a container*/
    for(;*strPtr!='\0';strPtr++){strr.push_back(*strPtr);}
    print();
}
str::str (const str& strSource){
    cout<<"copy constructor"<<endl;
    if(this!=&strSource){
        strr = strSource.strr;
    }
}
str& str::operator=(const str& strSource){
    cout<<"copy assignment"<<endl;
    if(this!=&strSource){
        strr = strSource.strr;
    }
    return *this;
}
str::str (str&& expiredSource){
    cout<<"move constructor"<<endl;
    if(this!=&expiredSource){
        strr = move(expiredSource.strr);
        expiredSource.strr.clear();
    }
}
str& str::operator=  (str&& expiredSource){
    if(this!=&expiredSource){
        strr = move(expiredSource.strr);
        expiredSource.strr.clear();
    }
    return *this;
}
void str::print (){
    for(char c : strr){cout<<c;}
    cout << endl;
}
int str::length(){
    return strr.size();
}
int str::size(){
    return strr.size();
}
char& str::operator[] (int i){
    return strr[i];
}
char& str::at (int i){
    return strr[i];
}
str str::operator+ (const str& strAdd){
    str temp=*this;
    temp.strr.insert(strr.end(),strAdd.strr.begin(),strAdd.strr.end());
    return temp;
}
str& str::append (const str& strAdd){
    strr.insert(strr.end(),strAdd.strr.begin(),strAdd.strr.end());
    return *this;
}
str str::operator+ (const char* strPtr){
    str temp=*this;
    for(;*strPtr!='\0';strPtr++){temp.strr.push_back(*strPtr);}
    return temp;
}
str& str::append (const char* strPtr){
    for(;*strPtr!='\0';strPtr++){strr.push_back(*strPtr);}
    return *this;
}
str::~str(){
    cout<<"destr"<<endl;
    strr.clear();
}