#include "matrix.hpp"

Matrix::Matrix(ftype val) {
  for (int i = 0; i < 3; i++) {
    mat[i].fill(val);
  }
}

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

Matrix& Matrix::transposed() {
  ftype tmp;
  for (int i = 0; i < 3; i++) {
    for (int j = i; j < 3; j++) {
      tmp = mat[i][j];
      mat[i][j] = mat[j][i]; 
      mat[j][i] = tmp;
    }
  }
  return *this;
}

ftype const& Matrix::operator()(int i, int j) const {
  return mat[i][j]; 
}

ftype& Matrix::operator()(int i, int j) {
  return mat[i][j];
}


std::ostream& operator<<(std::ostream& os, const Matrix& P) {
  for (int i = 0; i < 3; i++) {
    os << "[";
    for (int j = 0; j < 3; j++) {
      os << P(i,j);
      if (j != 2) {
        os << ", ";
      }
    }
    os << "]" <<'\n';
  }
  os <<'\n';
  return os;
}
