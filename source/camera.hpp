#ifndef CAMERA_HPP
#define CAMERA_HPP

#include "config.hpp"
#include "matrix.hpp"

namespace dt {
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
    ftype getPhi() const;
    ftype getTheta() const;
    Point getNormalVector() const;
    Point getPosition() const;

    void setPixelX(const int);
    void setPixelY(const int);
    void setFov(const ftype);
    void setPsi(const ftype);
    void setTheta(const ftype);
    void setPhi(const ftype);
    void setPosition(const Point&);
  };
}

#endif
