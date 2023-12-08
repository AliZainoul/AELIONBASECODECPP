#include <iostream>
#include <random>

void fillRandomList(std::vector<int>* toto) {
    for (auto& i : *toto)  i = std::rand();
}

void displayVector(std::vector<int>* toto){
    std::cout << "[" ;
    for (auto& i : *toto) {
        std::cout << i;
        if (i != *((*toto).end()-1))  std::cout << ", ";
    }
    std::cout << "]" ;
}

int main() {
    std::vector<int > vect(10);
    fillRandomList(&vect);
    displayVector(&vect);
    return 0;
}