#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <array>
#include <ostream>

#include "config.hpp"
#include "point.hpp"

namespace dt {
class Point;

// 3 x 3
class Matrix {
 private:
  std::array<std::array<ftype, 3>, 3> mat{};

 public:
  Matrix() = default;
  Matrix(ftype);

  Matrix& operator+=(const Matrix&);  // matrix sum
  Matrix& operator-=(const Matrix&);  // matrix difference
  Matrix& operator*=(const Matrix&);  // matrix rows columns product
  Matrix& operator*=(const ftype);    // matrix and scalar product
  Matrix& operator/=(const ftype);    // matrix and scalar division

  ftype const& operator()(int, int) const;
  ftype& operator()(int, int);

  Matrix transposed() const;
};

Matrix operator+(const Matrix&, const Matrix&);
Matrix operator-(const Matrix&, const Matrix&);
Matrix operator*(const Matrix&, const Matrix&);
Matrix operator*(const Matrix&, const ftype);
Matrix operator/(const Matrix&, const ftype);

std::ostream& operator<<(std::ostream&, const Matrix&);  // ostream for a matrix

Matrix rotationMatrix(
    ftype,
    const Point&);  // given theta and a x,y,z vector, returns the rotation by
                    // theta matrix along the normalized vector
}  // namespace dt

#endif
