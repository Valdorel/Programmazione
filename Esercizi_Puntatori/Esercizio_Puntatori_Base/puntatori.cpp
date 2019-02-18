#include <iostream>

//per passare un argommento da linea di comando devo usare argv[1]
//alla posizione 0 viene messo il path dell'eseguibile


void stampaStringa(char *p) {
  while(*p != '\0')
  {
    std::cout << *p;
    p++;
  }
  std::cout << '\n';
}

int lunghezzaStringa(char *p) {
  int length = 0;
  while (*p != '\0') {
    length++;
    p++;
  }
  return length;
}

void stampaInvertita( char *p)
{
  int x = lunghezzaStringa(p);
  while (*p != '\0') {
    p++;
  }

  for (int i = x ; i >= 0;  i--) {
    std::cout << *p;
    p--;
  }
  std::cout << '\n';
}


/*void reverse(char *p) {
  char *str = p - 1 + lunghezzaStringa(p);
  char c;


  while (p < str) {
    c = *p;
    *p = *str;
    *str = c;
    p++;
    str--;
  }
}
*/

char *copy(char *p){
  char *p1 = new char[lunghezzaStringa(p)+1];
  for (int i = 0; i <= lunghezzaStringa(p); i++)
  {
    p1[i] = p[i];
  }
  return p1;
}

char *concatena(char *s1, char *s2) {
  int l1 = lunghezzaStringa(s1);
  int l2 = lunghezzaStringa(s2);

  char *res = new char[l1+l2+1];
  int x = lunghezzaStringa(res);

  for (int i = 0; i < l1; i++)
  {
    res[i] = s1[i];
  }

  for (int i = l1; i < x; i++)
  {
    res[i] = s2[i-l1];
  }

  return res;
}







int main(int argc, char *argv[]) {

  //std::cout << argv[1] << '\n';

  char *p = argv[1];
  stampaStringa(p);
  std::cout << "La lunghezza della stringa e': " << lunghezzaStringa(p) << '\n';
  std::cout << "Stamapa invertita:";
  stampaInvertita(p);

  char *p1 = copy(p);
  std::cout << "Stringa copiata: ";
  stampaStringa(p1);
  char *p2 = argv[2];
  stampaStringa(p2);

  char *p3 = concatena(p1, p2);
  std::cout << "Stringa concatenata: ";
  stampaStringa(p3);





  delete[] p3;
  return 0;
}
