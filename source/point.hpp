#ifndef POINT_HPP
#define POINT_HPP

#include <array>

#include "matrix.hpp"

class Point {
 private:
  std::array<ftype, 3> pt;

 public:
  Point() = default;
  Point(ftype);
  Point(ftype, ftype, ftype);

  ftype const& operator()(int) const;
  ftype& operator()(int);

  ftype norm();
  Point unitVector();

  Point& operator+=(const Point&);
  Point& operator-=(const Point&);
  Point& operator*=(const ftype);
  Point& operator/=(const ftype);
};

Point operator+(const Point&, const Point&);
Point operator-(const Point&, const Point&);
Point operator*(const Point&, const ftype);
Point operator/(const Point&, const ftype);
Point operator*(const Matrix&, const Point&);

Point fromSpherical(ftype, ftype, ftype);

#endif
