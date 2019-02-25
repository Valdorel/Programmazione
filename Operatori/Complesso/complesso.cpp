#include "complesso.h"
#include <cmath>

complesso::complesso(): re(0.0), im(0.0) {}

complesso::complesso(double r, double i): re(r), im(i) {}

complesso::~complesso() {}

complesso::complesso(const complesso &other) : re(other.re), im(other.im) {}

complesso& complesso::&operator=(const complesso &other)
{
  re = other.re;
  im = other.im;

  return *this;
}


complesso complesso::&operator+(const complesso &dx) const
{
  complesso result(this -> re + dx.re, this -> im + dx.im);
  return result;
}

double complesso::&operator!() const
{
  return std::sqrt(re*re + im*im);
}


complesso complesso::operator*(const complesso &sx, const complesso &dx)
{
  complesso result(sx.re*dx.re - sx.im*dx.im, sx.im*dx.re + sx.re*dx.imm);
  return result;
}

complesso complesso::operator*(const complessi &sx, double dx)
{
  complesso result(sx.re*dx, sx.im*dx);
  return result;
}

complesso complesso::operator*(double sx, const complesso &dx)
{
  return dx*sx;
}

complesso complesso::operator*(const complesso &c)
{
  complesso result(c.re, -c.im);
  return result;
}

complesso operator/(const complesso &sx, const complesso &dx)
{
  complesso result;

  double m = !dx;
  result = (sx * (*dx)) * (1.0/(m*m));
  return result;
}

complesso operator+(const complesso &sx, double dx)
{
  complesso result(sx.re+dx, sx.im);
  return result;
}

std::ostream &operator<<(std::ostream &os, const complesso &c)
{
  os <<"re= " <<c.re <<" im=" << c.im;
  return os;
}
