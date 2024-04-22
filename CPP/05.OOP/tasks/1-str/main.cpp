#include"str.hpp"

int main(int argc, char const *argv[])
{
    str str2("hello");
    str str1 = str2;
    str1.print();

    str str3 ="lilo";
    str str4 = move(str3);
    str4.print();

    str4[3] = 'a';
    str4.at(3) = 'a';
    str4.print();
    cout << str4[3] << endl;
    cout << str4.at(3) << endl;
    cout << str4.length() << endl;
    cout << str4.size() << endl;

    cout<<endl;
    str str5 = str4 + str1;
    str5.print();
    cout<<endl;
    str str6 = str4 + "world";
    str6.print();
    cout<<endl;
    str6.append(str1);
    str6.append("world");
    str5.print();
    cout<<endl;
    str6.print();
    return 0;
}
