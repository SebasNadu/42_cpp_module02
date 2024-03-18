/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasnadu <johnavar@student.42berlin.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 21:45:22 by sebasnadu         #+#    #+#             */
/*   Updated: 2024/03/18 21:45:23 by sebasnadu        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

  /* Comparison operators */
  bool operator<(Fixed const &rightHandSide) const;
  bool operator>(Fixed const &rightHandSide) const;
  bool operator>=(Fixed const &rightHandSide) const;
  bool operator<=(Fixed const &rightHandSide) const;
  bool operator==(Fixed const &rightHandSide) const;
  bool operator!=(Fixed const &rightHandSide) const;
  /* Arithmetic operators */
  Fixed operator+(Fixed const &rightHandSide) const;
  Fixed operator-(Fixed const &rightHandSide) const;
  Fixed operator*(Fixed const &rightHandSide) const;
  Fixed operator/(Fixed const &rightHandSide) const;
  /* Increment/decrement operators */
  Fixed &operator++(void);
  Fixed &operator--(void);
  Fixed operator++(int);
  Fixed operator--(int);

  /* Overloaded member functions */
  static Fixed &min(Fixed &a, Fixed &b);
  static Fixed const &min(Fixed const &a, Fixed const &b);
  static Fixed &max(Fixed &a, Fixed &b);
  static Fixed const &max(Fixed const &a, Fixed const &b);

  /* Public member functions */
  int getRawBits(void) const;
  void setRawBits(int const raw);
  float toFloat(void) const;
  int toInt(void) const;

private:
  int _rawBits;
  static int const _fractionalPoint = 8;
};

std::ostream &operator<<(std::ostream &out, Fixed const &instance);
