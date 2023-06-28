#include <cmath>
#include <fstream>
#include <iostream>

#include "camera.hpp"
#include "donut.hpp"
#include "render.hpp"

int main() {
  Camera cam(Point(-25., -25., 0.), M_PI_4, M_PI_4, 0., 1920, 1080, 120. / 360. * M_PI * 2);
  donut don(20., 5., 1000, 1000, RGB(255, 160, 122));
  don.set_cdm(Point(0., 30., 50.));
  //don.rotate(Point(1., 0.3, -0.8));

  auto res = render(cam, std::vector<donut>(1, don), RGB(0, 0, 0));
  projectPoint(cam, Point(50., 50., 50.));

  std::ofstream outFile("../visualize/data.txt");
  outFile << cam.getPixelX() << " " << cam.getPixelY() << "\n";
  for (auto x : res) {
    outFile << x.R << " " << x.G << " " << x.B << "\n";
  }
  outFile.close();

  return 0;
}