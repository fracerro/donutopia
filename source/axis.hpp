#ifndef AXIS_HPP
#define AXIS_HPP

#include <vector>

#include "config.hpp"
#include "matrix.hpp"
#include "rgb.hpp"

class axis {
  int ALPHA_POINTS{};
  Point orientation{};
  RGB color;

 public:
  axis() = default;
  axis(int alpha_, RGB _color) : ALPHA_POINTS(alpha_), color(_color) {}

  void rotate(Point);
  std::vector<Point> getPoints() const;
  RGB getColor() const;
};

#endif