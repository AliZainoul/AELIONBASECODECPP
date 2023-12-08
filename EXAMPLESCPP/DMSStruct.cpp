#include <iostream>

// using namespace std;

struct DMS {
	int degrees;
	int minutes;
	int seconds;
};

void initialiserCoordonnees(DMS *point)
{
    // Initialisation de chacun des membres de la structure ici
    point->degrees = 45;
    point->minutes=19;
    point->seconds=1;
    /*
        (*point).degrees = 45;
        (*point).minutes=19;
        (*point).seconds=0.8;
    */
}

int main()
{
    DMS* point1;
    initialiserCoordonnees(point1);
    std::cout << "Le contenu de la variable est " 
        << (point1->degrees) << "° " 
        << (point1->minutes) << "' " 
        << (point1->seconds) << "s" 
        << std::endl;
        
    return 0;
}