#include <vector>
#include <iostream>

using namespace std;

void initializations() {
    int rows = 3, cols = 4;

    // 2D vector of size 3x4, all initialized to 0
    std::vector<std::vector<int>> matrix(rows, std::vector<int>(cols, 0));

    // Print the 2D vector
    for (const auto& row : matrix) {
        for (int val : row)
            std::cout << val << " ";
        std::cout << "\n";
    }

    std::vector<std::vector<int>> matrix1{
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9}
    };

    // Print the matrix
    for (const auto& row : matrix1) {
        for (int val : row)
            std::cout << val << " ";
        std::cout << "\n";
    }
}

int operations() {
    std::vector<int> v = { 10, 20, 30 };

    v.push_back(40);
    v.insert(v.begin() + 1, 15);

    std::cout << "Vector elements: ";
    for (int val : v) {
        std::cout << val << " ";
    }
    std::cout << "\nSize: " << v.size() << "\n";

    v.pop_back();
    v.erase(v.begin());

    std::cout << "After removal: ";
    for (int val : v) {
        std::cout << val << " ";
    }
    std::cout << "\n";

    v.clear();
    std::cout << "Is vector empty? " << (v.empty() ? "Yes" : "No") << "\n";

    return 0;
}

void dynamic() {

    /*int* arr = new int[10];*/
    string abc = "abc";
    vector<int> vec(abc.size(), INT_MAX);
    for (auto& it : vec) {
        cout << it << " " << ends;
    }

}

int* funreturnarray() {

    return new int[2] {-1, -1};;
}

int main() {
     dynamic();

    std::vector<int> v;             // Empty vector of ints
    std::vector<int> v2(5, 10);    // Vector of size 5, all elements 10
    std::vector<int> v3 = { 1, 2, 3 }; // Initialized with values

    v.push_back(20);
    v.push_back(30);

    v.insert(v.begin() + 1, 15); // Insert 15 at index 1

    v.insert(v.begin() + 2, 3, 25); // Insert three 25s at index 2

    int x = v[0];      // operator[] - No bounds checking, fast access

    int y = v.at(2);   // at(index) - Bounds-checked, throws exception if out of range

    v.erase(v.begin() + 1);  // - Erase element at position

    v.clear();              // v.clear();



    return 0;
}
