#include <SFML/Graphics/Image.hpp>
#include <cmath>
#include <iostream>

#include "../../source/donutopia.hpp"

class Cone : public Shape {
  ftype R{};
  ftype h{};

 public:
  Cone() = default;
  Cone(ftype R_, ftype h_, int points_, RGB color_) {
    R = R_;
    h = h_;
    points = points_;
    color = color_;
  }

  void setR(ftype R_) { R = R_; }
  void seth(ftype h_) { h = h_; }

  // TODO: fix getPoints()
  std::vector<Point> getPoints() const override {
    std::vector<Point> figure{};
    ftype Z = sqrt(points);
    for (int i = 0; i < Z; i++) {
      ftype z = h * i / Z;
      for (int j = 0; j < Z; j++) {
        ftype theta = M_PI * 2 * j / Z;
        ftype r = (1. - z / h) * R;
        Point p = (r * cos(theta), r * sin(theta), z);

        p = rotatedPoint(p, orientation(0), Point(1., 0., 0.));
        p = rotatedPoint(p, orientation(1), Point(0., 1., 0.));
        p = rotatedPoint(p, orientation(2), Point(0., 0., 1.));

        p += center;
        figure.push_back(p);
      }
    }
    std::cout << figure.size() << std::endl;
    return figure;
  }
};

int main() {
  Camera cam(Point(10., 0., 0.), M_PI_2, -M_PI, 0., 1920, 1080,
             120. / 360. * M_PI * 2);

  Cone cone(5., 8., 1000000, RGB(255, 0, 0));
  std::vector<Shape*> sprites{};
  sprites.push_back(&cone);
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
  img.saveToFile("custom_shape.png");
}