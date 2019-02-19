#include "bicycle.h"
#include <iostream>

Bicycle::Bicycle()
{
  cadence = 0;
  gear = 0;
  speed = 0;
}

Bicycle::Bicycle(int c, int g, int s)
{
  cadence = c;
  gear = g;
  speed = s;
}

void Bicycle::changeCadence(int c) {
  cadence = c;
}

void Bicycle::changeGear(int g) {
  gear = g;
}

void Bicycle::speedUp(int inc) {
  speed += inc;
}

void Bicycle::applyBakers(int dec) {
  speed -= dec;
}

void Bicycle::printStates() {
  std::cout << "cadence: " << cadence  << ", speed: " << speed <<", gear: " << gear << '\n';
}
