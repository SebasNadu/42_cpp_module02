/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasnadu <johnavar@student.42berlin.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 21:45:11 by sebasnadu         #+#    #+#             */
/*   Updated: 2024/03/18 21:45:12 by sebasnadu        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>
#include <iostream>

/* Constructors and destructors */
Fixed::Fixed(void) : _rawBits(0){};

Fixed::Fixed(Fixed const &instance) { *this = instance; }

Fixed::Fixed(int const value) {
  this->_rawBits = value << Fixed::_fractionalPoint;
}

Fixed::Fixed(float const value) {
  this->_rawBits =
      static_cast<int>(roundf(value * (1 << Fixed::_fractionalPoint)));
}

Fixed::~Fixed(void) {}

/* Operators overloads */
/* Comparison operators */
Fixed &Fixed::operator=(Fixed const &rightHandSide) {
  if (this != &rightHandSide)
    this->_rawBits = rightHandSide._rawBits;
  return *this;
}

std::ostream &operator<<(std::ostream &out, Fixed const &instance) {
  out << instance.toFloat();
  return out;
}

bool Fixed::operator<(Fixed const &rightHandSide) const {
  return this->_rawBits < rightHandSide._rawBits;
}

bool Fixed::operator>(Fixed const &rightHandSide) const {
  return rightHandSide < *this;
}

bool Fixed::operator>=(Fixed const &rightHandSide) const {
  return !(*this < rightHandSide);
}

bool Fixed::operator<=(Fixed const &rightHandSide) const {
  return !(*this > rightHandSide);
}

bool Fixed::operator==(Fixed const &rightHandSide) const {
  return this->_rawBits == rightHandSide._rawBits;
}

bool Fixed::operator!=(Fixed const &rightHandSide) const {
  return !(*this == rightHandSide);
}

/* Arithmetic operators */
Fixed Fixed::operator+(Fixed const &rightHandSide) const {
  Fixed tmp;
  tmp._rawBits = this->_rawBits + rightHandSide._rawBits;
  return tmp;
}

Fixed Fixed::operator-(Fixed const &rightHandSide) const {
  Fixed tmp;
  tmp._rawBits = this->_rawBits - rightHandSide._rawBits;
  return tmp;
}

Fixed Fixed::operator*(Fixed const &rightHandSide) const {
  return Fixed(this->toFloat() * rightHandSide.toFloat());
}

Fixed Fixed::operator/(Fixed const &rightHandSide) const {
  if (rightHandSide.toFloat() == 0) {
    std::cout << "Cannot divide by 0" << std::endl;
    return Fixed();
  }
  return Fixed(this->toFloat() / rightHandSide.toFloat());
}

/* Increment/decrement operators */
Fixed &Fixed::operator++(void) {
  ++(this->_rawBits);
  return *this;
}

Fixed &Fixed::operator--(void) {
  --(this->_rawBits);
  return *this;
}

Fixed Fixed::operator++(int) {
  Fixed tmp(*this);
  ++(this->_rawBits);
  return tmp;
}

Fixed Fixed::operator--(int) {
  Fixed tmp(*this);
  --(this->_rawBits);
  return tmp;
}

/* Member Functions */
/* Overloaded member functions */
Fixed &Fixed::min(Fixed &a, Fixed &b) {
  if (a < b)
    return a;
  return b;
}

Fixed const &Fixed::min(Fixed const &a, Fixed const &b) {
  if (a < b)
    return a;
  return b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b) {
  if (a > b)
    return a;
  return b;
}

Fixed const &Fixed::max(Fixed const &a, Fixed const &b) {
  if (a > b)
    return a;
  return b;
}

/* Public member functions */
int Fixed::getRawBits(void) const {
  std::cout << "getRawBits member function called" << std::endl;
  return this->_rawBits;
}

void Fixed::setRawBits(int const rawBits) {
  std::cout << "setRawBits member function called" << std::endl;
  this->_rawBits = rawBits;
}

float Fixed::toFloat(void) const {
  return static_cast<float>(this->_rawBits) / (1 << Fixed::_fractionalPoint);
}

int Fixed::toInt(void) const {
  return this->_rawBits >> Fixed::_fractionalPoint;
}
