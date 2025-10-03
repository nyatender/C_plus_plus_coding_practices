
/*
https://www.geeksforgeeks.org/cpp/map-associative-containers-the-c-standard-template-library-stl/

map traversal
https://www.geeksforgeeks.org/cpp/traversing-a-map-or-unordered_map-in-cpp-stl/


*
* */


#include <iostream>
#include <map>
#include <list>
#include <queue>
#include <vector>
#include <unordered_map>
#include <utility>
#include <algorithm>

using namespace std;

void forLoop() {
    int arr[] = { 1, 1, 2, 1, 1, 3, 4, 3 };
    int n = sizeof(arr) / sizeof(arr[0]);

    //=============================================//
    // inserting elements
    map<int, int> m;
    for (int i = 0; i < n; i++)
        m[arr[i]]++;

    // Printing of MAP
    cout << "Element  Frequency" << endl;
    for (auto i : m)
        cout << i.first << " \t\t\t " << i.second << endl;
    //=============================================//

    m.insert({ 1, 1 });

    //https://stackoverflow.com/questions/10038985/remove-a-key-from-a-c-map
    m.erase(1);

}

void iteratorbased() {

    int arr[] = { 1, 1, 2, 1, 1, 3, 4, 3 };
    int n = sizeof(arr) / sizeof(arr[0]);

    // inserting data to map
    map<int, int> m;
    for (int i = 0; i < n; i++)
        m[arr[i]]++;

    // Printing of MAP
    cout << "Element  Frequency" << endl;
    for (auto i = m.begin(); i != m.end(); i++)
        cout << i->first << " \t\t\t" << i->second << endl;

}

class object {
    int a;
    int b;
public:
    object() :a(0), b(0) {}
    object(int x, int y) :a(x), b(y) {}

    bool operator<(const object& other) const {
        if (a != other.a) {
            return a < other.a;
        }
        return b < other.b;
    }

    bool operator==(const object& other) const {
        return a == other.a && b == other.b;
    }
};

void insertInSTL() {

    //=========================================
    // Map
    unordered_map<int, int> intMap;
    intMap.insert({ 1, 1 });

    map<object, int> objectMap;
    object* obj = new object(1, 1);
    objectMap.emplace(obj, 1);

    //auto it = objectMap.find(obj);  // obj is a pointer
    auto it = objectMap.find(*obj);
    object key{ 1,1 };
    auto it = objectMap.find(key);

}

void removeElementsFromSTL() {
    // Map
    unordered_map<int, int> intMap;
    intMap.insert({ 1, 1 });

    map<object, int> objectMap;
    object* obj = new object(1, 1);
    objectMap.emplace(obj, 1);

    intMap.erase(1);
    objectMap.erase(*obj);
}


void stackOperations() {

}

void StringOperations() {

}

void StringToInt() {

}

void IntToString() {

}

struct Person {
    std::string name;
    int age;
    bool operator<(const Person& other) const {
        return name < other.name || (name == other.name && age < other.age);
    }
};

int findImp() {
    std::map<Person, std::string> directory;
    directory[{ "Alice", 30 }] = "Doctor";
    directory[{ "Bob", 25 }] = "Engineer";
    directory[{ "Alice", 28 }] = "Lawyer";

    // Key to find:
    Person searchKey{ "Alice", 30 };

    // Find
    auto it = directory.find(searchKey);
    if (it != directory.end()) {
        std::cout << searchKey.name << " (" << searchKey.age << "): " << it->second << '\n';
    }
    else {
        std::cout << "Person not found!" << '\n';
    }
}

int main() {

    return 0;
}
