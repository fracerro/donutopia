#include <SFML/Graphics/Image.hpp>
#include <cmath>

#include "../../source/donutopia.hpp"

int main() {
  Camera cam(Point(-25., -25., 0.), M_PI_4, M_PI_4, 0., 1920, 1080,
             120. / 360. * M_PI * 2);

  Donut don(6., 2., 100000, RGB(0, 200, 0));
  don.setCenter(Point(5., -5., 20.));
  don.rotate(Point(0., 1., 0.));

  Ellipsoid ell(14., 8., 5., 100000, RGB(0, 0, 200));
  ell.setCenter(Point(0., 0., 60.));

  Cylinder cil(15., 10., 12., 10000, RGB(200, 0, 0));
  cil.setCenter(Point(0., 30., 50.));
  cil.rotate(Point(0, M_PI_2, M_PI_2));
  
  std::vector<Shape*> sprites = {&don, &ell, &cil};
  auto res = render(cam, sprites, RGB(128, 128, 128));

  std::vector<sf::Uint8> pixels;
  for (int i = 0; i < 1920 * 1080; i++) {
    pixels.push_back(res[i].R);
    pixels.push_back(res[i].G);
    pixels.push_back(res[i].B);
    pixels.push_back(255);
  }

  sf::Image img;
  img.create(1920, 1080, pixels.data());
  img.saveToFile("shapes.png");
}
