#include <iostream>
#include <cmath>
#include "Triangle.hpp"

// Constructors
Triangle::Triangle() : sideA(0.0), sideB(0.0), sideC(0.0) {
    // Default constructor creates an invalid triangle
}

Triangle::Triangle(double a, double b, double c) : sideA(a), sideB(b), sideC(c) {
    // Check if the sides form a valid triangle
    if (!isValidTriangle()) {
        std::cerr << "Invalid triangle. Setting all sides to zero." << std::endl;
        sideA = sideB = sideC = 0.0;
    }
}

// Getters
double Triangle::getSideA() const { return sideA; }
double Triangle::getSideB() const { return sideB; }
double Triangle::getSideC() const { return sideC; }

// Setters
void Triangle::setSideA(double a) {
    sideA = a;
    if (!isValidTriangle()) {
        std::cerr << "Invalid triangle. Setting all sides to zero." << std::endl;
        sideA = sideB = sideC = 0.0;
    }
}

void Triangle::setSideB(double b) {
    sideB = b;
    if (!isValidTriangle()) {
        std::cerr << "Invalid triangle. Setting all sides to zero." << std::endl;
        sideA = sideB = sideC = 0.0;
    }
}

void Triangle::setSideC(double c) {
    sideC = c;
    if (!isValidTriangle()) {
        std::cerr << "Invalid triangle. Setting all sides to zero." << std::endl;
        sideA = sideB = sideC = 0.0;
    }
}

// Function to check if the sides form a valid triangle
bool Triangle::isValidTriangle() const {
    return (sideA + sideB > sideC) && (sideA + sideC > sideB) && (sideB + sideC > sideA);
}