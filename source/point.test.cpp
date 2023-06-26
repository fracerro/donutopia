#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"
#include "matrix.hpp"

TEST_CASE("Testing the matrix class") { //manca fromSpherical e rotated_Point
  Point a(1.);
  Point b(1., 2., 3.);
  Point c{b};
  ftype lambda = 2;

  CHECK((c == b) == true);
  CHECK((c == a) == false);

  SUBCASE("Testing + / += operator") {
    c = a + b;
    a += b;
    CHECK(a(0) == 2);
    CHECK(a(1) == 3);
    CHECK(a(2) == 4);
    CHECK(c == a);
  }
  SUBCASE("Testing - / -= operator") {
    c = a - b;
    a -= b;
    CHECK(a(0) == 0);
    CHECK(a(1) == -1);
    CHECK(a(2) == -2);
    CHECK(c == a);
  }
  SUBCASE("Testing * / *= operator") {
    c = b * lambda;
    b *= lambda;
    CHECK(b(0) == 2);
    CHECK(b(1) == 4);
    CHECK(b(2) == 6);
    CHECK(c == b);
  }
  SUBCASE("Testing / / /= operator") {
    c = b / lambda;
    b /= lambda;
    CHECK(b(0) == 0.5);
    CHECK(b(1) == 1);
    CHECK(b(2) == 1.5);
    CHECK(c == b);
  }
  SUBCASE("Testing norm, norm_squared and unitVector functions") {
    lambda = b.norm();
    CHECK(lambda == doctest::Approx(3.74165738677));
    lambda = b.norm_squared();
    CHECK(lambda == 14);
    c = b.unitVector();
    CHECK(c(0) == doctest::Approx(0.26726124191));
    CHECK(c(1) == doctest::Approx(0.53452248382));
    CHECK(c(2) == doctest::Approx(0.80178372573));
  }
  SUBCASE("Testing dot and cross products functions") {
    lambda = dot(a,b);
    CHECK(lambda == 6);
    c = cross(a,b);
    CHECK(c(0) == 1);
    CHECK(c(1) == -2);
    CHECK(c(2) == 1);
    c = cross(b,a);
    CHECK(c(0) == -1);
    CHECK(c(1) == 2);
    CHECK(c(2) == -1);
  }
}