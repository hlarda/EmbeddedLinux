#include <iostream>
#include <csignal>
using namespace std;
int main()
{
    signal(SIGINT, [](int signal) { cout << "Ctrl + C" << endl;});
    cout << "Enter Ctrl+C" << endl;
    while (true){}
}