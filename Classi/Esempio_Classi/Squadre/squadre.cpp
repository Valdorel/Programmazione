#include <iostream>
#include <iomanip>
#include <string>


const int PUNTI_PER_VITTORIA = 3;
const int PUNTI_PER_PAREGGIO = 1;
const int PUNTI_PER_SCONFITTA = 0;




class Squadra {
  private:
    std::string nome;
    int pVinte;
    int pPerse;
    int pPareggiate;


  public:
    Squadra();
    Squadra(string n);


    string get_nome() { return nome; }
    void set_nome(string n) { nome = n; }

    int get_vinte() { return pVinte; }
    void set_vinte(int v) { pVinte = v; }

    int get_pareggio() { return pPareggiate; }
    void set_pareggio(int p) { pPareggiate = p; }

    int get_perse() { return pPerse; }
    void set_perse(int p) { pPerse = p; }

    int punti();
    void inizioAnno();
};



Squadra::Squadra() : nome(" "), pVinte(0), pPareggiate(0), pPerse(0) {}

Squadra::Squadra(string n) : nome(n), pVinte(0), pPareggiate(0), pPerse(0) {}

int Squadra::punti() {
  return pVinte * PUNTI_PER_VITTORIA + pPareggiate * PUNTI_PER_PAREGGIO +
    pPerse * PUNTI_PER_SCONFITTA;
}


void Squadra::inizioAnno() {
  pVinte = 0;
  pPareggiate = 0;
  pPerse = 0;
}


int main(int argc, char const *argv[]) {
  Squadra s1("Juventus");
  Squadra s2("Milan");
  char scelta;

  do {
    int v, p, s;

    std::cout << "Numero di vittorie, pareggi e sconfitte per la squadra" <<
    s1.get_nome() << ": ";
    std::cin >> v >> p >> s;

    s1.set_vinte(v);
    s1.set_pareggio(p);
    s1.set_perse(s);

    std::cout << "Numero di vittorie, pareggi e sconfitte per la squadra" <<
    s2.get_nome() << ": ";

    s2.set_vinte(v);
    s2.set_pareggio(p);
    s2.set_perse(s);


    cout << "Risultato finale" << endl;
    cout << "----------------" << endl;
    cout << setw(15) << s1.get_nome() << "\t" << s1.punti() << " punti" << endl;
    cout << setw(15) << s2.get_nome() << "\t" << s2.punti() << " punti" << endl << endl;


    if (s1.punti() != s2.punti() ) {
      std::cout << "Campionato vinto dalla squadra " << (s1.punti() > s2.punti()
        ? s1.get_nome() : s2.get_nome()) << endl;
    }

    else {
      cout << "Situazione di pari merito, e' necessario procedere allo spareggio" << endl;
    }

    std::cout << endl << "Continuare con un nuovo campionato [S/N]?: ";
    std::cin >> scelta;


    s1.inizioAnno();
    s2.inizioAnno();

 } while(scelta == 'S' || scelta == 's');


 return 0;


}
