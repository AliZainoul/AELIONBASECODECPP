#include <iostream>
#include <iomanip>
int main() 
{
    double price = 49.123;
    // Affichage avec un format monétaire
    std::cout << "The price is : €" << std::fixed << std::setprecision(1) << price << std::endl;
    // Affichage d'une chaîne formatée
    std::cout << "Reduction of 20% : €" << (price * 0.20) << std:: endl;
    return 0; 
}