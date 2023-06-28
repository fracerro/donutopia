#ifndef SOLID_HPP
#define SOLID_HPP

#include "shape.hpp"

class Donut : public Shape {
  ftype R{};
  ftype r{};  // r secondario, R principale
  int ALPHA_POINTS{};
  int BETA_POINTS{};
  Point CDM{}, orientation{};
  RGB color;

 public:
  Donut() = default;
  Donut(ftype R_, ftype r_, int alpha_, int beta_, RGB _color)
      : r(r_), R(R_), ALPHA_POINTS(alpha_), BETA_POINTS(beta_), color(_color) {}

  void shift(Point);
  void set_cdm(Point);
  void rotate(Point);
  std::vector<Point> getPoints() const override;
  RGB getColor() const override;
};

#endif