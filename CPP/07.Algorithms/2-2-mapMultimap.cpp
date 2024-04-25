#include <iostream>
#include <map>

int main() {
    std::map<std::string, int> ages;

    // Inserting data into the map
    ages["Alice"] = 20;
    ages["Bob"] = 21;
    ages["Charlie"] = 22;

    // Accessing data from the map
    std::cout << "Alice's age: " << ages["Alice"] << std::endl;

    // Iterating over the map
    for (const auto& pair : ages) {
        std::cout << pair.first << "'s age: " << pair.second << std::endl;
    }

    // Checking if a key exists in the map
    if (ages.count("Alice") > 0) {
        std::cout << "Alice's age: " << ages["Alice"] << std::endl;
    } else {
        std::cout << "Alice's age not found" << std::endl;
    }

    // Erasing data from the map
    ages.erase(ages.begin(), ages.end());

    std::multimap<std::string, int> scores;

    // Inserting data into the multimap
    scores.insert({"Alice", 100});
    scores.insert({"Bob", 90});
    scores.insert({"Alice", 95}); // Alice can have multiple scores

    // Iterating over the multimap
    for (const auto& pair : scores) {
        std::cout << pair.first << "'s score: " << pair.second << std::endl;
    }

    // Checking if a key exists in the multimap
    auto it = scores.find("Alice");
    if (it != scores.end()) {
        std::cout << "Alice's score: " << it->second << std::endl;
    } else {
        std::cout << "Alice's score not found" << std::endl;
    }

    // Erasing data from the multimap
    scores.erase(scores.begin(), scores.end());

    return 0;
}