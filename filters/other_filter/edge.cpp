#include "edge.h"

Edge::Edge(float threshold) : threshold_(threshold), matrix_f_({Matrix<float>({{0, -1, 0}, {-1, 4, -1}, {0, -1, 0}})}) {
}

void Edge::Apply(Image &image) {
    gs_.Apply(image);
    matrix_f_.Apply(image);

    for (uint32_t i = 0; i < image.Height(); ++i) {
        for (uint32_t j = 0; j < image.Width(); ++j) {
            if (static_cast<float>(image.At(i, j).Red()) / 255 > threshold_) {
                image.At(i, j) = Pixel(255, 255, 255);
            } else {
                image.At(i, j) = Pixel(0, 0, 0);
            }
        }
    }
}
