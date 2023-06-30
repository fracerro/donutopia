#ifndef RENDER_HPP
#define RENDER_HPP

#include <vector>

#include "axis.hpp"
#include "camera.hpp"
#include "donut.hpp"

std::vector<RGB> render(const Camera&, const std::vector<donut>&, RGB);
std::vector<RGB> render(const Camera&, const std::vector<axis>&, RGB);

#endif
