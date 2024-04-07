#include<iostream>
#include<vector>
using namespace std;

int  maxInArray (vector<int> vec){
    int  max = vec[0];
    for (int  num : vec){
        if (num > max) max = num;
    }
    return max;
}
int main()
{
    int size;
    
    cout << "This program is to find the maximum number in an array" << endl;
    cout << "Enter the size of the array: ";
    cin >> size;
    vector<int > vec(size);

    cout << "Enter the elements of the array: "<< endl;
    for(int& in : vec){
        cin >> in;
    }

    cout << "The maximum number in the array is: " << maxInArray(vec) << endl;
    return 0;
}
