#include <iostream>
int main() 
{
    int age = 35;
    std::string name = "Akuma";
    std::cout << "Hello, my name is " << name << " and I have " <<
    age << " YO." << "\n";
    // REMARK: we call the "::" operator of resolution;
    // furthermore, string and cout are classes of the std (
    // namespace) library.
    return 0; 
}