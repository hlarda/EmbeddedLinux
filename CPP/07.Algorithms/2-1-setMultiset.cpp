/**
 * !Associative containers
 * ? 1. set
 * stores unique elements following a specific order.
 * Sorting is done using the key comparison function Compare.
 * The value of the element cannot be modified once it is added to the set, 
 * though it is possible to remove and add the modified value of that element.
 * ? 2. multiset
 * Similar to a set, but it allows multiple instances of an element to be stored.
 * ? 3. map
 * stores elements formed by a combination of a key value and a mapped value, following a specific order.
 * The key value is used to uniquely identify the element and mapped value is the content associated with the key.
 * No two mapped values can have equivalent keys.
 * ? 4. multimap
 * Similar to a map, but it allows multiple values to be associated with a single key.
 * 5. unordered_set
 * 6. unordered_multiset
 * 7. unordered_map
 * 8. unordered_multimap
 * ! The primary difference between ordered and unordered containers
 * ? 1.Ordered Containers: 
 * internally use a self-balancing binary search tree (Red-Black Tree) for storage. 
 * As a result, the elements in these containers are always sorted (by key)
 * and operations like insertion, deletion, and search have a time complexity of O(log n).
 *  However, they use more memory than their unordered counterparts.
 * ? 2.Unordered Containers: 
 * internally use an hash table for storage. 
 * the order of elements is not maintained.
 * Operations like insertion, deletion, and search have a time complexity of O(1).
 *  However, they use less memory than their ordered counterparts.
 * 
 * If you need to maintain an order of elements and can afford a bit more memory, go for ordered containers. 
 * If you need faster operations and are okay with not maintaining any order, go for unordered containers.
*/
#include <iostream>
#include <set>
using namespace std;

int main() {
    set<int> numbers;

    // Inserting data into the set
    numbers.insert(5);
    numbers.insert(3);
    numbers.insert(4);
    numbers.insert(3); // This will not be inserted because 3 is already in the set

    // Iterating over the set
    for (const auto& num : numbers) {
        cout << num << endl;
    }

     multiset<int> numbers;

    // Inserting data into the multiset
    numbers.insert(5);
    numbers.insert(3);
    numbers.insert(4);
    numbers.insert(3); // This will be inserted because multiset allows duplicate elements

    // Iterating over the multiset
    for (const auto& num : numbers) {
        cout << num << endl;
    }
    return 0;
}