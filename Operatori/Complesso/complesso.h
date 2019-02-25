#ifndef COMPLESSO_H
#define COMPLESSO_H

 struct complesso {
   double re;
   double im;

 public:
   complesso();

   complesso(double r, double i);

   ~complesso();

   complesso(const complesso &other);

   complesso &operator=(const complesso &other);

   //Somma di 2 numeri complessi
   complesso &operator+(const complesso &dx) const;

   //Modulo
   double &operator!() const;

 };
//prodotto 2 numeri complessi
complesso operator*(const complesso &sx, const complesso &dx);


//prodotto complesso-scalare
complesso operator*(const complesso &sx, double dx);

complesso operator*(double sx, const complesso &dx);


//coniugato
complesso operator*(const complesso &c);

complesso operator/(const complesso &sx, const complesso &dx);

complesso operator+(const complesso &sx, double dx);

std::ostream &operator<<(std::ostream &os, const complesso &c);
#endif
