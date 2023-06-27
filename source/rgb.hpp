#ifndef RGB_HPP
#define RGB_HPP

// eventually control that R, G and B must be in range [0, 255]
struct RGB {
  int R{};
  int G{};
  int B{};

  RGB() = default;
  RGB(int, int, int);
};

#endif
