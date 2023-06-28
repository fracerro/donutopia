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

  const int getPixelX() const;
  const int getPixelY() const;
  const ftype getFov() const;
  const ftype getPsi() const;
  const Point& getNormalVector() const;
  const Point& getPosition() const;
};

#endif