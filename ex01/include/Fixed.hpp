#pragma once

#include <iostream>

class Fixed {
public:
  Fixed(void);
  Fixed(Fixed const &instance);
  Fixed(int const value);
  Fixed(float const value);
  ~Fixed(void);

  Fixed &operator=(Fixed const &rightHandSide);
  // other way to print float into cout is overloading type cast operator
  /* operator float(void) const { return this->toFloat(); } */

  int getRawBits(void) const;
  void setRawBits(int const raw);
  float toFloat(void) const;
  int toInt(void) const;

private:
  int _rawBits;
  static int const _fractionalPoint = 8;
};

std::ostream &operator<<(std::ostream &out, Fixed const &instance);
