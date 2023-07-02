#include <SFML/Graphics/Image.hpp>
#include <cmath>

#include "../../source/donutopia.hpp"

class Cone : public Shape {
  ftype R{};
  ftype h{};
  Point CDM{};  // center of the base
  Point orientation{};
  int ALPHA_POINTS{};
  int BETA_POINTS{};
  RGB color{};

 public:
  Cone() = default;
  Cone(ftype R_, ftype h_, int alpha_, int beta_, RGB color_)
      : R(R_), h(h_), ALPHA_POINTS(alpha_), BETA_POINTS(beta_), color(color_) {}

  void shift(Point P) { CDM += P; }
  void set_cdm(Point P) { CDM = P; }
  void rotate(Point P) { orientation += P; }
  // TODO: fix getPoints()
  std::vector<Point> getPoints() const override {
    std::vector<Point> points{};
    for (int i = 0; i < ALPHA_POINTS; i++) {
      ftype z = h * i / ALPHA_POINTS;
      for (int j = 0; j < BETA_POINTS; j++) {
        ftype theta = M_PI * 2 * j / BETA_POINTS;
        ftype r = (1. - z / h) * R;
        Point p = (r * cos(theta), r * sin(theta), z);

        p = rotatedPoint(p, orientation(0), Point(1., 0., 0.));
        p = rotatedPoint(p, orientation(1), Point(0., 1., 0.));
        p = rotatedPoint(p, orientation(2), Point(0., 0., 1.));

        p += CDM;
        points.push_back(p);
      }
    }
    return points;
  }
  RGB getColor() const override { return color; }
};

int main() {
  Camera cam(Point(-25., -25., 0.), M_PI_4, M_PI_4, 0., 1920, 1080,
             120. / 360. * M_PI * 2);

  Cone cone(5., 15., 1000, 1000, RGB(255, 0, 0));
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