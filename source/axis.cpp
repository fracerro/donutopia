#include "axis.hpp"

#include <cmath>

#include "config.hpp"
#include "matrix.hpp"

void axis::rotate(Point P) { orientation += P; }

std::vector<Point> axis::getPoints() const {
  std::vector<Point> points{};
  for (int i = 0; i < ALPHA_POINTS; i++) {
    float a = i;
    Point p(a, 0., 0.);
    
    p = rotatedPoint(p, orientation(0), Point(1., 0., 0.));
    p = rotatedPoint(p, orientation(1), Point(0., 1., 0.));
    p = rotatedPoint(p, orientation(2), Point(0., 0., 1.));
  
    points.push_back(p);
  }
  return points;
}

RGB axis::getColor() const { return color; }