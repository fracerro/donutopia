#include "shape.hpp"

#include "config.hpp"

void Shape::setCenter(const Point& P) { center = P; }
void Shape::setOrientation(const Point& O) { orientation = O; }
void Shape::setColor(const RGB& color_) { color = color_; }
void Shape::setPoints(int points_) { points = points_; }

void Shape::shift(const Point& P) { center += P; }
void Shape::rotate(const Point& O) { orientation += O; }

RGB Shape::getColor() const { return color; }
