#include <queue>
#include <vector>
#include <set>
#include <list>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

struct Person {
    std::string name;
    int age;
};

void swap(std::vector<int>& arr, int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void swap(int arr[], int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void toMoveFun(std::vector<int> arr, int toMove) {
    int i = 0;
    int j = arr.size() - 1;
    while (i < j) {
        while (i < j && arr[j] == toMove) {
            j--;
        }
        if (arr[i] == toMove) {
            swap(arr, i, j);
        }
        i++;
    }

    for (auto it : arr)
        cout << it << " ";
}

void toMoveInplace(std::vector<int> arr, int toMove) {
    int i = 0;
    int j = 0;

    int n = arr.size();

    while (i < n && j < n) {
        if (arr[i] == toMove) {
            while (j < n && arr[j] == toMove)
                j++;
            if (j < n) {
                swap(arr, i, j);
                j++;
            }
        }

        else {
            i++;
        }
    }

    for (auto it : arr)
        cout << it << " ";
}

bool isValidDirection(int i, int j, int R, int C) {
    return i < R && i >= 0 && j < C && j >= 0;   
}

std::vector<std::pair<int,int>> direction = { {1,0}, {-1,0}, {0,1}, {0,-1} };

void dfs(vector<vector<int>> arr, int i, int j, int R, int C, set<string> visited, int& currentCount) {
    if (!isValidDirection(i, j, R, C) && arr[i][j] != 1) {
        return;
    }
    string key = i + "-" + j;
    if (visited.contains(key)) {
        return;
    }
    visited.insert(key);
    currentCount++;

    for (auto& dir : direction) {
        dfs(arr, i + dir.first, j + dir.second, R, C, visited, currentCount);
    }

}

list<int> numOfRiver(vector<vector<int>> arr, int m, int n) {
    list<int> countResult;
    set<string> visited;
    for (int i = 0; i < m, i++;) {
        for (int j = 0; j < n, j++;) {
            int currentCount = 0;
            if (arr[i][j] == 1) {
                dfs(arr, i, j, m, n, visited, currentCount);
                if(currentCount > 0)
                    countResult.push_back(currentCount);
            }
        }
    }
    return countResult;
}

void heapify(int arr[], int parent, int size) {
    int left = parent * 2 + 1;
    int right = parent * 2 + 2;
    int largest = parent;
    if (left < size && arr[left] > arr[largest])
        largest = left;
    if (right < size && arr[right] > arr[largest])
        largest = right;

    if (largest != parent) {
        swap(arr, largest, parent);
        heapify(arr, parent, size);
    }
}

void minHeap(int arr[], int n) {

    int mid = n / 2;
    for (int i = mid-1; i >= 0; i--) {
        heapify(arr, mid, n);
    }

    for (int i = 0; i < n; i++) {
        swap(arr, i, n - i - 1);
        heapify(arr, i, n);
    }

}

void swap(string& str, int i, int j) {
    int temp = str[i];
    str[i] = str[j];
    str[j] = temp;
}

void permutationUtils(string& str, int index) {
    if (index == str.length())
        cout << str.c_str() << endl;

    for (int k = index; k < str.length(); k++) {
        swap(str, index, k);
        permutationUtils(str, index + 1);
        swap(str, index, k);
    }
}

// "abc"
void permutation(string str) {
    permutationUtils(str, 0);
}

void shop() {

    vector<pair<int, int>> vec = { {5, 0}, {1, 2}, {3, 1}, {2, 3} }; // {key, index}

    // Sort by key (first element)
    sort(vec.begin(), vec.end(), [](int a, int b) {return a < b;});

    // Output sorted vector
    for (const auto& p : vec) {
        cout << p.first << " " << p.second << endl;
    }

    return;
}

int main() {
    shop();
    //permutation("abc");
    vector<int> arr = { 2, 1, 2, 2, 2, 3, 4, 2 };
    int toMove = 2;

    toMoveInplace(arr, toMove);

    // Lambda for max-heap by age
    auto cmp = [](const Person& a, const Person& b) {
        return a.age < b.age;
        };

    // priority_queue with lambda comparator
    //std::priority_queue<Person, std::vector<Person>, decltype(cmp)> pq(cmp);

    //pq.push({ "Alice", 35 });
    //pq.push({ "Bob", 40 });
    //pq.push({ "Carol", 30 });

    //while (!pq.empty()) {
    //    std::cout << pq.top().name << ": " << pq.top().age << "\n";
    //    pq.pop();
    //}
    return 0;
}
