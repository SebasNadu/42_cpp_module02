#include "Fixed.hpp"
#include <cmath>
#include <iostream>

Fixed::Fixed(void) : _rawBits(0) {
  std::cout << "Default constructor called" << std::endl;
};

Fixed::Fixed(Fixed const &instance) {
  std::cout << "Copy constructor called" << std::endl;
  *this = instance;
}

Fixed::Fixed(int const value) {
  std::cout << "Int constructor called" << std::endl;
  this->_rawBits = value << Fixed::_fractionalPoint;
}

Fixed::Fixed(float const value) {
  std::cout << "Float constructor called" << std::endl;
  this->_rawBits =
      static_cast<int>(roundf(value * (1 << Fixed::_fractionalPoint)));
}

Fixed::~Fixed(void) { std::cout << "Destructor called" << std::endl; }

Fixed &Fixed::operator=(Fixed const &rightHandSide) {
  std::cout << "Copy assignment operator called" << std::endl;
  if (this != &rightHandSide)
    this->_rawBits = rightHandSide._rawBits;
  return *this;
}

int Fixed::getRawBits(void) const {
  std::cout << "getRawBits member function called" << std::endl;
  return this->_rawBits;
}

void Fixed::setRawBits(int const raw) {
  std::cout << "setRawBits member function called" << std::endl;
  this->_rawBits = raw;
}

float Fixed::toFloat(void) const {
  return static_cast<float>(this->_rawBits) / (1 << Fixed::_fractionalPoint);
}

int Fixed::toInt(void) const {
  return this->_rawBits >> Fixed::_fractionalPoint;
}

std::ostream &operator<<(std::ostream &out, Fixed const &instance) {
  out << instance.toFloat();
  return out;
}
