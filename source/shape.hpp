#ifndef SHAPE_HPP
#define SHAPE_HPP
#include <vector>
#include "config.hpp"
#include "matrix.hpp"
#include "point.hpp"
#include "rgb.hpp"
class Shape {
public:
    virtual std::vector<Point> getPoints() const = 0;
    virtual RGB getColor() const = 0;
};

#endif


