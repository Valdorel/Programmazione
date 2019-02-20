#include "rubrica.h"
#include <iostream>
#include <cassert>





void test_voce()
{
  voce v;

  std::cout << v << '\n';
  assert(v.nome == "");
  assert(v.cognome == "");
  assert(v.ntel == "");

  //Costruttore
  voce v2("Paolino", "Paperino", "313");
  std::cout << v2 << '\n';
  assert(v2.nome == "Paolino");
  assert(v2.cognome == "Paperino");
  assert(v2.ntel == "313");

  //Copy constructor
  voce v3(v2);
  std::cout << v3 << '\n';
  assert(v3.nome == "Paolino");
  assert(v3.cognome == "Paperino");
  assert(v3.ntel == "313");

  v = v2;
  std::cout << v << '\n';
  assert(v.nome == "Paolino");
  assert(v.cognome == "Paperino");
  assert(v.ntel == "313");

  v.nome = "Mickey";
  v.cognome = "Mouse";
  v.ntel = "111";

  std::cout << v << '\n';

  assert(v.nome == "Mickey");
  assert(v.cognome == "Mouse");
  assert(v.ntel == "111");


  v.swap(v2);
  assert(v2.nome == "Mickey");
  assert(v2.cognome=="Mouse");
	assert(v2.ntel=="111");
	assert(v.nome=="Paolino");
	assert(v.cognome=="Paperino");
	assert(v.ntel=="313");
}



void test_rubrica()
{
  rubrica r1;

  std::cout << r1 << '\n';
  rubrica r2(10);

  std::cout << r2 << '\n';

  r1 = r2;

  std::cout << r1 << '\n';
  rubrica r3 = r2;

  try {
    r3.add("nome1","cognome1","2222222");
		r3.add("nome2","cognome2","2222227");
		r3.add("nome3","cognome3","22272222");
		r3.add("nome4","cognome4","22212222");
		r3.add("nome5","cognome5","22229222");
		r3.add("nome6","cognome6","23222222");
		r3.add("nome7","cognome7","222222222");
		r3.add("nome8","cognome8","229822222");
		r3.add("nome9","cognome9","20022222");
		r3.add("nome10","cognome10","222652222");
		r3.add("nome11","cognome11","55555555");
  }
  catch(rubrica_full_exception &e) {
    std::cout << "errore di rubrica piena" << '\n';
  }
  try {
    voce v = r3.find("999999");
  }
  catch(voce_not_found_exception &e) {
		std::cout<<"errore voce non trovata"<<std::endl;
	}

	std::cout<< r3.find("222652222") << std::endl;

	r3.set_voce(0,voce("nome12","cognome12","555123")); // creiamo al volo una voce con il costruttore

	std::cout << r3 << std::endl;

	r3.save("output.txt");
}

void test_load()
{
  rubrica r;
  r.load("output.txt");
  std::cout << r << '\n';
}


void test_interattivo() {
	rubrica rub;

	unsigned int capacity;

	std::cout<<"Inserire la capacita' della rubrica: ";
	std::cin >> capacity;

	if (capacity==0) {
		std::cout << rub << std::endl;
		return;
	}

	rub.set_capacity(capacity);

	std::string cognome, nome, ntel;

	do {
		std::cout<<"Inserire una voce"<<std::endl;
		std::cout<<"  Cognome (* per terminare): ";
		std::cin >> cognome;

		if (cognome!="*") {

			std::cout<<"  Nome: ";
			std::cin >> nome;

			std::cout<<"  Numero Tel: ";
			std::cin >> ntel;

			try {
				rub.add(nome, cognome, ntel);
			}
			catch(rubrica_full_exception &e) {
				std::cout<<"****** Rubrica Piena!"<<std::endl;
				cognome = "*";
			}
			catch(voce_duplicated_exception &e) {
				std::cout<<"****** Voce duplicata. Inserirne un'altra."<<std::endl;
			}
		}
	} while(cognome!="*"); // fine do-while

	std::cout<<rub<<std::endl;

	std::string answer, filename;

	std::cout<<"Vuoi salvare la rubrica (y/n)?";
	std::cin >> answer;

	if (answer[0]=='n') return;

	std::cout<<"Nome del file: ";
	std::cin >> filename;

	try {
		rub.save(filename);
		std::cout<<"Rubrica rub salvata."<<std::endl;

		rubrica rub2;

		rub2.load(filename);

		std::cout<<"Rubrica rub2 caricata."<<std::endl;
		std::cout<<rub2<<std::endl;
	}
	catch(errore_file_exception &e) {
		std::cout << "****** Errore File!"<<std::endl;
	}
}



int main(int argc, char const *argv[])
{
  //test_voce();

  //test_rubrica();

  //test_load();

  test_interattivo();

  return 0;
}
