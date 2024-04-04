/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasnadu <johnavar@student.42berlin.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 21:44:57 by sebasnadu         #+#    #+#             */
/*   Updated: 2024/04/04 21:24:06 by sebasnadu        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"
#include <iomanip>
#include <iostream>

#define GREY "\033[90m"
#define YELLOW "\033[93m"
#define GREEN "\033[92m"
#define RED "\033[91m"
#define RESET "\033[0m"
#define BOLD "\033[1m"

char **createGrid(int height, int width) {
  char **grid = new char *[height];

  for (int i = 0; i < height; i++) {
    grid[i] = new char[width];
  }
  return (grid);
}

void deleteGrid(char **grid, int height) {
  for (int i = 0; i < height; i++)
    delete[] grid[i];
  delete[] grid;
}

void drawTriangle(Point a, Point b, Point c, Point p, int mode) {
  char fill = 'X';
  char empty = '.';
  Fixed minX = Fixed::min(Fixed::min(a.getX(), b.getX()), c.getX());
  Fixed maxX = Fixed::max(Fixed::max(a.getX(), b.getX()), c.getX());
  Fixed minY = Fixed::min(Fixed::min(a.getY(), b.getY()), c.getY());
  Fixed maxY = Fixed::max(Fixed::max(a.getY(), b.getY()), c.getY());
  int width = maxX.toInt() - minX.toInt() + 3;
  int height = maxY.toInt() - minY.toInt() + 3;

  char **grid = createGrid(height, width);
  for (int y = height - 2; y >= -1; y--) {
    for (int x = -1; x < width - 1; x++) {
      if (bspWithBorders(a, b, c,
                         Point((x + minX.toInt()), (y + minY.toInt()))))
        grid[y + 1][x + 1] = fill;
      else
        grid[y + 1][x + 1] = empty;
    }
  }
  std::cout << '\n';
  for (int y = height - 2; y >= -1; y--) {
    if (y + minY.toInt() < 0)
      std::cout << GREY << '-' << std::setfill('0') << std::setw(2)
                << (y + minY.toInt()) * -1 << "  " << RESET;
    else
      std::cout << GREY << std::setfill('0') << std::setw(3) << y + minY.toInt()
                << "  " << RESET;
    for (int x = -1; x < width - 1; x++) {
      if ((Fixed)(x + minX.toInt()) == p.getX() &&
          (Fixed)(y + minY.toInt()) == p.getY() && grid[y + 1][x + 1] == fill &&
          bsp(a, b, c, Point(x + minX.toInt(), (y + minY.toInt()))) &&
          mode == 1)
        std::cout << BOLD << GREEN << "Y   " << RESET;
      else if ((Fixed)(x + minX.toInt()) == p.getX() &&
               (Fixed)(y + minY.toInt()) == p.getY() && mode == 1 &&
               ((grid[y + 1][x + 1] == fill &&
                 !bsp(a, b, c, Point(x + minX.toInt(), (y + minY.toInt())))) ||
                grid[y + 1][x + 1] != fill))
        std::cout << BOLD << RED << "N   " << RESET;
      else if (grid[y + 1][x + 1] == fill) {
        if (!bsp(a, b, c, Point((x + minX.toInt()), (y + minY.toInt())))) {
          std::cout << YELLOW << grid[y + 1][x + 1] << "   " << RESET;
        } else {
          std::cout << grid[y + 1][x + 1] << "   ";
        }
      } else
        std::cout << GREY << grid[y + 1][x + 1] << "   " << RESET;
    }
    std::cout << "\n\n";
  }
  std::cout << "   ";
  for (int x = -1; x < width - 1; x++) {
    if (x + minX.toInt() < 0)
      std::cout << GREY << '-' << std::setfill('0') << std::setw(2)
                << (x + minX.toInt()) * -1 << " " << RESET;
    else
      std::cout << GREY << std::setfill('0') << std::setw(3) << x + minX.toInt()
                << " " << RESET;
  }
  std::cout << '\n' << std::endl;
  deleteGrid(grid, height);
}

bool getInputPoint(Point *point, std::string const &name) {
  float x;
  float y;

  std::cout << "Point " << name << ":\n";
  std::cout << "x = ";
  std::cin >> x;
  if (std::cin.fail()) {
    std::cout << RED << "\n\tWrong input\n" << std::endl;
    return (false);
  }
  std::cout << "y = ";
  std::cin >> y;
  if (std::cin.fail()) {
    std::cout << RED << "\n\tWrong input\n" << std::endl;
    return (false);
  }
  std::cout << '\n';
  Point tmp(x, y);
  *point = tmp;
  return (true);
}

int main(void) {
  Point a;
  Point b;
  Point c;
  Point point;

  std::cout << BOLD
            << "Plese enter the coordinates of the vertices of the triangle"
            << RESET << '\n';
  if (!getInputPoint(&a, "A"))
    return (1);
  if (!getInputPoint(&b, "B"))
    return (1);
  if (!getInputPoint(&c, "C"))
    return (1);
  drawTriangle(a, b, c, Point(0, 0), 0);
  std::cout << BOLD
            << "Now please enter the coordinates of the point you want to test."
            << RESET << '\n';
  if (!getInputPoint(&point, "Point"))
    return (1);
  drawTriangle(a, b, c, point, 1);
  if (bsp(a, b, c, point))
    std::cout << GREEN << "\n\tThe position (" << point.getX() << ","
              << point.getY() << ") is inside the triangle" << RESET << '\n'
              << std::endl;
  else
    std::cout << RED << "\n\tThe position (" << point.getX() << ","
              << point.getY() << ") is outside the triangle" << RESET << '\n'
              << std::endl;
  return 0;
}
