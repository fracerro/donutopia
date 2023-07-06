#include <SFML/Graphics.hpp>
#include <cmath>
#include <filesystem>
#include <iostream>

#include "../../source/donutopia.hpp"

// WARNING: ffmpeg needs to be installed

const std::string framesFolder = "frames";

void generateFrame(const dt::Camera& cam, const std::shared_ptr<dt::Donut>& don,
                   int index) {
  auto res = dt::render(cam, std::vector<std::shared_ptr<dt::Shape>>(1, don),
                        dt::RGB(10, 10, 10));
  std::vector<sf::Uint8> pixels;
  for (int i = 0; i < 1920 * 1080; i++) {
    pixels.push_back(res[i].R);
    pixels.push_back(res[i].G);
    pixels.push_back(res[i].B);
    pixels.push_back(255);
  }

  sf::Image img;
  img.create(1920, 1080, pixels.data());
  img.saveToFile(
      (framesFolder + "/frame_" + std::to_string(index) + ".png").data());
}

int main() {
  std::filesystem::create_directory(framesFolder);

  dt::Camera cam(dt::Point(5., 12., 60.), M_PI, 0., 0., 1920, 1080, M_PI / 3.);
  int framesNumber = 100;
  int fps = 20;

  auto don =
      std::make_shared<dt::Donut>(7., 2., 100000, dt::RGB(250, 128, 114));

  for (int i = 0; i < framesNumber; i++) {
    generateFrame(cam, don, i);
    std::cout << "Generated frame " << i + 1 << " out of " << framesNumber
              << "\n";
    don->rotate(dt::Point(-0.02, 0.1, -0.07));
    don->shift(dt::Point(cos(2 * M_PI * i / framesNumber),
                         sin(2 * M_PI * i / framesNumber), -0.3));
  }

  std::system(("ffmpeg -i " + framesFolder + "/frame_%d.png -r " +
               std::to_string(fps) + " spinning_donut.mp4")
                  .data());
}