#ifndef BICYCLE_H
#define BICYCLE_H
class Bicycle {
  public:
    Bicycle();
    Bicycle(int c, int g, int s);
    void changeCadence(int c);
    void changeGear(int g);
    void speedUp(int inc);
    void applyBakers(int dec);
    void printStates();

  private:
    int cadence;
    int speed;
    int gear;
};
#endif
