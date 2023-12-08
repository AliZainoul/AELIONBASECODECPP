#include <iostream>

// Utility Function
void draw_line() {
  std::cout << "----------------------------------------------------------------" << std::endl;
}

// GLOBAL VARIABLES IJK
// INITIALIZATION
int i = 10, j = 20, k = 30;


// Main Function
int main() {

  // DISPLAYING THE GLOBAL VARS
    std::cout << "CALL TO GLOBAL VARS Values of gi, gj, gk are: i = " << i << ", j = " << j << " and k = " << k << "." << std::endl;

  // LOCAL VARIABLES IJK
  // Declaration
    int i, j, k;
    std::cout << "CALL TO LOCAL VARS Values of i, j, k are: i = " << i << ", j = " << j << " and k = " << k << "." << std::endl;

  // Initialization of local VARS
  i = 1;
  j = 2;
  k = ++j = (j+=1) = (j=j+1);
  j--;

  // Output
  std::cout << "Values of i, j, k are: i = " << i << ", j = " << j << " and k = " << k << "." << std::endl;
  draw_line();
  std::cout << "All these variables i, j, k are local to the main function." << std::endl;
  draw_line();
  std::cout << "i.e. their visibility is ONLY inside the main function." << std::endl;
  draw_line();
  std::cout << "Outside the main function scope, the variables are destroyed, ";
  std::cout << "hence their memory addresses are freed." << std::endl;
  draw_line();

  return 0;
}
