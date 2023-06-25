#include "point.hpp"

#include <cmath>

Point::Point(ftype val) { pt.fill(val); }

Point::Point(ftype x, ftype y, ftype z) {
  pt[0] = x;
  pt[1] = y;
  pt[2] = z;
}

ftype const& Point::operator()(int i) const { return pt[i]; }

ftype& Point::operator()(int i) { return pt[i]; }

ftype Point::norm() {
  return sqrt(pt[0] * pt[0] + pt[1] * pt[1] + pt[2] * pt[2]);
}

Point Point::unitVector() { return (*this) / this->norm(); }

Point& Point::operator+=(const Point& P) {
  for (int i = 0; i < 3; i++) {
    pt[i] += P(i);
  }
  return *this;
}

Point& Point::operator-=(const Point& P) {
  for (int i = 0; i < 3; i++) {
    pt[i] -= P(i);
  }
  return *this;
}

Point& Point::operator*=(const ftype lambda) {
  for (int i = 0; i < 3; i++) {
    pt[i] *= lambda;
  }
  return *this;
}

Point& Point::operator/=(const ftype lambda) {
  for (int i = 0; i < 3; i++) {
    pt[i] /= lambda;
  }
  return *this;
}

Point operator+(const Point& P, const Point& Q) {
  Point R{P};
  R += Q;
  return R;
}

Point operator-(const Point& P, const Point& Q) {
  Point R{P};
  R -= Q;
  return R;
}

Point operator*(const Point& P, const ftype lambda) {
  Point R{P};
  R *= lambda;
  return R;
}

Point operator/(const Point& P, const ftype lambda) {
  Point R{P};
  R *= lambda;
  return R;
}

Point operator*(const Matrix& M, const Point& P) {
  Point Q(0.);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      Q(i) += M(i, j) * P(j);
    }
  }
  return Q;
}

// r ∈ [0, inf), phi ∈ [0, 2*pi), theta ∈ [0, pi)
Point fromSpherical(ftype r, ftype phi, ftype theta) {
  return Point(r * sin(theta) * cos(phi), r * sin(theta) * sin(phi),
               r * cos(theta));
}
