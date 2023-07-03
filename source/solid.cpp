#include "solid.hpp"

#include <cmath>

#include "config.hpp"
#include "matrix.hpp"
#include "shape.hpp"
#include "solid.hpp"

// using the contructor ": var(var_value) ..." generates an error (color not
// defined), no idea why
// maybe try later with Shape::variable_name
Donut::Donut(ftype R_, ftype r_, int points_, RGB color_) {
  R = R_;
  r = r_;
  points = points_;
  color = color_;
}

void Donut::setR(ftype R_) { R = R_; }
void Donut::setr(ftype r_) { r = r_; }

std::vector<Point> Donut::getPoints() const {
  std::vector<Point> figure{};
  for (int i = 0; i < sqrt(points); i++) {
    float a = 2 * M_PI * i / sqrt(points);
    for (int j = 0; j < sqrt(points); j++) {
      float b = 2 * M_PI * j / sqrt(points);
      Point p((R + r * cos(a)) * cos(b), (R + r * cos(a)) * sin(b), r * sin(a));

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

std::vector<Point> Ellipsoid::getPoints() const {
  std::vector<Point> figure{};
  for (int i = 0; i < sqrt(points); i++) {
    float a = M_PI * i / sqrt(points);
    for (int j = 0; j < sqrt(points); j++) {
      float b = 2 * M_PI * j / sqrt(points);
      Point p(A * sin(a) * cos(b), B * sin(a) * sin(b), C * cos(a));

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

void Cylinder::setR(ftype R_) { R = R_; };
void Cylinder::setr(ftype r_) { r = r_; };
void Cylinder::seth(ftype h_) { h = h_; };

// TODO: adjust the total points numeber in order for it to be euqal to "points"
// variable
std::vector<Point> Cylinder::getPoints() const {
  std::vector<Point> figure{};
  float Z = sqrt(points);
  for (int i = 0; i < Z; i++) {
    float a = 2 * M_PI * i / Z;
    for (int j = -Z / 2; j < Z / 2; j++) {
      float b = h * j / Z;
      Point p(R * cos(a), R * sin(a), b);
      Point q(r * cos(a), r * sin(a), b);

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

  for (int k = -Z; k < Z; k++) {
    for (int l = -Z; l < Z; l++) {
      ftype distance = sqrt(pow(R * l / Z, 2) + pow(R * k / Z, 2));
      if (distance > R || distance < r) {
        continue;
      }

      Point p(R * l / Z, R * k / Z, +h / 2);
      Point q(R * l / Z, R * k / Z, -h / 2);

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
