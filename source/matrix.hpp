#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <array>
#include <ostream>

using ftype = float;

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

  Matrix& transposed(); //returns the transposed matrix
};

std::ostream& operator<<(std::ostream&, const Matrix&);

#endif
