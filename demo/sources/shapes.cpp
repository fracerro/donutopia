#include <SFML/Graphics/Image.hpp>
#include <cmath>

#include "../../source/donutopia.hpp"

int main() {
  Camera cam(Point(-25., -25., 0.), M_PI_4, M_PI_4, 0., 1920, 1080,
             120. / 360. * M_PI * 2);

  Cylinder cil1(15., 10., 12., 200, RGB(200, 0, 0));
  cil1.setCenter(Point(0., 30., 50.));
  cil1.rotate(Point(0, M_PI_2, M_PI_2));
  std::vector<Shape*> sprites{};
  sprites.push_back(&cil1);
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
