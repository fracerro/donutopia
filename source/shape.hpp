#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <vector>

#include "config.hpp"
#include "matrix.hpp"
#include "point.hpp"
#include "rgb.hpp"

class Shape {
 protected:
  Point center{};       // point that determines the solid position
  Point orientation{};  // rotation of the solid around the axis
  RGB color{};
  int points{};  // number of points computed to project the shape into the
                 // camera

 public:
  void setCenter(const Point&);
  void setOrientation(const Point&);
  void setColor(const RGB&);
  void setPoints(int);

  void shift(const Point&);
  void rotate(const Point&);

  RGB getColor() const;

  virtual std::vector<Point> getPoints() const = 0;
};

#endif
