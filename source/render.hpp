#ifndef RENDER_HPP
#define RENDER_HPP

#include <vector>

#include "camera.hpp"
#include "donut.hpp"
#include "axis.hpp"

std::vector<RGB> render(const Camera&, const std::vector<donut>&, RGB);
std::vector<RGB> render(const Camera&, const std::vector<axis>&, RGB);

#endif
