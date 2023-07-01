#include <cmath>
#include <fstream>
#include <iostream>
#include <memory>

#include "camera.hpp"
#include "render.hpp"
#include "shape.hpp"
#include "solid.hpp"

int main() {
  Camera cam(Point(-25., -25., 0.), M_PI_4, M_PI_4, 0., 1920, 1080,
             120. / 360. * M_PI * 2);
  Donut don(20., 5., 100, 100, RGB(139, 0, 139));
  Donut don2(20., 5., 100, 100, RGB(200, 0, 0));
  don.set_cdm(Point(0., 30., 50.));
  don2.set_cdm(Point(0, 20, 60));
  don2.rotate(Point(M_PI_2, 0., 0.));
  // don.rotate(Point(1., 0.3, -0.8));
  Ellipsoid elly1(8., 9., 10., 1000, 1000, RGB(0, 255, 0));
  elly1.set_cdm(Point(5., 7., 11.));
  elly1.rotate(Point(0., M_PI_2, 0.));
  std::vector<Shape*> sprites{};
  sprites.push_back(&don);
  sprites.push_back(&don2);
  sprites.push_back(&elly1);
  auto res = render(cam, sprites, RGB(128, 128, 128));

  std::ofstream outFile("../visualize/data.txt");
  outFile << cam.getPixelX() << " " << cam.getPixelY() << "\n";
  for (auto x : res) {
    outFile << x.R << " " << x.G << " " << x.B << "\n";
  }
  outFile.close();

  return 0;
}