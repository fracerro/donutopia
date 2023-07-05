#ifndef RGB_HPP
#define RGB_HPP
#include <cstdint>

namespace dt {
struct RGB {
  std::int8_t R{};
  std::int8_t G{};
  std::int8_t B{};

  RGB() = default;
  RGB(std::int8_t, std::int8_t, std::int8_t);
};
}  // namespace dt

#endif
