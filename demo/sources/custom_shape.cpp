#include <SFML/Graphics/Image.hpp>
#include <cmath>
#include <iostream>
#include <memory>

#include "../../source/donutopia.hpp"

class Cone : public dt::Shape {
  dt::ftype R{};
  dt::ftype h{};

 public:
  Cone() = default;
  Cone(dt::ftype R_, dt::ftype h_, int points_, dt::RGB color_) {
    R = R_;
    h = h_;
    points = points_;
    color = color_;
  }

  void setR(dt::ftype R_) { R = R_; }
  void seth(dt::ftype h_) { h = h_; }

  dt::ftype getR() { return R; }
  dt::ftype geth() { return h; }

  std::vector<dt::Point> computePoints() const override {
    std::vector<dt::Point> figure{};
    float Z = sqrt(points);
    for (int i = 0; i < Z; i++) {
      float a = 2 * M_PI * i / Z;
      for (int j = -Z / 2; j < Z / 2; j++) {
        float b = h * j / Z;
        dt::ftype r = R * (j - (Z / 2)) / Z;
        dt::Point p(r * cos(a), r * sin(a), b);

        p = rotatedPoint(p, orientation(0), dt::Point(1., 0., 0.));
        p = rotatedPoint(p, orientation(1), dt::Point(0., 1., 0.));
        p = rotatedPoint(p, orientation(2), dt::Point(0., 0., 1.));

        p += center;
        figure.push_back(p);
      }
    }
    return figure;
  }
};

int main() {
  dt::Camera cam(dt::Point(20., 0., 0.), M_PI_2, -M_PI, 0., 1920, 1080,
             60. / 360. * M_PI * 2);

  auto cone = std::make_shared<Cone>(3., 5., 100000, dt::RGB(200, 200, 0));
  cone->setCenter(dt::Point(0., 0., -0.5));
  std::vector<std::shared_ptr<dt::Shape>> sprites{};
  sprites.push_back(cone);
  auto res = render(cam, sprites, dt::RGB(128, 128, 128));

  std::vector<sf::Uint8> pixels;
  for (int i = 0; i < 1920 * 1080; i++) {
    pixels.push_back(res[i].R);
    pixels.push_back(res[i].G);
    pixels.push_back(res[i].B);
    pixels.push_back(255);
  }

  sf::Image img;
  img.create(1920, 1080, pixels.data());
  img.saveToFile("custom_shape.png");
}
