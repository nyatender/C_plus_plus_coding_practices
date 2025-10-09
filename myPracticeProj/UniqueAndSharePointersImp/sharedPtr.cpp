
#include <iostream>
#include <memory> // For std::shared_ptr

template<typename T>
class SharedPtr {
    T* ptr;
    size_t* ref_count;
public:
    explicit SharedPtr(T* p = nullptr) : ptr(p), ref_count(new size_t(1)) {}

    // Copy constructor
    SharedPtr(const SharedPtr& other) : ptr(other.ptr), ref_count(other.ref_count) {
        ++(*ref_count);
    }
    // Copy assignment
    SharedPtr& operator=(const SharedPtr& other) {
        if (this != &other) {
            release();
            ptr = other.ptr;
            ref_count = other.ref_count;
            ++(*ref_count);
        }
        return *this;
    }
    // Destructor
    ~SharedPtr() {
        release();
    }

    void release() {
        if (--(*ref_count) == 0) {
            delete ptr;
            delete ref_count;
        }
    }

    T& operator*() const { return *ptr; }
    T* operator->() const { return ptr; }
    size_t use_count() const { return *ref_count; }
};


int main() {
    std::shared_ptr<int> ptr1 = std::make_shared<int>(42); // create shared_ptr
    std::cout << "Value: " << *ptr1 << std::endl;

    // Share ownership with another shared_ptr
    std::shared_ptr<int> ptr2 = ptr1;
    std::cout << "Use count after sharing: " << ptr1.use_count() << std::endl;

    {
        std::shared_ptr<int> ptr3 = ptr2;
        std::cout << "Use count in inner block: " << ptr1.use_count() << std::endl;
    } // ptr3 goes out of scope

    std::cout << "Use count after inner block: " << ptr1.use_count() << std::endl;
    std::cout << "Value via ptr2: " << *ptr2 << std::endl;

    return 0;
}
