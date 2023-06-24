#include <iostream>
#include "matrix.hpp"

int main() {
    Matrix A(2.);
    Matrix B(3.);

    A *= B;

    A(0,1) = 9.;
    A(0,2) = 3.;
    A(1,2) = 6.;

    std::cout << A.transposed() <<'\n';
    return 0;
}