#include <iostream>
int main() 
{
    int age;
    std::string name;
    std::cout << "Hello please enter your name " << "\n";
    std::cin >> name;

    std::cout << "Please enter your age " << "\n";
    std::cin >> age;

    std::cout << "Hello, my name is " << name << " and I have " << age << " YO." << "\n";
    // REMARK: we call the "::" operator of resolution;
    // furthermore, string and cout are classes of the std (
    // namespace) library.
    return 0; 
}