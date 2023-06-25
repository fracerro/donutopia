#include <iostream>
#include "matrix.hpp"

int main() {
    Matrix A(2.);
    Matrix B(3.);

    A *= B;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            A(i, j) = i * 3 + j;
        }
    }

    std::cout << A << "\n";
    A.transposed();
    std::cout << A << "\n";
    
    return 0;
}