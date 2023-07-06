#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "../donutopia.hpp"
#include "doctest.h"

TEST_CASE("Testing projectPoint function") {
  dt::Camera cam(dt::Point(1., 2., -3.), M_PI_4, -M_PI_2 / 3., 0., 1920, 1080,
                 M_PI / 3.);

  SUBCASE("Testing point outside camera field") {
    int pos = dt::projectPoint(cam, dt::Point(5., -3., 10.));
    CHECK(pos == -1);
  }

  // TODO: check case psi != 0
  SUBCASE("Project point onto camera") {
    dt::Point P(5., -3., 1.);
    // calculations done by hand (real pain)
    CHECK(dt::projectPoint(cam, P) == 1510 + 868 * 1920);
    cam.setPsi(M_PI / 8.);
    CHECK(dt::projectPoint(cam, P) == 1343 + 1053 * 1920);
  }
}

TEST_CASE("Testing render function") {
  dt::Camera cam(dt::Point(1., 2., -3.), M_PI_4, -M_PI_2 / 3., 0., 1920, 1080,
                 M_PI / 3.);

  SUBCASE("Testing point behind camera") {
    // since we can't directly acces to the if statement
    // in the function, we will just copy-paste the
    // mathematical condition
    dt::Point P(-5, 3., -1.);  // P is behind the camera field
    CHECK(std::signbit(dot(P - cam.getPosition(), cam.getNormalVector())));
  }
}
