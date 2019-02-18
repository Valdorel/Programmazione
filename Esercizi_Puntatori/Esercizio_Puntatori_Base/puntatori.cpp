#include "ese_stringhe.h"
#include <iostream>

/**
Della stringa passata come parametro, stampa un carattere per riga
La stringa e' passata const perche' non deve essere modificabile
@param str puntatore a stringa C da stampare
*/
void print_string(const char *str) {

// Si usa il carattere di terminazione speciale \0 per sapere quando sono
// finiti i caratteri della stringa (vale solo per le stringhe!)
while(*str != '\0') {
  std::cout << *str << std::endl;
  str++;
}
}

/**
Calcola la lunghezza della stringa passata come parametro
La stringa e' passata const perche' non deve essere modificabile
@param str puntatore a stringa C da stampare
@return il numero di caratteri della stringa
*/
int string_length(const char *str) {
int len = 0;

// Si usa il carattere di terminazione speciale \0 per sapere quando sono
// finiti i caratteri della stringa
while(*str != '\0') {
  len++;
  str++;
}

return len;
}

/**
Inverte i caratteri della stringa passata come parametro
La stringa e' passata non const perche' deve essere modificata dalla
funzione (modifica in place)
@param str puntatore a stringa C da invertire
*/
void reverse_string(char *str) {
// str2 punta alla fine della stringa
char *str2 = str + string_length(str) - 1;

char c;

// I puntatori si muovono in direzioni opposte e si incontrano
// a meta' della stringa. Questo ci indica la terminazione delle iterazioni.
// In un array, e' garantito che l'indirizzo della cella i e' minore della
// cella i+1
while(str<str2)
{
  c = *str;
  *str = *str2;
  *str2 = c;
  str++;
  str2--;
}
}

/**
Copia la stringa passata come parametro in una nuova dstringa e la ritorna
al chiamante
La stringa e' passata const perche' non deve essere modificabile
Viene ritornato il puntatore alla nuova stringa
@param str puntatore a stringa C da copiare
@return puntatore alla nuova stringa C
*/
char *copy_string(const char *str) {
// E' necessaria l'allocazione dinamica dell'array di caratteri usando la new
// Il +1 serve per il carattere di terminazione
char *var = new char[string_length(str)+1];

// Si copiano i caratteri
for (int i=0; i <= string_length(str); ++i) {
  var[i] = str[i];
}

//Si ritorna la nuova stringa
return var;
}

/**
Concatena due stringhe creandone una nuova che viene ritornata al chiamante
Le due stringhe sono passate const perche' non devono essere modificate
@param s1 puntatore alla prima stringa C
@param s2 puntatore alla seconda stringa C
@return puntatore alla nuova stringa C contenete la concatenazione di s1 e s2
*/
char *concat_string(const char *s1, const char *s2) {
// Si recuperano le dimensioni delle due stringhe
int l1 = string_length(s1);
int l2 = string_length(s2);

// Si crea un array dinamico di caratteri pari alla dimensione delle due stringhe
// + 1 (il carattere di terminazione)
char *res = new char[l1+l2+1];

// Si copiano i caratterei dalla prima stringa
for(int i=0; i<l1; ++i)
  res[i] = s1[i];

// Si copiano i caratteri della seconda stringa
for (int i=l1; i<=l1+l2; ++i)
  res[i] = s2[i-l1];

// Si ritorna il risultato
return res;
}

/**
Cerca la prima occorrenza della stringa token in quella di input
Le due stringhe sono passate const perche' non devono essere modificate
@param s1 puntatore alla stringa di input
@param st puntatore alla stringa token
@return puntatore alla posizione di token nell'input
*/
const char *find_token(const char *s1, const char *st) {
int l1 = string_length(s1);
int lt = string_length(st);


// La stringa s1 va' analizzata dall'inizio fino a lt-1 caratteri prima
// della fine. Memorizzo le posizioni in due puntatori.
const char *pi = s1;
const char *pf = s1+l1-lt+1;

// Puntatore di appoggio per il ciclo for
const char *p=0;
for (p=pi; p < pf; ++p) {
  const char *pt = st; // puntatore all'inizio del token
  const char *pp = p; // Puntatore alla sotto-stringa corrente

  // Fino a che i caratteri della stringa e del token sono uguali e
  // il token non e' finito ci spostiamo ai successivi caratteri
  while (*pt == *pp && *pt!='\0') {
    ++pp;
    ++pt;
  }
  // Se il puntatore del token e' sul carattere di terminazione, il
  // token e' stato trovato. Ritorniamo il puntatore all'inizio del
  // token nella stringa st (p)
  if (*pt == '\0') return p;

  // Alrimenti ci spostiamo di una posizione in s1  e riprendiamo l'analisi
}

// Non e' stato trovato il token: ritorniamo NULL
return 0;
}

// La prima stringa e' passata non const perche' deve essere modificata
// Le altre non devono essere modificate
/**
Sostituisce ogni occorrenza di token nella stringa di input usando la stringa filler
token e filler sono passate const perche' non devono essere modificate
s1 e' passata non const perche' deve essere modificata in place.
@param s1 puntatore alla stringa di input
@param token puntatore alla stringa token
@param filler puntatore alla stringa filler
@return puntatore alla stringa di input modificata
*/
char *overwrite_token(char *s1, const char *token, const char *filler) {
char *res = s1;

int size_token = string_length(token);
int size_filler = string_length(filler);

if (size_filler != size_token) return s1;

// find ritorna un const char* e non possiamo usarlo per modificare i char
// dobbiamo togliere il const dal puntatore con un const_cast
res = const_cast<char*>(find_token(s1,token));

while (res != 0) {

  for(int i = 0 ; i < size_token; ++i)
    res[i] = filler[i];

  res = const_cast<char*>(find_token(res + size_token,token));
}
return s1;
}
