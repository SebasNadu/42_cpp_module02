#include "Point.hpp"

Point &Point::operator=(Point const &rightHandSide) {
  if (this != &rightHandSide) {
    const_cast<Fixed &>(this->_x) = rightHandSide._x;
    const_cast<Fixed &>(this->_y) = rightHandSide._y;
  }
  return *this;
}

Point Point::operator-(Point const &rightHandSide) const {
  return Point(this->_x - rightHandSide.getX(),
               this->_y - rightHandSide.getY());
}
