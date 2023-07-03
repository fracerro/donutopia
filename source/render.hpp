#ifndef RENDER_HPP
#define RENDER_HPP

#include <memory>
#include <vector>

#include "camera.hpp"
#include "shape.hpp"

std::vector<RGB> render(const Camera&,
                        const std::vector<std::shared_ptr<Shape>>&, RGB);

#endif
