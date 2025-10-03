#include <queue>
#include <deque>
#include <vector>
#include <string>
#include <iostream>

struct Person {
    std::string name;
    int age;
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

void priority_Queue() {
    // Lambda for max-heap by age
    auto cmp = [](const Person& a, const Person& b) {
        return a.age > b.age;
        };

    // priority_queue with lambda comparator
    std::priority_queue <Person> min;
    std::priority_queue<Person, std::vector<Person>, decltype(cmp)> pq(cmp);

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

    insertInInt();
    //priority_Queue();

    return 0;
}
