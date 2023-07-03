#include "solid.hpp"

#include <cmath>

#include "config.hpp"
#include "matrix.hpp"
#include "shape.hpp"
#include "solid.hpp"

namespace dt {
  // using the contructor ": var(var_value) ..." generates an error (color not
  // defined), no idea why
  // maybe try later with Shape::variable_name
  Donut::Donut(ftype R_, ftype r_, int points_, RGB color_) {
    R = R_;
    r = r_;
    points = points_;
    color = color_;
  }

  ftype Donut::getR() const { return R; }
  ftype Donut::getr() const { return r; }

  void Donut::setR(const ftype R_) { R = R_; }
  void Donut::setr(const ftype r_) { r = r_; }

  std::vector<Point> Donut::computePoints() const {
    std::vector<Point> figure{};
    float Z = sqrt(points);
    for (int i = 0; i < Z; i++) {
      float alpha = 2 * M_PI * i / Z;
      for (int j = 0; j < Z; j++) {
        float beta = 2 * M_PI * j / Z;
        Point p((R + r * cos(alpha)) * cos(beta),
                (R + r * cos(alpha)) * sin(beta), r * sin(alpha));

        p = rotatedPoint(p, orientation(0), Point(1., 0., 0.));
        p = rotatedPoint(p, orientation(1), Point(0., 1., 0.));
        p = rotatedPoint(p, orientation(2), Point(0., 0., 1.));

        p += center;
        figure.push_back(p);
      }
    }
    return figure;
  }

  Ellipsoid::Ellipsoid(ftype A_, ftype B_, ftype C_, int points_, RGB color_) {
    A = A_;
    B = B_;
    C = C_;
    points = points_;
    color = color_;
  }

  ftype Ellipsoid::getA() const { return A; }
  ftype Ellipsoid::getB() const { return B; }
  ftype Ellipsoid::getC() const { return C; }

  void Ellipsoid::setA(const ftype A_) { A = A_; }
  void Ellipsoid::setB(const ftype B_) { B = B_; }
  void Ellipsoid::setC(const ftype C_) { C = C_; }

  std::vector<Point> Ellipsoid::computePoints() const {
    std::vector<Point> figure{};
    float Z = sqrt(points);
    for (int i = 0; i < Z; i++) {
      float alpha = M_PI * i / Z;
      for (int j = 0; j < Z; j++) {
        float beta = 2 * M_PI * j / Z;
        Point p(A * sin(alpha) * cos(beta), B * sin(alpha) * sin(beta),
                C * cos(alpha));

        p = rotatedPoint(p, orientation(0), Point(1., 0., 0.));
        p = rotatedPoint(p, orientation(1), Point(0., 1., 0.));
        p = rotatedPoint(p, orientation(2), Point(0., 0., 1.));

        p += center;
        figure.push_back(p);
      }
    }
    return figure;
  }

  Cylinder::Cylinder(ftype R_, ftype r_, ftype h_, int points_, RGB color_) {
    R = R_;
    r = r_;
    h = h_;
    points = points_;
    color = color_;
  }

  ftype Cylinder::getR() const { return R; }
  ftype Cylinder::getr() const { return r; }
  ftype Cylinder::geth() const { return h; }

  void Cylinder::setR(const ftype R_) { R = R_; };
  void Cylinder::setr(const ftype r_) { r = r_; };
  void Cylinder::seth(const ftype h_) { h = h_; };

  std::vector<Point> Cylinder::computePoints() const {
    std::vector<Point> figure{};
    for (int i = 0; i < points; i++) {
      float alpha = 2 * M_PI * i / points;
      for (int j = -points / 2; j < points / 2; j++) {
        float H = h * j / points;
        Point p(R * cos(alpha), R * sin(alpha), H);
        Point q(r * cos(alpha), r * sin(alpha), H);

        p = rotatedPoint(p, orientation(0), Point(1., 0., 0.));
        p = rotatedPoint(p, orientation(1), Point(0., 1., 0.));
        p = rotatedPoint(p, orientation(2), Point(0., 0., 1.));

        q = rotatedPoint(q, orientation(0), Point(1., 0., 0.));
        q = rotatedPoint(q, orientation(1), Point(0., 1., 0.));
        q = rotatedPoint(q, orientation(2), Point(0., 0., 1.));

        p += center;
        q += center;
        figure.push_back(p);
        figure.push_back(q);
      }
    }
    int facePoints = points / 2;
    for (int k = -facePoints; k < facePoints; k++) {
      for (int l = -facePoints; l < facePoints; l++) {
        ftype distance =
            sqrt(pow(R * l / facePoints, 2) + pow(R * k / facePoints, 2));
        if (distance > R || distance < r) {
          continue;
        }

        Point p(R * l / facePoints, R * k / facePoints, +h / 2);
        Point q(R * l / facePoints, R * k / facePoints, -h / 2);

        p = rotatedPoint(p, orientation(0), Point(1., 0., 0.));
        p = rotatedPoint(p, orientation(1), Point(0., 1., 0.));
        p = rotatedPoint(p, orientation(2), Point(0., 0., 1.));

        q = rotatedPoint(q, orientation(0), Point(1., 0., 0.));
        q = rotatedPoint(q, orientation(1), Point(0., 1., 0.));
        q = rotatedPoint(q, orientation(2), Point(0., 0., 1.));

        p += center;
        q += center;
        figure.push_back(p);
        figure.push_back(q);
      }
    }
    return figure;
  }
}
