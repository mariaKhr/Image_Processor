#include "blur.h"
#include <cmath>

Blur::Blur(float sigma) {
    const float sigma_2 = pow(sigma, 2);
    const float coef = 1 / sqrt(2 * M_PI * sigma_2);
    const int radius = static_cast<int>(3 * sigma);

    std::vector<float> row;
    row.reserve(radius * 2 + 1);
    for (int i = -radius; i <= radius; ++i) {
        row.push_back(coef * exp(-abs(i) / (2 * sigma_2)));
    }

    Matrix<float> horizontal_conv = Matrix<float>({row});
    Matrix<float> vertical_conv = horizontal_conv.Transposed();

    AddMatrix(std::move(horizontal_conv));
    AddMatrix(std::move(vertical_conv));
}
