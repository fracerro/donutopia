#include "solid.hpp"

#include <cmath>

#include "config.hpp"
#include "matrix.hpp"
#include "shape.hpp"

void Donut::shift(Point P) { CDM += P; }

void Donut::set_cdm(Point P) { CDM = P; }

void Donut::rotate(Point P) { orientation += P; }

std::vector<Point> Donut::getPoints() const {
  std::vector<Point> points{};
  for (int i = 0; i < ALPHA_POINTS; i++) {
    float a = 2 * M_PI * i / ALPHA_POINTS;
    for (int j = 0; j < BETA_POINTS; j++) {
      float b = 2 * M_PI * j / BETA_POINTS;
      Point p((R + r * cos(a)) * cos(b), (R + r * cos(a)) * sin(b), r * sin(a));

      p = rotatedPoint(p, orientation(0), Point(1., 0., 0.));
      p = rotatedPoint(p, orientation(1), Point(0., 1., 0.));
      p = rotatedPoint(p, orientation(2), Point(0., 0., 1.));

      p += CDM;
      points.push_back(p);
    }
  }
  return points;
}

RGB Donut::getColor() const { return color; }

void Ellipsoid::shift(Point P) { CDM += P; }

void Ellipsoid::set_cdm(Point P) { CDM = P; }

void Ellipsoid::rotate(Point P) { orientation += P; }

std::vector<Point> Ellipsoid::getPoints() const {
  std::vector<Point> points{};
  for (int i = 0; i < ALPHA_POINTS; i++) {
    float a = M_PI * i / ALPHA_POINTS;
    for (int j = 0; j < BETA_POINTS; j++) {
      float b = 2 * M_PI * j / BETA_POINTS;
      Point p(A * sin(a) * cos(b), B * sin(a) * sin(b), C * cos(a));

      p = rotatedPoint(p, orientation(0), Point(1., 0., 0.));
      p = rotatedPoint(p, orientation(1), Point(0., 1., 0.));
      p = rotatedPoint(p, orientation(2), Point(0., 0., 1.));

      p += CDM;
      points.push_back(p);
    }
  }
  return points;
}
RGB Ellipsoid::getColor() const { return color; }

void Cylinder::shift(Point P) { CDM += P; }

void Cylinder::set_cdm(Point P) { CDM = P; }

void Cylinder::rotate(Point P) { orientation += P; }

std::vector<Point> Cylinder::getPoints() const {
  std::vector<Point> points{};

  for (int i = 0; i < ALPHA_POINTS; i++) {
    float a = 2 * M_PI * i / ALPHA_POINTS;
    for (int j = -BETA_POINTS / 2; j < BETA_POINTS / 2; j++) {
      float b = h * j / BETA_POINTS;
      Point p(R * cos(a), R * sin(a), b);
      Point q(r * cos(a), r * sin(a), b);

      p = rotatedPoint(p, orientation(0), Point(1., 0., 0.));
      p = rotatedPoint(p, orientation(1), Point(0., 1., 0.));
      p = rotatedPoint(p, orientation(2), Point(0., 0., 1.));

      q = rotatedPoint(q, orientation(0), Point(1., 0., 0.));
      q = rotatedPoint(q, orientation(1), Point(0., 1., 0.));
      q = rotatedPoint(q, orientation(2), Point(0., 0., 1.));

      p += CDM;
      q += CDM;
      points.push_back(p);
      points.push_back(q);
    }
  }
  ftype GAMMA_POINTS = sqrt(ALPHA_POINTS * BETA_POINTS);
  for (int k = -GAMMA_POINTS; k < GAMMA_POINTS; k++) {
    for (int l = -GAMMA_POINTS; l < GAMMA_POINTS; l++) {
      ftype distance =
          sqrt(pow(R * l / GAMMA_POINTS, 2) + pow(R * k / GAMMA_POINTS, 2));
      if (distance > R || distance < r) {
        continue;
      }

      Point p(R * l / GAMMA_POINTS, R * k / GAMMA_POINTS, +h / 2);
      Point q(R * l / GAMMA_POINTS, R * k / GAMMA_POINTS, -h / 2);

      p = rotatedPoint(p, orientation(0), Point(1., 0., 0.));
      p = rotatedPoint(p, orientation(1), Point(0., 1., 0.));
      p = rotatedPoint(p, orientation(2), Point(0., 0., 1.));

      q = rotatedPoint(q, orientation(0), Point(1., 0., 0.));
      q = rotatedPoint(q, orientation(1), Point(0., 1., 0.));
      q = rotatedPoint(q, orientation(2), Point(0., 0., 1.));

      p += CDM;
      q += CDM;
      points.push_back(p);
      points.push_back(q);
    }
  }
  return points;
}
RGB Cylinder::getColor() const { return color; }
