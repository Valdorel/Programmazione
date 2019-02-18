#include <iostream>

//per passare un argommento da linea di comando devo usare argv[1]
//alla posizione 0 viene messo il path dell'eseguibile


void stampaStringa(const char *p) {
  while(*p != '\0')
  {
    std::cout << *p;
    p++;
  }
  std::cout << '\n';
}

int lunghezzaStringa(const char *p) {
  int length = 0;
  while (*p != '\0') {
    length++;
    p++;
  }
  return length;
}













int main(int argc, char const *argv[]) {

  //std::cout << argv[1] << '\n';

  const char *p = argv[1];
  stampaStringa(p);
  std::cout << "La lunghezza della stringa e': " << lunghezzaStringa(p) << '\n';
  
  return 0;
}
