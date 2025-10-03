#include <iostream>
#include <set>

using namespace std;

int insertFindAndDelete() {
    std::set<int> s;

    // Insertion
    s.insert(10);
    s.insert(20);
    s.insert(30);
    s.insert(20);  // ignored since 20 already exists

    // Size
    std::cout << "Size: " << s.size() << "\n"; // Output: 3

    // Check existence - C++20 contains()
    if (s.contains(20)) {
        std::cout << "20 is present\n";
    }

    // Find element
    auto it = s.find(10);
    if (it != s.end()) {
        std::cout << "Found: " << *it << "\n"; // Output: Found: 10
    }

    // Remove element
    s.erase(20);

    // Iterate and print set
    std::cout << "Elements in set: ";
    for (const auto& x : s)
        std::cout << x << " ";
    std::cout << "\n";

    return 0;
}

struct Person {
    std::string name;
    int age;
    bool operator<(const Person& other) const {
        return name < other.name || (name == other.name && age < other.age);
    }
};

int insertFindAndDeleteForObject() {
    std::set<Person> s;

    // Insertion
    s.insert({Person("alice", 20)});
    s.insert({ Person("paul", 30) });
    s.insert({ Person("mike", 10) });
    s.insert({ Person("julia", 40) });
    s.insert({ Person("alice", 20) });  // ignored since 20 already exists

    // Size
    std::cout << "Size: " << s.size() << "\n"; // Output: 3

    // Check existence - C++20 contains()
    if (s.contains(Person("alice", 20))) {
        std::cout << "20 is present\n";
    }

    // Find element
    auto it = s.find(Person("mike", 10));
    if (it != s.end()) {
        std::cout << "Found: " << (*it).name << " : " << (*it).age << "\n"; // Output: Found: "mike", 10
    }

    // Remove element
    s.erase(Person("julia", 40));

    // Iterate and print set
    std::cout << "Elements in set: ";
    for (const auto& x : s)
        std::cout << x.name << " : " << x.age;
    std::cout << "\n";

    return 0;
}

int main() {
    insertFindAndDeleteForObject();

    return 0;
}
