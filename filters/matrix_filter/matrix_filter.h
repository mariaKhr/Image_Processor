#pragma once

#include "../../matrix/matrix.h"
#include "../filter.h"

class MatrixFilter : public Filter {
public:
    MatrixFilter() = default;
    MatrixFilter(const std::vector<Matrix<float>>& convolutions);
    void Apply(Image& image) override;
    void AddMatrix(const Matrix<float>& new_convolution);

private:
    std::vector<Matrix<float>> convolutions_;
};
