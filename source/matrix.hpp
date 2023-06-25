#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <array>
#include <ostream>

#include "config.hpp"
#include "point.hpp"

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
  Matrix& operator*=(const Matrix&);  // Matrix product
  Matrix& operator*=(const ftype);    // Product with a scalar type

  ftype const& operator()(int, int) const;
  ftype& operator()(int, int);

  Matrix transposed() const;
};

Matrix operator+(const Matrix&, const Matrix&);
Matrix operator-(const Matrix&, const Matrix&);
Matrix operator*(const Matrix&, const Matrix&);
Matrix operator*(const Matrix&, const ftype);

std::ostream& operator<<(std::ostream&, const Matrix&);

Matrix rotationMatrix(const ftype, const Point&);

#endif
