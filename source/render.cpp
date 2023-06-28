#include "render.hpp"

#include <cmath>
#include <limits>

#include "solid.hpp"

/*

steps:
1) project point onto plane
2) rotate by psi; still working on
3) rotate cam plane in order to make it parallel to xy plane; still working on
4) get x and y
5) scale
6) return index

*/

int projectPoint(const Camera& cam, const Point& P) {
  Point intersection = (P - cam.getPosition()) /
                       dot(P - cam.getPosition(), cam.getNormalVector());
  Point relativePosition = rotatedPoint(
      intersection, acos(dot(cam.getNormalVector(), Point(0., 0., 1.))),
      cross(cam.getNormalVector(), Point(0., 0., 1.)));

  // manage psi
  relativePosition =
      rotatedPoint(relativePosition, cam.getPsi(), Point(0., 0., 1.));

  ftype scaleFactor = cam.getPixelX() / (2. * tan(cam.getFov() / 2.));
  relativePosition *= scaleFactor;

  int x = round(relativePosition(0)) + cam.getPixelX() / 2;
  int y = round(relativePosition(1)) + cam.getPixelY() / 2;
  if (x >= 0 && x < cam.getPixelX() && y >= 0 && y < cam.getPixelY()) {
    return x + y * cam.getPixelX();
  } else {
    return -1;
  }
}

std::vector<RGB> render(const Camera& cam, const std::vector<Shape*>& obj,
                        RGB backgroundColor) {
  std::vector<RGB> image(cam.getPixelX() * cam.getPixelY(), backgroundColor);
  std::vector<ftype> distances(cam.getPixelX() * cam.getPixelY(),
                               std::numeric_limits<ftype>::max());
  for (const Shape* sprite : obj) {
    std::vector<Point> points = sprite->getPoints();
    for (const Point& P : points) {
      //  check if the point is in front of the camera, if not skip iteration
      if (std::signbit(dot(P - cam.getPosition(), cam.getNormalVector()))) {
        continue;
      }

      int projection = projectPoint(cam, P);
      if (projection == -1) {
        continue;
      }

      if ((P - cam.getPosition()).normSquared() < distances[projection]) {
        distances[projection] = (P - cam.getPosition()).normSquared();
        image[projection] = sprite->getColor();
      }
    }
  }
  return image;
}
