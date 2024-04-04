#include "Point.hpp"

Point::Point(float const x, float const y) : _x(x), _y(y){};
Point::Point(Fixed const x, Fixed const y) : _x(x), _y(y){};
Point::Point(Point const &src) : _x(src._x), _y(src._y){};

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
