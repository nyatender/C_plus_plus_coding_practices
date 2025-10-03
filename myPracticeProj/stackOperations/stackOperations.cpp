
#include <iostream>
#include <stack>

int stackOperationWithoutObject() {
    std::stack<int> st;

    // Inserting elements
    st.push(10);
    st.push(20);
    st.push(30);

    // Accessing the top element
    std::cout << "Top element: " << st.top() << '\n'; // Output: 30

    // Removing top element
    st.pop();

    std::cout << "Top element after pop: " << st.top() << '\n'; // Output: 20

    // Stack size
    std::cout << "Stack size: " << st.size() << '\n'; // Output: 2

    // Check if empty
    std::cout << "Is stack empty? " << (st.empty() ? "Yes" : "No") << '\n'; // Output: No

    return 0;
}


struct Person {
    std::string name;
    int age;
    Person(std::string n, int a): name(n), age(a) {}
    bool operator<(const Person& other) const {
        return name < other.name || (name == other.name && age < other.age);
    }
};


int stackOperationWithoutObject() {
    std::stack<Person> st;

    // Inserting elements
    st.push({Person("alice", 20) });
    st.push({ Person("paul", 30) });
    st.push({ Person("mike", 10) });

    // Accessing the top element
    std::cout << "Top element: " << st.top().name << " : " << st.top().age << '\n'; // Output: mike : 10

    // Removing top element
    st.pop();

    std::cout << "Top element after pop: " << st.top().name << " : " << st.top().age << '\n'; // Output: paul : 30

    // Stack size
    std::cout << "Stack size: " << st.size() << '\n'; // Output: 2

    // Check if empty
    std::cout << "Is stack empty? " << (st.empty() ? "Yes" : "No") << '\n'; // Output: No

    return 0;
}


int main() {

    return 0;
}