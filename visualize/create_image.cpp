#include <SFML/Graphics.hpp>
#include <fstream>
#include <vector>

int main() {
  int pixel_x;
  int pixel_y;
  std::vector<sf::Uint8> pixels;

  std::ifstream inputFile("data.txt");
  inputFile >> pixel_x >> pixel_y;
  for (int i = 0; i < pixel_x * pixel_y; i++) {
    int r, g, b;
    inputFile >> r >> g >> b;
    pixels.push_back(r);
    pixels.push_back(g);
    pixels.push_back(b);
    pixels.push_back(255);
  }
  inputFile.close();

  sf::Image img;
  img.create(pixel_x, pixel_y, pixels.data());
  img.saveToFile("image.png");
}