#include <iostream>
#include "Triangle.hpp"


int main() {
    // Testing Triangle class

    // Create a valid triangle
    Triangle validTriangle(3.0, 4.0, 5.0);

    // Display sides of the valid triangle
    std::cout << "Valid Triangle Sides: "
              << validTriangle.getSideA() << ", "
              << validTriangle.getSideB() << ", "
              << validTriangle.getSideC() << std::endl;

    // Attempt to create an invalid triangle
    Triangle invalidTriangle(1.0, 1.0, 3.0);

    // Display sides of the invalid triangle
    std::cout << "Invalid Triangle Sides: "
              << invalidTriangle.getSideA() << ", "
              << invalidTriangle.getSideB() << ", "
              << invalidTriangle.getSideC() << std::endl;

    return 0;
}