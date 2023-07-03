#ifndef RENDER_HPP
#define RENDER_HPP

#include <memory>
#include <vector>

#include "camera.hpp"
#include "shape.hpp"

namespace dt {
    std::vector<RGB> render(const Camera&,
                            const std::vector<std::shared_ptr<Shape>>&, RGB);
    // maybe remove projectPoint from hpp
    int projectPoint(const Camera&, const Point&);
}

#endif
