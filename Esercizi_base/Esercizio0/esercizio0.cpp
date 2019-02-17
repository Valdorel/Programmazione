#include <iostream>
#include <cmath>

double f(double x) {
  return std::sin(x);
}

int main(int argc, char const *argv[]) {
  double a = 0;
  double b = M_PI;
  int n;
  //std::cout << b << '\n';
  std::cout << "Inserire il numero di sottointervalli" << '\n';
  std::cin >> n;
  double delta_x = (b-a)/n;

  double result = 0;

  for (int i = 1; i <= n; i++) {
    result = result + ((f(a+(i-1)*delta_x)) + (f(a+i)*delta_x))/2;
  }

  std::cout << "Il risultato dell'integrale e': "<< result << '\n';







  return 0;
}
