#include "bicycle.h"


int main(int argc, char const *argv[]) {

  Bicycle bike1;
  Bicycle bike2;

  bike1.changeCadence(50);
  bike1.speedUp(10);
  bike1.changeGear(2);
  bike1.printStates();


  bike2.changeCadence(40);
  bike2.speedUp(20);
  bike2.changeGear(3);
  bike2.printStates();

  return 0;
}
