#include "circle.h"

circle::circle(double r, std::string c) {
  radius = r;
  color = c;
}

double circle::getRadius() const {
  return radius;
}

void circle::setRadius(double r) {
  radius = r;
}

std::string circle::getColor() const {
  return color;
}

void circle::setColor(std::string c) {
  color = c;
}

double circle::getArea() const {
  return radius*radius*3.1416;
}
