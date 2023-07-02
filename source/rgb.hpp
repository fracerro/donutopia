#ifndef RGB_HPP
#define RGB_HPP

#include <cstdint>

struct RGB {
  uint8_t R{};
  uint8_t G{};
  uint8_t B{};

  RGB() = default;
  RGB(uint8_t, uint8_t, uint8_t);
};

#endif
