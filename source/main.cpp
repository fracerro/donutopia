#include <cmath>
#include <fstream>
#include <iostream>

#include "camera.hpp"
#include "donut.hpp"
#include "render.hpp"

int main() {
  Camera cam(Point(-25., -25., 0.), M_PI_4, M_PI_4, 0., 1920, 1080, 120. / 360. * M_PI * 2);
  donut don(20., 5., 100, 100, RGB(139,0,139));
  donut don2(20., 5., 100, 100, RGB(200, 0, 0));
  don.set_cdm(Point(0., 30., 50.));
  don2.set_cdm(Point(0, 20, 60));
  don2.rotate(Point(M_PI_2, 0., 0.));
  //don.rotate(Point(1., 0.3, -0.8));

  std::vector<donut> sprites = {don, don2};

  auto res = render(cam, sprites, RGB(128, 128, 128));

  std::ofstream outFile("../visualize/data.txt");
  outFile << cam.getPixelX() << " " << cam.getPixelY() << "\n";
  for (auto x : res) {
    outFile << x.R << " " << x.G << " " << x.B << "\n";
  }
  outFile.close();

  return 0;
}