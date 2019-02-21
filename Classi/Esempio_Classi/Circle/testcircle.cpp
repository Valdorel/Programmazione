#include <iostream>
#include "circle.h"

int main(int argc, char const *argv[])
{
  circle c1(1.2, "red");
  std::cout << "Radius=" << c1.getRadius() << " Area=" << c1.getArea()<< " Color=" << c1.getColor() <<'\n';
  c1.setRadius(2.1);
  c1.setColor("blue");
  std::cout << "Radius=" << c1.getRadius() << " Area=" << c1.getArea()<< " Color=" << c1.getColor() << '\n';
  c1.setRadius(2.1);

  circle c2;
  std::cout << "Radius=" << c2.getRadius() << " Area=" << c2.getArea()<< " Color=" << c2.getColor()  << '\n';


  return 0;
}
