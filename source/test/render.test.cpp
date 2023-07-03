#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "../render.hpp"

#include "doctest.h"

int projectPoint(const Camera&, const Point&);

TEST_CASE("Testing projectPoint function") {
  Camera cam(Point(1., 2., -3.), M_PI_4, -M_PI_2 / 3., 0., 1920, 1080,
             M_PI / 3.);

  SUBCASE("Testing point outside camera field") {
    int pos = projectPoint(cam, Point(5., -3., 10.));
    CHECK(pos == -1);
  }

  // TODO: check case psi != 0
  SUBCASE("Project point onto camera") {
    Point P(5., -3., 1.);
    // calculations done by hand (real pain)
    CHECK(projectPoint(cam, P) == 1510 + 868 * 1920);
  }
}

TEST_CASE("Testing render function") {
  Camera cam(Point(1., 2., -3.), M_PI_4, -M_PI_2 / 3., 0., 1920, 1080,
             M_PI / 3.);

  SUBCASE("Testing point behind camera") {
    // since we can't directly acces to the if statement
    // in the function, we will just copy-paste the
    // mathematical condition
    Point P(-5, 3., -1.);  // P is behind the camera field
    CHECK(std::signbit(dot(P - cam.getPosition(), cam.getNormalVector())));
  }
}
