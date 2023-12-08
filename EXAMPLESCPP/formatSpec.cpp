#include <iostream>

int main() {
    int number = 42;
    int* ptr = &number;

    // Using %p to print the memory address of the pointer
    std::cout << "Memory address of 'number': " << std::hex << std::showbase << ptr << std::endl;

    return 0;
}
