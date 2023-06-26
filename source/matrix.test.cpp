#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "matrix.hpp"

#include "doctest.h"

TEST_CASE("Testing the matrix class") { //manca rotationMatrix
  Matrix A(4.);  // This tests if the ftype filler constructor works
  Matrix A_{A};
  
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      REQUIRE(A(i, j) ==
              4.);  // This also tests if A(int,int) behaves as it should
    }
  }

  Matrix B(3.);
  Matrix B_{B};

  Matrix C{};

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
    ftype lambda = 0.5;
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
}