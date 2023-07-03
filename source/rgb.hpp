#ifndef RGB_HPP
#define RGB_HPP

namespace dt {
  struct RGB {
    int R{};
    int G{};
    int B{};

    RGB() = default;
    RGB(int, int, int);
  };
}

#endif
