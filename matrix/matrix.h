#pragma once

#include <stdexcept>
#include <vector>

template <typename T>
class Matrix {
public:
    Matrix() : height_(0), width_(0){};

    Matrix(size_t height, size_t width) {
        if (height == 0 || width == 0) {
            height_ = 0;
            width_ = 0;

        } else {
            height_ = height;
            width_ = width;
            std::vector<T> row(width);
            matrix_.assign(height, row);
        }
    }

    Matrix(const std::vector<std::vector<T>>& input_matrix) {
        if (input_matrix.empty()) {
            height_ = 0;
            width_ = 0;

        } else {
            size_t cur_size = input_matrix[0].size();
            for (const auto& row : input_matrix) {
                if (row.size() != cur_size) {
                    throw std::invalid_argument("Invalid matrix");
                }
            }
            if (cur_size == 0) {
                height_ = 0;
                width_ = 0;
            } else {
                matrix_ = input_matrix;
                height_ = input_matrix.size();
                width_ = cur_size;
            }
        }
    }

    size_t Height() const {
        return height_;
    }

    size_t Width() const {
        return width_;
    }

    T& At(size_t row, size_t col) {
        if (row >= height_ || col >= width_) {
            throw std::out_of_range("index out of range");
        }
        return matrix_[row][col];
    }

    T At(size_t row, size_t col) const {
        if (row >= height_ || col >= width_) {
            throw std::out_of_range("index out of range");
        }
        return matrix_[row][col];
    }

    Matrix<T> Transposed() const {
        std::vector<T> row(height_);
        std::vector<std::vector<T>> new_matrix(width_, row);
        for (size_t i = 0; i < width_; ++i) {
            for (size_t j = 0; j < height_; ++j) {
                new_matrix[i][j] = matrix_[j][i];
            }
        }
        return Matrix<T>(new_matrix);
    }

    T CoefSum() const {
        T sum = 0;
        for (size_t i = 0; i < height_; ++i) {
            for (size_t j = 0; j < width_; ++j) {
                sum += matrix_[i][j];
            }
        }
        return sum;
    }

private:
    std::vector<std::vector<T>> matrix_;
    size_t height_;
    size_t width_;
};
