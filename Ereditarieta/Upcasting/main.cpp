#include <iostream>

class Instrument {
public:
  Instrument(void) {std::cout << "Instrument::Instrument()" << '\n';}
  ~Instrument() {std::cout << "Instrument::~Instrument()" << '\n';}
};


class Harp : public Instrument {
public:
  Harp() {std::cout << "Harp::Harp()" << '\n';}
  ~Harp() {std::cout << "Harp::~Harp()" << '\n';}
};

/*class Violin : public Instrument {
public:
  Violin() {}
  void play() {std::cout << "Violin::play()" << '\n';}
};

void play_instrument(Instrument &b) {
  b.play();
}
*/
int main() {
  Harp *h = new Harp;

  delete h;
  return 0;
}
