
#include <iostream>
#include <memory>

template<typename T>
class UniquePtr {
    T* ptr;
public:
    explicit UniquePtr(T* p = nullptr) : ptr(p) {}

    // Delete copy operations to ensure unique ownership
    UniquePtr(const UniquePtr&) = delete;
    UniquePtr& operator=(const UniquePtr&) = delete;

    // Enable move semantics
    UniquePtr(UniquePtr&& other) noexcept : ptr(other.ptr) {
        other.ptr = nullptr;
    }
    UniquePtr& operator=(UniquePtr&& other) noexcept {
        if (this != &other) {
            delete ptr;
            ptr = other.ptr;
            other.ptr = nullptr;
        }
        return *this;
    }

    T& operator*() const { return *ptr; }
    T* operator->() const { return ptr; }
    T* get() const { return ptr; }

    ~UniquePtr() { delete ptr; }
};



int main() {
    std::unique_ptr<int> ptr1 = std::make_unique<int>(100);
    std::cout << "unique_ptr value: " << *ptr1 << std::endl;

    // Ownership transfer
    std::unique_ptr<int> ptr2 = std::move(ptr1);
    if (!ptr1) {
        std::cout << "ptr1 is null after move." << std::endl;
    }
    std::cout << "unique_ptr value after move: " << *ptr2 << std::endl;
    return 0;
}


