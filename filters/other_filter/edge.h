#pragma once

#include "../matrix_filter/matrix_filter.h"
#include "../simple_filter/grayscale.h"

class Edge : public Filter {
public:
    Edge(float threshold);
    void Apply(Image& image) override;

private:
    float threshold_;
    Grayscale gs_;
    MatrixFilter matrix_f_;
};
