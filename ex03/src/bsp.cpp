#include "Fixed.hpp"
#include "Point.hpp"
#include <iostream>

namespace {
Fixed const areaTriangle(Point const a, Point const b, Point const c) {
  return (a.getX() - c.getX()) * (b.getY() - c.getY()) -
         (a.getY() - c.getY()) * (b.getX() - c.getX());
}
} // namespace

bool bsp(Point const a, Point const b, Point const c, Point const point) {
  if (areaTriangle(a, b, c) >= 0) {
    return areaTriangle(a, b, point) > 0 && areaTriangle(b, c, point) > 0 &&
           areaTriangle(c, a, point) > 0;
  } else {
    return areaTriangle(a, b, point) < 0 && areaTriangle(b, c, point) < 0 &&
           areaTriangle(c, a, point) < 0;
  }
}

bool bspWithBorders(Point const a, Point const b, Point const c,
                    Point const point) {
  if (areaTriangle(a, b, c) >= 0) {
    return areaTriangle(a, b, point) >= 0 && areaTriangle(b, c, point) >= 0 &&
           areaTriangle(c, a, point) >= 0;
  } else {
    return areaTriangle(a, b, point) <= 0 && areaTriangle(b, c, point) <= 0 &&
           areaTriangle(c, a, point) <= 0;
  }
}
