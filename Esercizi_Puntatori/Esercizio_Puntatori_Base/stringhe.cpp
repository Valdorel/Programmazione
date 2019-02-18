#include <iostream>
#include "ese_stringhe.h"

int main(int argc, char*argv[]){

	// Ricordate che il primo argomento e' sempre il path dell'eseguibile
	// Gli argomenti sono: stringa token filler
	// Stringa e token saranno usate anche nella concatenazione
	if(argc!=4) {
		std::cout<<"Passare tre stringhe!"<<std::endl;
		return 0;
	}

	char *res=concat_string(argv[1],argv[2]);

	std::cout<<res<<std::endl;

	// IMPORTANTE: Dato che res e' stato creato (dalla funzione concat_string) dinamicamente
	// con la new, e' necessario rimuoverlo dalla memoria con la delete[].
	// Se non viene rimosso esplicitamente si ha memory leak alla fine del programma.
	// E' un grave errore di memoria.
	delete[] res;

	const char *start_token = find_token(argv[1],argv[2]);
	std::cout<<start_token<<std::endl;

	std::cout<< overwrite_token(argv[1],argv[2],argv[3]) << std::endl;

	return 0;
}
