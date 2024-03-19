#include "Point.hpp"

Point &Point::operator=(Point const &rightHandSide) {
  if (this != &rightHandSide) {
    const_cast<Fixed &>(this->_x) = rightHandSide._x;
    const_cast<Fixed &>(this->_y) = rightHandSide._y;
  }
  return *this;
}
