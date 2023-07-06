#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <vector>

#include "point.hpp"
#include "rgb.hpp"

namespace dt {
class Shape {
 protected:
  Point center{};       // point that determines the solid position
  Point orientation{};  // rotation of the solid around the 3 axis
  RGB color{};
  int points{};  // number of points computed to project the shape onto the
                 // camera

 public:
  void setCenter(const Point&);
  void setOrientation(const Point&);
  void setColor(const RGB&);
  void setPoints(const int);

  void shift(const Point&);
  void rotate(const Point&);

  Point getCenter() const;
  Point getOrientation() const;
  int getPoints() const;
  RGB getColor() const;

  virtual std::vector<Point> computePoints() const = 0;
};
}  // namespace dt

#endif
