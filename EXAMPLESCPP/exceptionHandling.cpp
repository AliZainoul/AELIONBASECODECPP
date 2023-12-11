/*
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wdivision-by-zero"

#include <iostream>
#include <stdexcept>


int main() {
    try {
        // Code that may throw an exception
        int result = 10 / 0;
    } catch (const std::exception& e) {
        // Catching and handling the exception
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
    return 0;
}

#pragma GCC diagnostic pop
*/


#include <iostream>
#include <stdexcept>

class myCustomException : std::exception { 
    const char* what() const noexcept 
    { 
        return "Hello"
               " from what method"
               " inside mycustomexception class/struct"; 
    } 
}; 
  

int main() {
    try {
        // Code that may throw an exception
        int result = 10 / 0;
        throw myCustomException();
    } catch (const std::exception& e) {
        // Catching and handling the exception
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
    return 0;
}





/*
// C++ code for exception::what() 
#include <iostream>  
#include <stdexcept>

using namespace std; 
  
class myCustomException : exception { 
    const char* what() const noexcept 
    { 
        return "Hello"
               " from what method"
               " inside mycustomexception class/struct"; 
    } 
}; 
  
// main method 
int main() 
{ 
  
    // try block 
    try { 
        throw myCustomException(); 
    } 
  
    // catch block to handle the errors 
    catch (const std::exception& myCustomExceptionError) { 
        cerr << myCustomExceptionError.what(); 
    } 
  
    return 0; 
} 
*/


/*
#include <iostream>
#include <stdexcept>

class myCustomException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Custom exception occurred!";
    }
};

int main() {
    try {
        // Code that may throw a custom exception
        throw myCustomException();
    } catch (const std::exception& e) {
        // Catching and handling the custom exception
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
    return 0;
}
*/
