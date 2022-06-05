#pragma once

#include "../filter.h"
#include <stdint.h>

class Crop : public Filter {
public:
    Crop(uint32_t height, uint32_t width);
    void Apply(Image& image) override;

private:
    uint32_t height_;
    uint32_t width_;
};