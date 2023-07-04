#include "../../source/donutopia.hpp"

#include <SFML/Graphics.hpp>
#include <filesystem>
#include <cmath>

/*
  WARNING: ffmpeg needs to be installed
*/

const std::string framesFolder = "frames";

void generateFrame(const dt::Camera& cam, const std::shared_ptr<dt::Donut>& don, int index) {
  auto res = dt::render(cam, std::vector<std::shared_ptr<dt::Shape>>(1, don), dt::RGB(10, 10, 10));
  std::vector<sf::Uint8> pixels;
  for (int i = 0; i < 1920 * 1080; i++) {
    pixels.push_back(res[i].R);
    pixels.push_back(res[i].G);
    pixels.push_back(res[i].B);
    pixels.push_back(255);
  }

  sf::Image img;
  img.create(1920, 1080, pixels.data());
  img.saveToFile((framesFolder + "/frame_" + std::to_string(index) + ".png").data());
}

int main() {
  // needs to be changed to std::filesysten::create_directories
  std::system(("mkdir -p " + framesFolder).data());

  dt::Camera cam(dt::Point(0., 0., 40.), M_PI, 0., 0., 1920, 1080, M_PI / 3.);
  auto don = std::make_shared<dt::Donut>(7., 2., 100000, dt::RGB(250, 128, 114));
  for (int i = 0; i < 120; i++) {
    generateFrame(cam, don, i);
    don->rotate(dt::Point(-0.02, 0.1, -0.07));
  }

  std::system(("ffmpeg -i " + framesFolder + "/frame_%d.png -r 30 spinning_donut.mp4").data());
}