#pragma once

#include "matrix_filter.h"

class Blur : public MatrixFilter {
public:
    Blur(float sigma);
};
