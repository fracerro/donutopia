#ifndef SOLID_HPP
#define SOLID_HPP

#include "shape.hpp"

class Donut : public Shape {
  // r secondario, R principale
  ftype R{};
  ftype r{};

 public:
  Donut() = default;
  Donut(ftype, ftype, int, RGB);

  void setR(ftype);
  void setr(ftype);

  std::vector<Point> getPoints() const override;
};

class Ellipsoid : public Shape {
  ftype A{};  // x semi-axis
  ftype B{};  // y semi-axis
  ftype C{};  // z semi-exis

 public:
  Ellipsoid() = default;
  Ellipsoid(ftype, ftype, ftype, int, RGB);

  void setA(ftype);
  void setB(ftype);
  void setC(ftype);

  std::vector<Point> getPoints() const override;
};

class Cylinder : public Shape {
  ftype R{};
  ftype r{};
  ftype h{};

 public:
  Cylinder() = default;
  Cylinder(ftype, ftype, ftype, int, RGB);

  void setR(ftype);
  void setr(ftype);
  void seth(ftype);

  std::vector<Point> getPoints() const override;
};

#endif