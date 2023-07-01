#ifndef POINT_HPP
#define POINT_HPP

#include <array>
#include <ostream>

#include "config.hpp"
#include "matrix.hpp"

class Matrix;

class Point {  // x,y,z vector
 private:
  std::array<ftype, 3> pt;

 public:
  Point() = default;
  Point(ftype);                // Fills the vector with the ftype value
  Point(ftype, ftype, ftype);  // Basic x,y,z constructor

  ftype const& operator()(int) const;
  ftype& operator()(int);

  ftype norm() const;         // returns the norm of the vector
  ftype normSquared() const;  // returns the square of norm
  Point unitVector() const;   // Normalizes the vector

  Point& operator+=(const Point&);  // vector sum
  Point& operator-=(const Point&);  // vector difference
  Point& operator*=(const ftype);   // scalar product
  Point& operator/=(const ftype);   // scalar division
};

Point operator+(const Point&, const Point&);
Point operator-(const Point&, const Point&);
Point operator*(const Point&, const ftype);
Point operator/(const Point&, const ftype);
Point operator*(const Matrix&,
                const Point&);  // Product for a matrix and a vector
bool operator==(const Point&, const Point&);  // operator to compare vectors

Point fromSpherical(
    ftype, ftype,
    ftype);  // given radius, angle from x axis (on x,y plane), angle from z
             // axis returns the x,y,z coordinates vector
Point sphericalUnitVector(ftype, ftype, ftype);
ftype dot(const Point&, const Point&);  // dot product (returns an ftype value)
Point cross(const Point&,
            const Point&);  // cross product (returns a Point vector)

Point rotatedPoint(const Point&, ftype,
                   const Point&);  // given the point P, theta angle and the
                                   // vector v, rotates P around v by theta

std::ostream& operator<<(std::ostream&, const Point&);  // output for a point

#endif
