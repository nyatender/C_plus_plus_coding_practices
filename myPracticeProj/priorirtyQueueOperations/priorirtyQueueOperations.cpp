#include <queue>
#include <deque>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

struct Person {
    std::string name;
    int age;
    bool operator>(const Person& person) const {
        return this->age < person.age;
    }
};

void insertInInt() {
    // priority queue
    std::priority_queue<int> pq; // Max-heap (default)
    std::priority_queue<int, std::vector<int>, std::greater<int>> min_pq;

    min_pq.push(35);
    min_pq.push(40);
    min_pq.push(20);

    while (!min_pq.empty()) {
        std::cout << min_pq.top() << "\n";
        min_pq.pop();
    }
}

/*
In C++, to declare a max heap for a collection of int[] (an array of integers), the typical approach is to use a
custom comparator with the STL priority_queue since priority_queue by default creates a max heap for simple types,
but for arrays (like int[] or std::vector<int>), a comparator function is needed.
*/

void priority_Queue() {
    auto cmpMax = [](const Person& a, const Person& b) {
        return a.age < b.age;
        };

    // Lambda for max-heap by age
    auto cmp = [](const Person& a, const Person& b) {
        return a.age > b.age;
        };

    // priority_queue with lambda comparator
    std::priority_queue <Person, std::vector<Person>, greater<Person>> maxHeap;
    //std::priority_queue <Person, std::vector<Person>, decltype(cmpMax)> maxHeap(cmpMax);
    std::priority_queue<Person, std::vector<Person>, decltype(cmp)> pq(cmp);

    maxHeap.push({ "Alice", 35 });
    maxHeap.push({ "Bob", 40 });
    maxHeap.push({ "Carol", 30 });

    while (!maxHeap.empty()) {
        std::cout << maxHeap.top().name << ": " << maxHeap.top().age << "\n";
        maxHeap.pop();
    }

    pq.push({ "Alice", 35 });
    pq.push({ "Bob", 40 });
    pq.push({ "Carol", 30 });

    while (!pq.empty()) {
        std::cout << pq.top().name << ": " << pq.top().age << "\n";
        pq.pop();
    }
}

void Queue() {

    // priority_queue with lambda comparator
    std::queue<Person> queue;

    queue.push({ "Alice", 35 });
    queue.push({ "Bob", 40 });
    queue.push({ "Carol", 30 });

    while (!queue.empty()) {
        std::cout << queue.front().name << ": " << queue.front().age << "\n";
        queue.pop();
    }
}

void Dqueue() {

    // priority_queue with lambda comparator
    std::deque<Person> queue;

    queue.push_back({ "Alice", 35 });
    queue.push_back({ "Bob", 40 });
    queue.push_back({ "Carol", 30 });

    /*queue.emplace_back({ "Alice", 35 });*/

    while (!queue.empty()) {
        std::cout << queue.front().name << ": " << queue.front().age << "\n";
        queue.pop_front();
        queue.pop_back();
    }
}

int main() {

    //insertInInt();
    priority_Queue();

    return 0;
}
