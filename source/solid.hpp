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

class Ellipsoid : public Shape {
  ftype A{};  // primo semiasse
  ftype B{};  // secondo semiasse
  ftype C{};  // terzo semiasse
  int ALPHA_POINTS{};
  int BETA_POINTS{};
  Point CDM{}, orientation{};
  RGB color;

 public:
  Ellipsoid() = default;
  Ellipsoid(ftype A_, ftype B_, ftype C_, int alpha_, int beta_, RGB _color)
      : A(A_), B(B_), ALPHA_POINTS(alpha_), BETA_POINTS(beta_), color(_color) {}
  void shift(Point);
  void set_cdm(Point);
  void rotate(Point);
  std::vector<Point> getPoints() const override;
  RGB getColor() const override;
};

class Cylinder : public Shape {
  ftype R{};
  ftype h{};
  int ALPHA_POINTS{};
  Point CDM{}, orientation{};
  RGB color;

  public:
  Cylinder()= default;
  Cylinder(ftype R_, ftype h_, int alpha_, RGB _color)
  : R(R_), h(h_), ALPHA_POINTS(alpha_), color(_color) {}
   void shift(Point);
  void set_cdm(Point);
  void rotate(Point);
  std::vector<Point> getPoints() const override;
  RGB getColor() const override;
};
  
#endif