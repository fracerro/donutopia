#include "render.hpp"

#include <cmath>
#include <limits>

/*

steps:
1) project point onto plane
2) calculated dir_x: default x-axis for camera
3) rotate the camera plane to be parallel to the xy plane, with cross
cross(dir_x, dir_y) = -k
4) rotate the point to get the default orientation dictated by
dir_x, and then rotate by the user chosen angle psi
5) scale the point with camera Fov
6) calculate x and y
7) check if the point is inside the screen, in
this case return the array position, otherwise -1

*/

namespace dt {
int projectPoint(const Camera& cam, const Point& P) {
  // lambda is the line parameter
  ftype lambda = 1. / dot(P - cam.getPosition(), cam.getNormalVector());
  // intersection between line and camera plane, the coordinates are expressed
  // considering the camera center as the origin
  Point intersection = (P - cam.getPosition()) * lambda - cam.getNormalVector();
  // default camera orientation
  Point dir_x(sin(cam.getPhi()), -cos(cam.getPhi()), 0.);
  // rotate the camera plane paraller to xy plane
  Point relativePosition = rotatedPoint(intersection, cam.getTheta(), dir_x);

  // angle between dir_x and the x unit vector
  // dot(dir_x, Point(1., 0., 0.)) == sin(cam.getPhi()), by the definition of
  // dir_x
  ftype angle = acos(sin(cam.getPhi()));
  if (std::signbit(cross(Point(1., 0., 0.), dir_x)(2))) {
    angle = -angle;  // get angle sign
  }
  // rotate by -angle and psi
  relativePosition =
      rotatedPoint(relativePosition, cam.getPsi() - angle, Point(0., 0., 1.));

  // scale the points
  ftype scaleFactor = cam.getPixelX() / (2. * tan(cam.getFov() / 2.));
  relativePosition *= scaleFactor;

  // approximate pixel coordinates
  int x = round(relativePosition(0)) + cam.getPixelX() / 2;
  int y = round(relativePosition(1)) + cam.getPixelY() / 2;
  // check if the pixel is inside the camera view
  if (x >= 0 && x < cam.getPixelX() && y >= 0 && y < cam.getPixelY()) {
    return x + y * cam.getPixelX();
  } else {
    return -1;
  }
}

std::vector<RGB> render(const Camera& cam,
                        const std::vector<std::shared_ptr<Shape>>& obj,
                        RGB backgroundColor) {
  std::vector<RGB> image(cam.getPixelX() * cam.getPixelY(), backgroundColor);
  std::vector<ftype> distances(cam.getPixelX() * cam.getPixelY(),
                               std::numeric_limits<ftype>::max());
  for (const auto& sprite : obj) {
    std::vector<Point> points = sprite->computePoints();
    for (const auto& P : points) {
      //  check if the point is in front of the camera, if not skip iteration
      if (std::signbit(dot(P - cam.getPosition(), cam.getNormalVector()))) {
        continue;
      }

      int projection = projectPoint(cam, P);
      if (projection == -1) {
        continue;
      }

      // check if the pixel position is already occupied by a closer object
      if ((P - cam.getPosition()).normSquared() < distances[projection]) {
        distances[projection] = (P - cam.getPosition()).normSquared();
        image[projection] = sprite->getColor();
      }
    }
  }
  return image;
}
}  // namespace dt