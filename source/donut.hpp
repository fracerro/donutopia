#ifndef DONUT_HPP
#define DONUT_HPP

#include <vector>

#include "config.hpp"
#include "matrix.hpp"

class donut {
  ftype R{};
  ftype r{};  // r secondario, R principale
  int ALPHA_POINTS{};
  int BETA_POINTS{};
  Point CDM{}, orientation{};

 public:
  donut() = default;
  donut(ftype R_, ftype r_, int alpha_, int beta_)
      : r(r_), R(R_), ALPHA_POINTS(alpha_), BETA_POINTS(beta_) {}

  void shift(Point);
  void set_cdm(Point);
  void rotate(Point);
  std::vector<Point> get_points() const;
};

#endif
