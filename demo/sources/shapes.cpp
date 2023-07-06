#include <SFML/Graphics/Image.hpp>
#include <cmath>
#include <memory>

#include "../../source/donutopia.hpp"

int main() {
  dt::Camera cam(dt::Point(-25., -25., 0.), M_PI_4, M_PI_4, 0., 1920, 1080,
                 120. / 360. * M_PI * 2);

  std::vector<std::shared_ptr<dt::Shape>> sprites;

  auto don = std::make_shared<dt::Donut>(6., 2., 100000, dt::RGB(0, 200, 0));
  don->setCenter(dt::Point(5., -5., 20.));
  don->rotate(dt::Point(0., 1., 0.));
  sprites.push_back(don);

  auto ell =
      std::make_shared<dt::Ellipsoid>(14., 8., 5., 100000, dt::RGB(0, 0, 200));
  ell->setCenter(dt::Point(0., 0., 60.));
  sprites.push_back(ell);

  auto cil =
      std::make_shared<dt::Cylinder>(15., 10., 12., 100000, dt::RGB(200, 0, 0));
  cil->setCenter(dt::Point(0., 30., 50.));
  cil->rotate(dt::Point(0, M_PI_2, M_PI_2));
  sprites.push_back(cil);

  auto res = render(cam, sprites, dt::RGB(128, 128, 128));

  // convert the output image in order to be usable for SFML
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
