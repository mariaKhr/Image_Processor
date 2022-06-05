#include "matrix_filter.h"

MatrixFilter::MatrixFilter(const std::vector<Matrix<float>>& convolutions) : convolutions_(convolutions) {
}

void MatrixFilter::Apply(Image& image) {
    for (const Matrix<float>& conv : convolutions_) {

        Image new_image(image.Height(), image.Width());

        float div = conv.CoefSum();
        int vertical_radius = (conv.Height() - 1) / 2;
        int horizontal_radius = (conv.Width() - 1) / 2;

        for (uint32_t i = 0; i < image.Height(); ++i) {
            for (uint32_t j = 0; j < image.Width(); ++j) {

                float cur_red = 0;
                float cur_green = 0;
                float cur_blue = 0;

                for (int k = static_cast<int>(i) - vertical_radius; k <= static_cast<int>(i) + vertical_radius; ++k) {
                    for (int l = static_cast<int>(j) - horizontal_radius; l <= static_cast<int>(j) + horizontal_radius;
                         ++l) {

                        int row = std::clamp(k, 0, static_cast<int>(image.Height()) - 1);
                        int column = std::clamp(l, 0, static_cast<int>(image.Width()) - 1);

                        int matrix_row = k - static_cast<int>(i) + vertical_radius;
                        int matrix_col = l - static_cast<int>(j) + horizontal_radius;

                        cur_red += image.At(row, column).Red() * conv.At(matrix_row, matrix_col);
                        cur_green += image.At(row, column).Green() * conv.At(matrix_row, matrix_col);
                        cur_blue += image.At(row, column).Blue() * conv.At(matrix_row, matrix_col);
                    }
                }

                if (div != 0) {
                    cur_red /= div;
                    cur_green /= div;
                    cur_blue /= div;
                }

                unsigned char new_red = std::min(255, std::max(0, static_cast<int>(cur_red)));
                unsigned char new_green = std::min(255, std::max(0, static_cast<int>(cur_green)));
                unsigned char new_blue = std::min(255, std::max(0, static_cast<int>(cur_blue)));

                new_image.At(i, j) = Pixel(new_red, new_green, new_blue);
            }
        }
        image = std::move(new_image);
    }
}

void MatrixFilter::AddMatrix(const Matrix<float>& new_convolution) {
    convolutions_.push_back(new_convolution);
}
