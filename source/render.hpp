#ifndef RENDER_HPP
#define RENDER_HPP

#include <vector>

#include "camera.hpp"
#include "shape.hpp"

std::vector<RGB> render(const Camera&, const std::vector<Shape*>&, RGB);

#endif
