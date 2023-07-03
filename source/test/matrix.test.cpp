#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "../matrix.hpp"

#include "doctest.h"

TEST_CASE("Testing the matrix class") {
  dt::Matrix A(4.);  // This tests if the ftype filler constructor works
  dt::Matrix A_{A};

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      REQUIRE(A(i, j) ==
              4.);  // This also tests if A(int,int) behaves as it should
    }
  }

  dt::Matrix B(3.);
  dt::Matrix B_{B};

  dt::Matrix C{};

  SUBCASE("Testing + / += operator") {
    C = A + B;
    A += B;
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        CHECK(A(i, j) == 7.);
        CHECK(C(i, j) == 7.);
      }
    }
  }

  SUBCASE("Testing - / -= operator") {
    C = A - B;
    A -= B;
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        CHECK(A(i, j) == 1.);
        CHECK(C(i, j) == 1.);
      }
    }
  }

  SUBCASE(
      "Testing * / *= operator in each overload (matrix product and scalar "
      "product)") {
    C = A * B;
    A *= B;
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        CHECK(A(i, j) == 36.);
        CHECK(C(i, j) == 36.);
      }
    }
    dt::ftype lambda = 0.5;
    C = C * lambda;
    A *= lambda;
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        CHECK(A(i, j) == 18.);
        CHECK(C(i, j) == 18.);
      }
    }
  }

  SUBCASE("Testing the transposed function") {
    A(0, 1) = 8.;
    A(0, 2) = 9.;
    A(1, 2) = 10.;
    A = A.transposed();
    CHECK(A(0, 1) == 4.);
    CHECK(A(0, 2) == 4.);
    CHECK(A(1, 2) == 4.);
    CHECK(A(1, 0) == 8.);
    CHECK(A(2, 0) == 9.);
    CHECK(A(2, 1) == 10.);
  }

  SUBCASE("Testing rotationMatrix function") {
    dt::Matrix M = dt::rotationMatrix(M_PI / 6., dt::Point(1., -2., 3.));
    CHECK(M(0, 0) == doctest::Approx(0.8755950));
    CHECK(M(0, 1) == doctest::Approx(-0.4200311));
    CHECK(M(0, 2) == doctest::Approx(-0.2385524));
    CHECK(M(1, 0) == doctest::Approx(0.3817526));
    CHECK(M(1, 1) == doctest::Approx(0.9043038));
    CHECK(M(1, 2) == doctest::Approx(-0.1910483));
    CHECK(M(2, 0) == doctest::Approx(0.2959701));
    CHECK(M(2, 1) == doctest::Approx(0.0762129));
    CHECK(M(2, 2) == doctest::Approx(0.9521520));
  }

  SUBCASE("Testing * / *= operator between Matrix and Point") {
    dt::Matrix M{};
    M(0, 0) = 0.3;
    M(0, 1) = 0.2;
    M(0, 2) = -0.1;
    M(1, 0) = 0.4;
    M(1, 1) = -0.7;
    M(1, 2) = 3.3;
    M(2, 0) = 2.3;
    M(2, 1) = -0.9;
    M(2, 2) = 1.1;
    dt::Point P(4.5, -2.3, 1.9);
    P = M * P;

    CHECK(P(0) == doctest::Approx(0.7));
    CHECK(P(1) == doctest::Approx(9.68));
    CHECK(P(2) == doctest::Approx(14.51));
  }
}