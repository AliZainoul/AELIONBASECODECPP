#include <iostream>

class Person{
private: 
    // Members:
        size_t age;
        size_t ID;
        std::string name;
public:


    // Constructor:
        Person(size_t _age, size_t _ID, std::string _name){
            age = _age;
            ID = _ID;
            name = _name;
        }
    
    // Getters
        const size_t& getAge() const {return age;}
        const size_t& getID() const {return ID;}
        const std::string& getName() const {return name;}

};

// B IS A DERIVED CLASS FROM A
class Employee : public Person
{
public:
    // Members 
    double salary;
    Employee(size_t _age, size_t _ID, std::string _name, double _salary):
    Person(_age, _ID, _name), salary(_salary){}
};

int main()
{
    Employee e(42, 3666666, "BruceLee", 10000000.00);
    std::cout << "------------------ Informations ---------------- " << "\n"
        << "Age of the employee is: " << (e.getAge()) << "\n"
        << "ID of the employee is: " << (e.getID()) << "\n"
        << "Name of the employee is: " << (e.getName())  << "\n"
        << "Salary of the employee is: " << (e.salary) << "\n";
    return 0;
}

// DIAMOND PROBLEM: A hérite de B et de C, et B et C héritent de D. 
// pour éviter un tel problème, on déclare initialement les classes B et C dans A. 
// FORWARD DECLARATION !! 