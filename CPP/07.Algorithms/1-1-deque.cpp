/**
 * ?sequence containers in STL:
 * 1. array     2.string        3.vector
 * 4. deque     5.list          6. forward_list
 * ? deque and vector are both sequence containers in STL hold elements of any type. 
 * Here are the main differences between them:
 * !1.Memory Allocation:
 *      *vector
 *       allocates memory in a contiguous manner. 
 *      When the memory is full and new elements are added, 
 *      it reallocates a bigger chunk of memory, 
 *      copies the old elements to the new location, 
 *      and then adds the new elements.
 *      *deque (double-ended queue) 
 *      allocates memory in chunks. 
 *      When new elements are added and the current chunk is full, 
 *      it simply allocates a new chunk. 
 *      This means that a deque's elements may not be stored contiguously in memory.
 * !2.Insertion and Deletion: 
 *      *vector 
 *      provides fast insertion and deletion at the end, 
 *      but slow insertion and deletion at the beginning 
 *      or in the middle because all elements after the insertion/deletion point have to be shifted. 
 *      *deque 
 *      provides fast insertion and deletion at both the beginning and the end.
 * 
 * !3.Random Access: 
 *      Both vector and deque provide fast random access to elements.
 * !4.Memory Overhead: 
 *      deque has a bit more memory overhead than vector due to the management of multiple chunks of memory.
 * !5.Reallocation: 
 *      Since vector reallocates and copies elements when its memory is full, 
 *      any pointers or references to its elements may become invalidated after a push_back operation. 
 *      On the other hand, deque does not invalidate pointers or references to its elements when new elements are added.
*/
#include <iostream>
#include <deque>
using namespace std;

int main() {
    deque<int> deq = {1, 2, 3, 4, 5};

    deq.push_back(6);

    deq.push_front(0);

    cout << "First element: " << deq.front() << endl;
    cout << "Last element: " << deq.back() << endl;

    cout << "Size: " << deq.size() << endl;

    cout << "Elements: ";
    for(int i : deq) {
        cout << i << " ";
    }
    cout << endl;

    deq.pop_back();

    deq.pop_front();

    if(deq.empty()) {
        cout << "Deque is empty" << endl;
    } else {
        cout << "Deque is not empty" << endl;
    }

    deq.clear();
    return 0;
}