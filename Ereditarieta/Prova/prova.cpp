#include <iostream>

/*class Base {
public:
  Base() {std::cout << "Base" << '\n';}
  Base(const Base& other) {std::cout << "Base(const Base&)" << '\n';}
  ~Base() {std::cout << "~Base" << '\n';}
};

class Member1 {
public:
  Member1() {std::cout << "Member1" << '\n';}
  ~Member1() {std::cout << "~Member1" << '\n';}
};

class Member2 {
public:
  Member2() {std::cout << "Member2" << '\n';}
  ~Member2() {std::cout << "~Member2" << '\n';}
};

class Derived : public Base {
  Member1 m1;
  Member2 m2;
public:
  Derived() {std::cout << "Derived" << '\n';}
  ~Derived() {std::cout << "~Derived" << '\n';}
};


int main(int argc, char const *argv[]) {
  Derived d;

  return 0;
}*/


class base {
  int data;
public:
  void whoAmI() {std::cout << "base" << '\n';}
};

class derived : public base {
  int data;
public:
  void whoAmI() {std::cout << "derived" << '\n';}
};

void ExecuteIt(base b) {
  
}


int main(int argc, char const *argv[]) {

  derived d;
  ExecuteIt(d);

  return 0;
}
