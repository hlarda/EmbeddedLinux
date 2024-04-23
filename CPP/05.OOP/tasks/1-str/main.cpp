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

    str str5 = "str5";
    str str6 = "str6";
    str str7 = str5 + str6;
    str7.print();

    str7.append(str6);
    str7.print();

    str7.append("str8");
    str7.print();

    str7 = str7 + "str9";
    str7.print();
    return 0;
}
