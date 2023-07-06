#ifndef CAMERA_HPP
#define CAMERA_HPP

#include "point.hpp"

namespace dt {
class Camera {
 private:
  Point position{};  // camera position

  ftype phi{};       // polar angle
  ftype theta{};     // azimuthal angle
  ftype psi{};   // rotation of camera field of view with respect to the default
                 // orientation

  int pixelX{};  // number of pixels on the horizontal edge
  int pixelY{};  // number of pixels on the vertical edge
  ftype fov{};   // filed of view over X axis

 public:
  Camera() = default;
  Camera(const Point&, ftype, ftype, ftype, int, int, ftype);

  int getPixelX() const;
  int getPixelY() const;
  ftype getFov() const;
  ftype getPsi() const;
  ftype getPhi() const;
  ftype getTheta() const;
  Point getPosition() const;

  void setPixelX(const int);
  void setPixelY(const int);
  void setFov(const ftype);
  void setPsi(const ftype);
  void setTheta(const ftype);
  void setPhi(const ftype);
  void setPosition(const Point&);

  Point getNormalVector() const;
};
}  // namespace dt

#endif
