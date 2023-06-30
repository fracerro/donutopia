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

ftype Point::norm() const {
  return sqrt(pt[0] * pt[0] + pt[1] * pt[1] + pt[2] * pt[2]);
}

ftype Point::normSquared() const {
  return pt[0] * pt[0] + pt[1] * pt[1] + pt[2] * pt[2];
}

Point Point::unitVector() const { return (*this) / this->norm(); }

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
  R /= lambda;
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

bool operator==(const Point& P, const Point& Q) {
  if (P(0) == Q(0) && P(1) == Q(1) && P(2) == Q(2)) {
    return true;
  }
  return false;
}

// r ∈ [0, inf), theta ∈ [0, pi), phi ∈ [0, 2*pi)
Point fromSpherical(ftype r, ftype theta, ftype phi) {
  return Point(r * sin(theta) * cos(phi), r * sin(theta) * sin(phi),
               r * cos(theta));
}

ftype dot(const Point& P, const Point& Q) {
  return P(0) * Q(0) + P(1) * Q(1) + P(2) * Q(2);
}

Point cross(const Point& P, const Point& Q) {
  Point R{};
  R(0) = P(1) * Q(2) - P(2) * Q(1);
  R(1) = P(2) * Q(0) - P(0) * Q(2);
  R(2) = P(0) * Q(1) - P(1) * Q(0);
  return R;
}

#include <iostream>
Point rotatedPoint(const Point& P, const ftype theta, const Point& v) {
  return rotationMatrix(theta, v) * P;
}

std::ostream& operator<<(std::ostream& os, const Point& P) {
  os << "(" << P(0) << ", " << P(1) << ", " << P(2) << ")";
  return os;
}
