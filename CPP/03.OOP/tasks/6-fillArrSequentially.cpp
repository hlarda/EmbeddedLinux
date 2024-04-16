#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int main() {
    vector<int> vec(5); 
    int sum = 0;
    iota(vec.begin(), vec.end(), 10);

    for (int i : vec) {
        cout << i << " ";
    }

    sum = accumulate(vec.begin(), vec.end(), sum);
    cout << "\nSum: " << sum << endl;


    return 0;
}
