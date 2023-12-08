// MY_SOLUTION:

#include <iostream>
#include <vector>

// Helper method to print the elements of a vector
template <typename T>
void printVector(const std::vector<T>& vec) {
    for (const auto& el : vec)
        std::cout << el << " ";
    std::cout << std::endl;
}

template <class T>
class cln_ptr {
private:
    T* ptr;
public:
    cln_ptr(T* _ptr) : ptr(_ptr) {}
    cln_ptr(cln_ptr&& _p) : ptr(_p.ptr) {_p.ptr = 0;}
    // OR: cln_ptr(cln_ptr& _p) : ptr(_p-->ptr) {_p-->ptr = 0;}

    cln_ptr& operator=(cln_ptr&& _p)
    {
        std::swap(ptr, _p.ptr);
        return *this;
    }

    T& operator*() const { return *ptr; }

    ~cln_ptr() {
        delete ptr; // Release the resource when the cln_ptr goes out of scope
    }
};

int main() {
    std::vector<int> v(3, 4);

    // Print the original vector v
    std::cout << "Original vector v: ";
    printVector(v);

    // Use cln_ptr to manage the ownership of the vector data with move semantics
    cln_ptr<std::vector<int>> w(new std::vector<int>(std::move(v)));

    // Display vector w using the helper method
    std::cout << "Vector managed by cln_ptr (w): ";
    printVector(*w);

    // Print vector v after the move
    std::cout << "Vector v after move: ";
    printVector(v);  // Should print an empty vector

    return 0;
}



/*
OPTIMIZED SOLUTION
#include <iostream>
#include <vector>

template <class T>
class cln_ptr {
private:
    T* ptr;

public:
    cln_ptr(T* _ptr) : ptr(_ptr) {}
    cln_ptr(cln_ptr&& _p) noexcept : ptr(_p.ptr) { _p.ptr = nullptr; }
    cln_ptr& operator=(cln_ptr&& _p) noexcept {
        if (this != &_p) {
            delete ptr; // Release current resource
            ptr = _p.ptr;
            _p.ptr = nullptr;
        }
        return *this;
    }

    T& operator*() const { return *ptr; }

    ~cln_ptr() {
        delete ptr; // Release the resource when the cln_ptr goes out of scope
    }

    // Add additional functionality if needed
};

// Helper method to print the elements of a vector
template <typename T>
void printVector(const std::vector<T>& vec) {
    for (const auto& el : vec)
        std::cout << el << " ";
    std::cout << std::endl;
}

int main() {
    std::vector<int> v(3, 4);

    // Print the original vector v
    std::cout << "Original vector v: ";
    printVector(v);

    // Use cln_ptr to manage the ownership of the vector data with move semantics
    cln_ptr<std::vector<int>> cln_v(new std::vector<int>(std::move(v)));

    // Display vector w using the helper method
    std::cout << "Vector managed by cln_ptr: ";
    printVector(*cln_v);

    // Print vector v after the move
    std::cout << "Vector v after move: ";
    printVector(v);  // Should print an empty vector

    return 0;
}
*/


// CUSTOM_SOLUTION




/*
CLASS 
// MEMBERS

// CONSTRUCTORS

// DESTRUCTOR

// METHODS

    // GETTERS

    // SETTERS

    // OTHER METHODS

    // OPERATORS

    // HELPERS
*/