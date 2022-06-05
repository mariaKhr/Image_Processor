#pragma once

#include "../filter.h"

class Crystallize : public Filter {
public:
    Crystallize(size_t crystal_cnt);
    void Apply(Image &image) override;

private:
    size_t crystal_cnt_;
};
