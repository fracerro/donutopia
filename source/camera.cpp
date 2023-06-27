#include "camera.hpp"

#include <stdexcept>
#include <string>

const int maxPixel = 4096;

Camera::Camera(const Point& _position, ftype _phi, ftype _theta, ftype _psi,
               int _pixelX, int _pixelY, ftype _fov)
    : position(_position),
      phi(_phi),
      theta(_theta),
      psi(_psi),
      pixelX(_pixelX),
      pixelY(_pixelY),
      fov(_fov) {
  if (pixelX <= 0 || pixelY <= 0) {
    throw std::runtime_error("Pixel number must be positive.");
  }

  std::string error_msg =
      "Pixel number must be at most " + std::to_string(maxPixel) + ".";
  if (pixelX >= maxPixel || pixelY >= maxPixel) {
    throw std::runtime_error(error_msg.c_str());
  }

  normalVector = fromSpherical(1., phi, theta);
}

const int Camera::getPixelX() const { return pixelX; }
const int Camera::getPixelY() const { return pixelY; }
const ftype Camera::getFov() const { return fov; }
const Point& Camera::getNormalVector() const { return normalVector; }
const Point& Camera::getPosition() const { return position; }
