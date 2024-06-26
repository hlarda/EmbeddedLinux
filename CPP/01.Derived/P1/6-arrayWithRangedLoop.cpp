#include <iostream>
/*
This loop will iterate over each element in the `numbers` array. 
For each iteration, `number` will be assigned the value of the current element. 
The loop will automatically end after it has iterated over all elements in the array.
So, in this case, the loop will print out each number in the `numbers` array, followed by a space.

the type of the variable declared that will hold the current element in each iteration of the loop 
should be the same as the array or container that you're iterating

for(each element of, container)

*/
int main() {
    int numbers[] = {7, 5, 9, 2, 6};

    // Using a ranged loop to iterate over the array
    for (int number : numbers) {
        std::cout << number << " ";
    }

    return 0;
}