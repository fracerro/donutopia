#include "donut.hpp"

#include <cmath>

#include "config.hpp"
#include "matrix.hpp"

void donut::shift(Point P) { CDM += P; }

void donut::set_cdm(Point P) { CDM = P; }

void donut::rotate(Point P) { orientation += P; }

std::vector<Point> donut::getPoints() const {
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

RGB donut::getColor() const { return color; }
