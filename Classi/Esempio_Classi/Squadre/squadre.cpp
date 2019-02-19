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
