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

  axis axisX(10000., RGB(255, 0, 0));
  axis axisY(10000., RGB(0, 255, 0));
  axis axisZ(10000., RGB(0, 0, 255));

  axisY.rotate(Point(0., 0., M_PI_2));
  axisZ.rotate(Point(0., 3 * M_PI / 2, 0.));

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