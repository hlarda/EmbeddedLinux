/*
? list and forward_list: 
are sequence containers in STL can hold elements of any type. 
They are implemented as doubly-linked list and singly-linked list respectively. 
?Here are the main differences between them and when to use them over `vector` and `queue`:

!1. list (Doubly-Linked List): 
Each element in a `list` contains a link to its previous element and its next element. 
This allows for efficient insertions and deletions at both the beginning and the end, as well as in the middle. 
However, it does not provide fast random access to elements (it takes linear time to access an element). 
You should use `list` when you need to frequently insert or delete elements in the middle of the sequence.

!2.forward_list (Singly-Linked List): 
Each element in a `forward_list` contains a link to its next element, but not its previous element. 
This makes it more memory efficient than `list`, but it only allows for efficient insertions and deletions at the beginning. 
You should use `forward_list` when you need a sequence with low memory overhead and only need to insert or delete at the beginning.

!3.vector: 
`vector` provides fast random access and efficient insertions and deletions at the end, but not at the beginning or in the middle. 
You should use `vector` when you need fast random access and mostly add elements at the end.

!4.queue: 
`queue` is an adapter container that provides efficient insertions at the end and deletions at the beginning, 
but it does not allow access to other elements. 
You should use `queue` when you need a first-in, first-out (FIFO) data structure.

If you need to frequently insert or delete elements in the middle   ----->  List
            a FIFO data structure   ----->  queue
            fast random access  ----->  vector 
            a sequence with low memory overhead and only need to insert or delete at the beginning   ----->  forward_list
*/
#include <iostream>
#include <list>
#include <forward_list>

using namespace std;

int main() {
    list<int> lst = {1, 2, 3, 4, 5};
    forward_list<int> flst = {1, 2, 3, 4, 5};

    lst.push_back(6);
    // forward_list doesn't have push_back

    lst.push_front(0);
    flst.push_front(0);

    cout << "First element of list: " << lst.front() << endl;
    cout << "First element of forward_list: " << flst.front() << endl;

    // Size of list
    cout << "Size of list: " << lst.size() << endl;
    // forward_list doesn't have size()

    // Iterate over elements
    cout << "Elements in list: ";
    for(int i : lst) {
        cout << i << " ";
    }
    cout << endl;

    cout << "Elements in forward_list: ";
    for(int i : flst) {
        cout << i << " ";
    }
    cout << endl;

    // Pop elements from the end
    lst.pop_back();
    // forward_list doesn't have pop_back()

    // Pop elements from the beginning
    lst.pop_front();
    flst.pop_front();

    // Check if list is empty
    if(lst.empty()) {
        cout << "List is empty" << endl;
    } else {
        cout << "List is not empty" << endl;
    }

    // Check if forward_list is empty
    if(flst.empty()) {
        cout << "Forward list is empty" << endl;
    } else {
        cout << "Forward list is not empty" << endl;
    }

    // Accessing an element in a list by index
    int index = 2;
    auto it = lst.begin();
    advance(it, index);
    cout << "Element at index " << index << " in list: " << *it << endl;

    // Accessing an element in a forward_list by index
    auto it2 = flst.begin();
    advance(it2, index);
    cout << "Element at index " << index << " in forward_list: " << *it2 << endl;

    // Clear the list and forward_list
    lst.clear();
    flst.clear();

    return 0;
}