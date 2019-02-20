#ifndef RUBRICA_H
#define RUBRICA_H

#include "voce.h" // voce

/**
	Eccezione custom che rappresenta l'evento di rubrica piena.
	Possiamo usare una classe vuota per rappresentare una eccezione.
	Vedremo poi come derivarle dalle eccezioni standard.

	@brief Eccezione custom che rappresenta l'evento di rubrica piena.
*/
class rubrica_full_exception{};

/**
	Eccezione custom che rappresenta l'evento di voce duplicata.

	@brief Eccezione custom che rappresenta l'evento di voce duplicata.
*/
class voce_duplicated_exception{};

/**
	Eccezione custom che rappresenta l'evento di voce non valida.

	@brief Eccezione custom che rappresenta l'evento di voce non valida.
*/
class set_voce_exception{};

/**
	Eccezione custom che rappresenta l'evento di voce non trovata.

	@brief Eccezione custom che rappresenta l'evento di voce non trovata.
*/
class voce_not_found_exception {};


/**
	Eccezione custom che rappresenta l'evento di errore su file.

	@brief Eccezione custom che rappresenta l'evento di errore su file.
*/
class errore_file_exception {};


/**
	Classe che rappresenta una rubrica telefonica che ha una capacita' definita.
	Si possono aggiungere voci fino alla capacita' della rubrica. Non si puo'
	inserire una voce duplicata. A scopo didattico abbiamo anche introdotto il vincolo che
	non si puo' settare una voce che ha lo stesso numero telefonico di una gia' presente nella rubrica.
	Siccome la rubrica ha una capacita' non nota a priori, si usa un array dinamico di voci.

	@brief Classe che rappresenta una rubrica telefonica
*/
class rubrica {
	voce *_voci; ///< puntatore all'array di voci
	unsigned int _capacity; ///< dimensione dell'array
	unsigned int _count; ///< numero di voci inserite

public:

	/**
		Costruttore di default
	*/
	rubrica();

	/**
		Copy constructor
		@param other la rubrica da usare per costruire quella attuale
	*/
	rubrica(const rubrica &other);

	/**
		Operatore di assegnamento
		@param other la rubrica da usare per riempire quella attuale
		@return la rubrica modificata con i nuovi valori
	*/
	rubrica& operator=(const rubrica &other);

	/**
		Distruttore
	*/
	~rubrica();

	/**
		Costruttore secondario che permette di costruire una rubrica di una data capacita'
		@param cap capacita' che deve avere la rubrica
	*/
	explicit rubrica(unsigned int cap);

	/**
		Metodo che permette di cambiare la capacita della rubrica. Se la nuova capacita'
		lo consente le vecchie voci sono mantenute.
		@param cap capacita' che deve avere la rubrica
	*/
	void set_capacity(unsigned int cap);

	/**
		Scambia il contenuto di due voci
		@param other voce il cui contenuto e' da scambiare con quello di this
	*/
	void swap(rubrica &other);

	/**
		Getter della capacita' della rubrica
		@return la capacita' della rubrica
	*/
	unsigned int get_capacity(void) const;

	/**
		Getter del numero di voci inserite
		@return il numero di voci inserite nella rubrica
	*/
	unsigned int get_count(void) const;

	/**
		Getter della voce i-esima
		@param index indice della voce da leggere
		@return la voce alla posizione index-esima
	*/
	const voce &operator[](unsigned int index) const;

	/**
		Setter di una voce. La voce e' verificata prima di essere scritta
		@param index indice della voce da sostituire
		@param value voce da inserire
		@throw set_voce_exception nel caso in cui la voce non e' valida
	*/
	void set_voce(unsigned int index, const voce &value);

	/**
		Inserimento di una voce
		@param v voce da inserire
		@throw rubrica_full_exception nel caso in cui la rubrica sia piena
		@throw voce_duplicated_exception nel caso in cui il numero di telefono sia gia' presente
	*/
	void add(const voce &v);

	/**
		Inserimento di una voce
		@param n nome della voce
		@param c cognome della voce
		@param nt numero di telefono della voce
		@throw rubrica_full_exception nel caso in cui la rubrica sia piena
		@throw voce_duplicated_exception nel caso in cui il numero di telefono sia gia' presente
	*/
	void add(const std::string &n,
					 const std::string &c,
					 const std::string &nt);

	/**
		Cerca l'esistenza di un numero di telefono con l'eventuale recupero della
		relativa voce.
		@param nt numero di telefono da cercare
		@return la voce associata al numero cercato
		@throw voce_not_found_exception se il numero di telefono non e' trovato
	*/
	const voce &find(const std::string &nt) const;

	/**
		Svuota il contenuto della rubrica senza cambiare la capacita'.
	*/
	void clear(void);

	/**
		Salvataggio del contenuto della rubrica su file di testo
		@param nomefile nome del file da scrivere
		@throw errore_file nel caso in cui ci siano problemi con il file
	*/
	void save(const std::string &nomefile) const;

	/**
		Caricamento del contenuto della rubrica da file di testo
		@param nomefile nome del file da leggere
		@throw errore_file nel caso in cui ci siano problemi con il file
	*/
	void load(const std::string &nomefile);
};

/**
	Ridefinizione dell'operatore << per scivere il contenuto della rubrica su stream
	@param os stream di output su cui mandare la voce
	@param r rubrica da spedire sullo stream
	@return il riferimento allo stream di output
*/
std::ostream& operator<<(std::ostream &os,
	const rubrica &r);

#endif
