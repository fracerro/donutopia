#include "matrix.hpp"

#include <cmath>

Matrix::Matrix(ftype val) {
  for (int i = 0; i < 3; i++) {
    mat[i].fill(val);
  }
}

// Operators

Matrix& Matrix::operator+=(const Matrix& B) {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      mat[i][j] += B.mat[i][j];
    }
  }
  return *this;
}

Matrix& Matrix::operator-=(const Matrix& B) {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      mat[i][j] -= B.mat[i][j];
    }
  }
  return *this;
}

Matrix& Matrix::operator*=(const Matrix& B) {
  std::array<std::array<ftype, 3>, 3> tmp{};
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      tmp[i][j] = 0.;
      for (int k = 0; k < 3; k++) {
        tmp[i][j] += mat[i][k] * B.mat[k][j];
      }
    }
  }
  mat = tmp;
  return *this;
}

Matrix& Matrix::operator*=(const ftype lambda) {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      mat[i][j] *= lambda;
    }
  }
  return *this;
}

Matrix& Matrix::operator/=(const ftype lambda) {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      mat[i][j] /= lambda;
    }
  }
  return *this;
}

Matrix operator+(const Matrix& A, const Matrix& B) {
  Matrix C{A};
  C += B;
  return C;
}

Matrix operator-(const Matrix& A, const Matrix& B) {
  Matrix C{A};
  C -= B;
  return C;
}

Matrix operator*(const Matrix& A, const Matrix& B) {
  Matrix C{A};
  C *= B;
  return C;
}

Matrix operator*(const Matrix& A, const ftype lambda) {
  Matrix C{A};
  C *= lambda;
  return C;
}

Matrix operator/(const Matrix& A, const ftype lambda) {
  Matrix C{A};
  C /= lambda;
  return C;
}

Matrix Matrix::transposed() const {
  Matrix tr{};
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      tr(j, i) = mat[i][j];
    }
  }
  return tr;
}

ftype const& Matrix::operator()(int i, int j) const { return mat[i][j]; }

ftype& Matrix::operator()(int i, int j) { return mat[i][j]; }

std::ostream& operator<<(std::ostream& os, const Matrix& P) {
  for (int i = 0; i < 3; i++) {
    os << "[";
    for (int j = 0; j < 3; j++) {
      os << P(i, j);
      if (j != 2) {
        os << ", ";
      }
    }
    os << "]" << '\n';
  }
  os << '\n';
  return os;
}

// da riscrivere in maniera pulita
Matrix rotationMatrix(const ftype theta, const Point& v) {
  // rewrite later
  if (v.normSquared() == 0.) {
    Matrix identity{0};
    for (int i = 0; i < 3; i++) {
      identity(i, i) = 1.;
    }
    return identity;
  }

  auto u = v.unitVector();
  Matrix rmatrix{};
  auto X = u(0);
  auto Y = u(1);
  auto Z = u(2);
  rmatrix(0, 0) = X * X + (1 - X * X) * cos(theta);
  rmatrix(0, 1) = X * Y * (1 - cos(theta)) - Z * sin(theta);
  rmatrix(0, 2) = X * Z * (1 - cos(theta)) + Y * sin(theta);
  rmatrix(1, 0) = X * Y * (1 - cos(theta)) + Z * sin(theta);
  rmatrix(1, 1) = Y * Y + (1 - Y * Y) * cos(theta);
  rmatrix(1, 2) = Y * Z * (1 - cos(theta)) - X * sin(theta);
  rmatrix(2, 0) = X * Z * (1 - cos(theta)) - Y * sin(theta);
  rmatrix(2, 1) = Y * Z * (1 - cos(theta)) + X * sin(theta);
  rmatrix(2, 2) = Z * Z + (1 - Z * Z) * cos(theta);
  return rmatrix;
}
