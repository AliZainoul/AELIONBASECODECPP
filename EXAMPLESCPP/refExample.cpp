#include <iostream> 

int main() {

    int original = 42;
    // Utilisation d'une référence
    int& ref = original;
    std::cout << "La␣valeur␣de␣la␣variable original avant changement ␣est␣:␣" 
        << original << std::endl;
    std::cout << "La␣valeur␣de␣la␣référence␣est␣:␣" 
        << ref << std::endl;

    ref = 133;
    std::cout << "La␣valeur␣de␣la␣variable original après changement ␣est␣:␣" 
        << original << std::endl;
    std::cout << "La␣valeur␣de␣la␣référence␣est␣:␣" 
        << ref << std::endl;

    original = 142;
    std::cout << "La␣valeur␣de␣la␣variable original après changement ␣est␣:␣" 
        << original << std::endl;
    std::cout << "La␣valeur␣de␣la␣référence␣est␣:␣" 
        << ref << std::endl;


    std::cout << "La␣valeur␣de␣la␣référence␣est␣:␣" 
        << &original << std::endl;
    std::cout << "La␣valeur␣de␣la␣référence␣est␣:␣" 
        << &ref << std::endl;

    return 0;
}