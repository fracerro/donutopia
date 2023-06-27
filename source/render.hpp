#ifndef RENDER_HPP
#define RENDER_HPP

#include <vector>

#include "camera.hpp"
#include "donut.hpp"

// remove after testing
int projectPoint(const Camera&, const Point&);

std::vector<RGB> render(const Camera&, const std::vector<donut>&, RGB);

#endif
