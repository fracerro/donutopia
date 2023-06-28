#ifndef RENDER_HPP
#define RENDER_HPP

#include <vector>

#include "camera.hpp"
#include "donut.hpp"

std::vector<RGB> render(const Camera&, const std::vector<donut>&, RGB);

#endif
