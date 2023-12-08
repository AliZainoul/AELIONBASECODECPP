#pragma once

#ifndef TRIANGLEHPP
#define TRIANGLEHPP

#include <iostream>
#include <cmath>

class Triangle {
private:
    double sideA, sideB, sideC;

public:
    // Constructors
    Triangle();
    Triangle(double a, double b, double c);

    // Getters
    double getSideA() const;
    double getSideB() const;
    double getSideC() const;

    // Setters
    void setSideA(double a);
    void setSideB(double b);
    void setSideC(double c);

    // Function to check if the sides form a valid triangle
    bool isValidTriangle() const;
};
#endif