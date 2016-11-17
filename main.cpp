#include <iostream>
#include "matrix.hpp"

int main(){
  std::cout << "Welcome to linear algebra!" << std::endl;

  // Matrix a;
  // a.display(true);

  Matrix<double> a(5, 2, "1 2 1.1 34 44 456 2 4 6.23");
  Matrix<double> b;
  b = a * 10;
  Matrix<double> c = a + b;

  a.display(true);
  b.display(true);
  c.display(true);


  std::cout << "End of program" << std::endl;
  return EXIT_SUCCESS;
}
