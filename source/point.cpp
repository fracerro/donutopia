#include "point.hpp"

#include <cmath>

Point::Point(ftype x, ftype y, ftype z) {
  pt[0] = x;
  pt[1] = y;
  pt[2] = z;
}

ftype const& Point::operator()(int i) const { return pt[i]; }

ftype& Point::operator()(int i) { return pt[i]; }

ftype Point::norm() {
  return sqrt(pt[0] * pt[0] + pt[1] * pt[1] + pt[2] * pt[2]);
}

Point Point::toSpherical() {
  Point pl{*this};
  pl(0) = this->norm();
  // TODO
  return pl;
}

Point Point::toCartesian() {
  Point ct{*this};
  ct(0) = pt[0] * sin(this->pt[1]) * cos(pt[2]);
  ct(1) = pt[0] * sin(this->pt[1]) * sin(pt[2]);
  ct(2) = pt[0] * cos(this->pt[1]);
  return ct;
}
