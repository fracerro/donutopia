#ifndef POINT_HPP
#define POINT_HPP

#include <array>

#include "matrix.hpp"

class Point {
 private:
  std::array<ftype, 3> pt;

 public:
  Point() = default;
  Point(ftype, ftype, ftype);

  ftype const& operator()(int) const;
  ftype& operator()(int);

  ftype norm();

  Point toSpherical();  // from cartesian to spherical coordinates
  Point toCartesian();  // from spherical to cartesian coordinates
};

#endif
