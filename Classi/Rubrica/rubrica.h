#ifndef RUBRICA_H
#define RUBRICA_H
 #include "voce.h"


 class rubrica_full_exception{};

 class voce_duplicated_exception {};

 class set_voce_exception {};

 class voce_not_found_exception {};

 class errore_file_exception {};

 class rubrica {
   voce *_voci;
   unsigned int _capacity;
   unsigned int _count;

 public:

   rubrica();

   ~rubrica();

   rubrica(const rubrica &other);

   rubrica &operator=(const rubrica &other);

   explicit rubrica(unsigned int cap);

   void set_capacity(unsigned int cap);

   void swap(rubrica &other);
   //getter della capacità della rubrica
   unsigned int get_capacity() const;

   unsigned int get_count() const;

   //getter della voce i-esima
   const voce &operator[](unsigned int index) const;


   //setter di una voce. La voce è verificata prima di essere scritta
   void set_voce(unsigned int index, const voce &value);

   //Inserimento di una voce

   void add(const voce &v);

   void add(const std::string &n, const std::string &c, const std::string &nt);

   const voce &find (const std::string &nt) const;

   void clear();

   void save(const std::string &nomefile) const;

   void load(const std::string &nomefile);
 };



 std::ostream& operator<<(std::ostream &os,
	const rubrica &r);
#endif
