#include <list>
#include <iostream>

using namespace std;

int main() {

    std::list<int> l1;                  // Empty list
    std::list<int> l2 = { 1, 3, 4, 2, 5 }; // List initialized with values
    std::list<int> l3(5, 9);           // List with 5 elements, each 9

    // Print list elements
    for (int x : l2)
        std::cout << x << " ";
    std::cout << "\n";


    // Adding Elements
    std::list<int> l = { 3, 2 };

    l.push_back(5);     // List: 3 2 5
    l.push_front(1);    // List: 1 3 2 5

    auto it = l.begin();
    std::advance(it, 2);
    l.insert(it, 4);    // List: 1 3 4 2 5

    // Accessing Elements
    std::cout << l.front() << "\n";   // 1
    std::cout << l.back() << "\n";    // 5
    std::cout << *std::next(l.begin(), 2) << "\n";  // 4

    // Remove
    l.pop_front();       // Removes 1
    l.pop_back();        // Removes 5

    auto it = l.begin();
    std::advance(it, 1);
    l.erase(it);         // Removes element at second position


    /*
    * 
    size() - Returns number of elements

    empty() - Checks if the list is empty

    clear() - Removes all elements

    reverse() - Reverses the list in-place

    sort() - Sorts the list (performed in O(n log n))

    merge() - Merges two sorted lists

    unique() - Removes consecutive duplicate elements
    
    */


    std::list<int> listObj = { 1, 3, 4, 2, 5 }; // List initialized with values

    cout << listObj.size() << "\n";
    cout << listObj.empty() << "\n";

    listObj.reverse();
    cout << " after reverse \n";
    for (auto& i : listObj) {
        cout << "\n" << i << "\n";
    }
    listObj.reverse();

    listObj.sort();
    cout << " after sort \n";
    for (auto& i : listObj) {
        cout << "\n" << i << "\n";
    }

    std::list<int> listObj2 = { 10, 30, 40, 20, 50 }; // List initialized with values
    listObj.merge(listObj, listObj2);
    cout << " after megre \n";
    for (auto& i : listObj) {
        cout << "\n" << i << "\n";
    }

    std::list<int> listObj3 = { 10, 10, 40, 20, 20 }; // List initialized with values
    listObj3.unique();

}
