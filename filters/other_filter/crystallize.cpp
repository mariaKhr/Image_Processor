#include "crystallize.h"
#include <cmath>
#include <random>

Crystallize::Crystallize(size_t crystal_cnt) : crystal_cnt_(crystal_cnt) {
}

void Crystallize::Apply(Image &image) {
    std::vector<std::pair<size_t, size_t>> coord;
    coord.reserve(image.Height() * image.Width());
    for (size_t i = 0; i < image.Height(); ++i) {
        for (size_t j = 0; j < image.Width(); ++j) {
            coord.emplace_back(i, j);
        }
    }
    std::shuffle(coord.begin(), coord.end(), std::default_random_engine(0));
    coord.resize(crystal_cnt_);

    for (size_t i = 0; i < image.Height(); ++i) {
        for (size_t j = 0; j < image.Width(); ++j) {

            size_t min_dist = 0;
            size_t cur_dist = 0;
            size_t ind_min = 0;

            for (size_t k = 0; k < crystal_cnt_; ++k) {
                int dist_x = static_cast<int>(coord[k].first) - static_cast<int>(i);
                int dist_y = static_cast<int>(coord[k].second) - static_cast<int>(j);
                cur_dist = pow(dist_x, 2) + pow(dist_y, 2);
                if (cur_dist < min_dist || k == 0) {
                    min_dist = cur_dist;
                    ind_min = k;
                }
            }

            image.At(i, j) = image.At(coord[ind_min].first, coord[ind_min].second);
        }
    }
}
