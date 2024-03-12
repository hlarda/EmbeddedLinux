#include <iostream>
/*
This loop will iterate over each element in the `numbers` array. 
For each iteration, `number` will be assigned the value of the current element. 
The loop will automatically end after it has iterated over all elements in the array.
So, in this case, the loop will print out each number in the `numbers` array, followed by a space.
*/
int main() {
    int numbers[] = {7, 5, 9, 2, 6};

    // Using a ranged loop to iterate over the array
    for (int number : numbers) {
        std::cout << number << " ";
    }

    return 0;
}