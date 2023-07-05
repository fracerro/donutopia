#ifndef RGB_HPP
#define RGB_HPP
#include <cstdint>

namespace dt {
struct RGB {
  std::uint8_t R{};
  std::uint8_t G{};
  std::uint8_t B{};

  RGB() = default;
  RGB(std::uint8_t, std::uint8_t, std::uint8_t);
};
}  // namespace dt

#endif
