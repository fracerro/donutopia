#include <iostream>
#include "matrix.hpp"

int main() {
    Matrix A(2.);
    Matrix B(3.);

    A *= B;
    std::cout << A << "\n";
    return 0;
}