#ifndef SOLID_HPP
#define SOLID_HPP

#include "shape.hpp"

namespace dt {
  class Donut : public Shape {
    ftype R{}; //main radius (distance from shape center)
    ftype r{}; //internal thickness radius

  public:
    Donut() = default;
    Donut(ftype, ftype, int, RGB);

    ftype getR() const;
    ftype getr() const;

    void setR(const ftype);
    void setr(const ftype);

    std::vector<Point> computePoints() const override;
  };

  class Ellipsoid : public Shape {
    ftype A{};  // x semi-axis
    ftype B{};  // y semi-axis
    ftype C{};  // z semi-exis

  public:
    Ellipsoid() = default;
    Ellipsoid(ftype, ftype, ftype, int, RGB);

    ftype getA() const;
    ftype getB() const;
    ftype getC() const;

    void setA(const ftype);
    void setB(const ftype);
    void setC(const ftype);

    std::vector<Point> computePoints() const override;
  };

  class Cylinder : public Shape {
    ftype R{}; //greater radius
    ftype r{}; //minor radius
    ftype h{}; //height

  public:
    Cylinder() = default;
    Cylinder(ftype, ftype, ftype, int, RGB);

    ftype getR() const;
    ftype getr() const;
    ftype geth() const;

    void setR(const ftype);
    void setr(const ftype);
    void seth(const ftype);

    std::vector<Point> computePoints() const override;
  };
}

#endif