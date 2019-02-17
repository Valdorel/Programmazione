#include "nsqrt.h"

double nsqrt(double x, double epsilon) {
  if (x == 0) {
    return 0;
  }



  double s = x/2;

  double check = 0;

  do {
    s = ((s * s) + x)/(2*s);
    check = (s*s)-x;
  } while(check < -epsilon || check > epsilon);

  return s;
}
