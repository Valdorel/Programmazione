#include "nsqrt.h"
#include <iostream>
#include <cmath>

int main(int argc, char const *argv[]) {

  int x;
  std::cout << "Inserire un numero intero positivo" << '\n';
  std::cin >> x;


  double y = nsqrt(x, 1e-6);
  //double z = std::sqrt(x);

  std::cout << "La radice quadrata di "<< x << " e': "<< y << '\n';

  return 0;
}
