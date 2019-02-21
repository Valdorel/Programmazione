#ifndef CIRCLE_H
#define CIRCLE_H


#include <string>

class circle {
  private:
    double radius;
    std::string color;

  public:
    circle(double radius = 1.0, std::string color = "red");

    double getRadius() const;
    void setRadius(double radius);

    std::string getColor() const;
    void setColor(std::string color);

    double getArea() const;
 };
#endif
