#pragma once

#include "Fixed.hpp"

class Point {
public:
  Point() : _x(0), _y(0){};
  Point(float const x, float const y) : _x(x), _y(y){};
  Point(Fixed const x, Fixed const y) : _x(x), _y(y){};
  Point(Point const &src) : _x(src._x), _y(src._y){};
  ~Point(){};

  Point &operator=(Point const &rightHandSide);
  Point operator-(Point const &rightHandSide) const;

  Fixed const &getX() const { return _x; }
  Fixed const &getY() const { return _y; }

private:
  Fixed const _x;
  Fixed const _y;
};

bool bsp(Point const a, Point const b, Point const c, Point const point);
bool bspWithBorders(Point const a, Point const b, Point const c,
                    Point const point);
