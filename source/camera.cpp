#include "camera.hpp"

#include <stdexcept>
#include <string>

namespace dt {
  Camera::Camera(const Point& _position, ftype _theta, ftype _phi, ftype _psi,
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
  }

  int Camera::getPixelX() const { return pixelX; }
  int Camera::getPixelY() const { return pixelY; }
  ftype Camera::getFov() const { return fov; }
  ftype Camera::getPsi() const { return psi; }
  ftype Camera::getTheta() const { return theta; }
  ftype Camera::getPhi() const { return phi; }
  Point Camera::getNormalVector() const { return fromSpherical(1., theta, phi); }
  Point Camera::getPosition() const { return position; }

  void Camera::setPixelX(const int pixelX_) { pixelX = pixelX_; }
  void Camera::setPixelY(const int pixelY_) { pixelY = pixelY_; }
  void Camera::setFov(const ftype fov_) { fov = fov_; }
  void Camera::setPsi(const ftype psi_) { psi = psi_; }
  void Camera::setTheta(const ftype theta_) { theta = theta_; }
  void Camera::setPhi(const ftype phi_) { phi = phi_; }
  void Camera::setPosition(const Point& position_) { position = position_; }
}
