#include "shape.hpp"

namespace dt {
void Shape::setCenter(const Point& P) { center = P; }
void Shape::setOrientation(const Point& O) { orientation = O; }
void Shape::setColor(const RGB& color_) { color = color_; }
void Shape::setPoints(const int points_) { points = points_; }

void Shape::shift(const Point& P) { center += P; }
void Shape::rotate(const Point& O) { orientation += O; }

Point Shape::getCenter() const { return center; }
Point Shape::getOrientation() const { return orientation; }
int Shape::getPoints() const { return points; }
RGB Shape::getColor() const { return color; }
}  // namespace dt