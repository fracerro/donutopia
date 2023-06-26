#ifndef POINT_HPP
#define POINT_HPP

#include <array>

#include "config.hpp"
#include "matrix.hpp"

class Matrix;

class Point {
 private:
  std::array<ftype, 3> pt;

 public:
  Point() = default;
  Point(ftype);
  Point(ftype, ftype, ftype);

  ftype const& operator()(int) const;
  ftype& operator()(int);

  ftype norm() const;
  Point unitVector() const;

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

ftype dot(const Point&, const Point&);
Point cross(const Point&, const Point&);

#endif
