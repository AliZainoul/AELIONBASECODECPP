#include <iostream> 
#include <iomanip>
#include <cmath>

void my_function(){
    // Affichage de pi avec deux décimales
    std::cout << "The␣value␣of␣PI␣est␣:␣" << std::fixed << std::setprecision(10) << M_PI << std::endl;
    // Affichage en notation scientifique
    std::cout << "In␣Scientific␣notation␣:␣" <<          std::scientific <<       M_PI << 
    std::endl;
}

int main() 
{
    my_function();
    return 0; 
}