#include <cmath>
#include <fstream>
#include <iostream>

#include "axis.hpp"
#include "camera.hpp"
#include "donut.hpp"
#include "render.hpp"

ftype toRadians(ftype angle) { return angle / 360. * M_PI * 2.; }

int main() {
  Camera cam(1 * Point(-30., -30., -15.), toRadians(50.), M_PI_4, toRadians(0.),
             1920, 1080, toRadians(60.));
  // Camera cam(Point(100., 100., 0.), M_PI_2, 5 * M_PI_4, 0., 1920, 1080,
  // 130. / 360. * M_PI * 2);

  // donut don(20., 5., 100, 100, RGB(139,0,139));
  // donut don2(20., 5., 100, 100, RGB(200, 0, 0));

  axis axisX(10000., RGB(255, 0, 0));
  axis axisY(10000., RGB(0, 255, 0));
  axis axisZ(10000., RGB(0, 0, 255));

  axisY.rotate(Point(0., 0., M_PI_2));
  axisZ.rotate(Point(0., 3 * M_PI / 2, 0.));

  // don.set_cdm(Point(0., 30., 50.));
  // don2.set_cdm(Point(0, 20, 60));
  // don2.rotate(Point(M_PI_2, 0., 0.));
  // don.rotate(Point(1., 0.3, -0.8));

  std::vector<axis> sprites = {axisX, axisY, axisZ};

  auto res = render(cam, sprites, RGB(128, 128, 128));

  std::ofstream outFile("../visualize/data.txt");
  outFile << cam.getPixelX() << " " << cam.getPixelY() << "\n";
  for (auto x : res) {
    outFile << x.R << " " << x.G << " " << x.B << "\n";
  }
  outFile.close();

  return 0;
}