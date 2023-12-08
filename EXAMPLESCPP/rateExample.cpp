#include <iostream> 
#include <iomanip>
int main() {
    double rate = 0.08;
    // Affichage en pourcentage avec deux décimales
    std::cout << "Tax rate : " << std::fixed << std::setprecision(2) 
        << std::setw(6) << std::right << rate * 100 << "%" << std::endl; 
    return 0;
}