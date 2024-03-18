/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasnadu <johnavar@student.42berlin.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 21:44:57 by sebasnadu         #+#    #+#             */
/*   Updated: 2024/03/18 21:44:59 by sebasnadu        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

int main(void) {
  Fixed a;
  Fixed const b(Fixed(5.05f) * Fixed(2));
  std::cout << a << std::endl;
  std::cout << ++a << std::endl;
  std::cout << a << std::endl;
  std::cout << a++ << std::endl;
  std::cout << a << std::endl;
  std::cout << b << std::endl;
  std::cout << Fixed::max(a, b) << std::endl;

  /* std::cout << "-------------------" << std::endl; */
  /* std::cout << Fixed::min(a, b) << std::endl; */
  /* if (a < b) */
  /*   std::cout << "a < b" << std::endl; */
  /* if (a > b) */
  /*   std::cout << "a > b" << std::endl; */
  /* if (a <= b) */
  /*   std::cout << "a <= b" << std::endl; */
  /* if (a >= b) */
  /*   std::cout << "a >= b" << std::endl; */
  /* if (a == b) */
  /*   std::cout << "a == b" << std::endl; */
  /* if (a != b) */
  /*   std::cout << "a != b" << std::endl; */
  /* std::cout << a + b << std::endl; */
  /* std::cout << a - b << std::endl; */
  /* std::cout << a * b << std::endl; */
  /* std::cout << a / b << std::endl; */
  /* std::cout << b / a << std::endl; */
  return 0;
}
