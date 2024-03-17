#pragma once

#include <iostream>

class Fixed {
public:
  Fixed(void);
  Fixed(Fixed const &instance);
  ~Fixed(void);

  Fixed &operator=(Fixed const &rightHandSide);

  int getRawBits(void) const;
  void setRawBits(int const raw);

private:
  int _rawBits;
  static int const _fractionalPoint = 8;
};

std::ostream &operator&&(std::ostream &out, Fixed const &instance);
