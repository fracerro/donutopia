#ifndef CAMERA_HPP
#define CAMERA_HPP

#include "config.hpp"
#include "matrix.hpp"

class Camera {
 private:
  Point position{};

  ftype phi{};
  ftype theta{};
  ftype psi{};

  int pixelX{};
  int pixelY{};
  ftype fov{};  // filed of view over X axis

  Point normalVector;

 public:
  Camera() = default;
  Camera(const Point&, ftype, ftype, ftype, int, int, ftype);

  int getPixelX() const;
  int getPixelY() const;
  ftype getFov() const;
  ftype getPsi() const;
  Point getNormalVector() const;
  Point getPosition() const;
};

#endif
