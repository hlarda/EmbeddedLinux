#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int search(vector<int> v, int x){
    if(find(v.begin(), v.end(), x) != v.end()){
        return distance(v.begin(), find(v.begin(), v.end(), x));
    }else{
        return -1;
    }
}

void add(vector<int> &v, int element, int index){
    if (index >= 0 && index <= v.size()){
        v.insert( v.begin()+index , element );
        for(int i : v){ cout << i <<"   "; } cout << endl;    
    }else{
        cout << "Invalid index" << endl;
    }
}

int main(){
    int size;
    vector<int> v;
    int choice = 1;

    cout << "Program to do some operations on vector" << endl;
    cout << "Enter the initial size of the vector: " << endl;
    cin >> size;
    v.resize(size);
    cout << "Enter the elements of the vector: " << endl;
    for(int& in : v){
        cin >> in;
    }

    while (choice){
        int element;

        cout << "Which operation to perform?" << endl;
        cout << "0. Exit    1. Search   2. Add  3. Delete   4.sort" << endl;
        cin >> choice;
        switch (choice){
            case 0:
                break;
            case 1:
                cout << "Enter the element to search then return its index:     ";
                cin >> element;
                if(search(v, element) == -1){
                    cout << "Not found" << endl;
                }else{
                    cout << "The index of the element is:   " << search(v, element) << endl;
                }
                break;
            case 2:
                int index;
                cout << "Enter the element to add knowing that last element's index is "<<v.size()-1<<":     ";
                cin >> element;
                cout << "Enter the index:     ";
                cin >> index;
                add(v, element, index);
                break;
            case 3:
                int choice;
                cout << "Delete by: 1. Value 2. Position?"<< endl;
                cin >> choice;
                if (choice == 1) {
                    cout << "Enter the value to delete: ";
                    cin >> element;
                    v.erase(remove(v.begin(), v.end(), element), v.end());
                    for(int i : v){ cout << i <<"   "; } cout << endl;    
                } else if (choice == 2) {
                    cout << "Enter the position to delete: ";
                    cin >> index;
                    if (index >= 0 && index < v.size()) {
                        v.erase(v.begin() + index);
                        for(int i : v){ cout << i <<"   "; } cout << endl;    
                    } else {
                        cout << "Invalid position" << endl;
                    }
                } else {
                    cout << "Invalid choice" << endl;
                }
                break;
            case 4:
                int sortChoice;
                cout << "Choose if 1. Ascending or 2. Descending:" << endl;
                cin >> sortChoice;
                switch (sortChoice){
                    case 1:
                        sort(v.begin(), v.end(), [](int a, int b) { return a < b; });
                        for(int i : v){ cout << i <<"   "; } cout << endl;    
                        break;
                    case 2:
                        sort(v.begin(), v.end(), [](int a, int b) { return a > b; });
                        for(int i : v){ cout << i <<"   "; } cout << endl;    
                        break;                
                default:
                    cout << "Invalid choice" << endl;
                    break;
                }
                break;
            default:
                cout << "Invalid choice" << endl;
                break;
        }
    }
    return 0;
}
