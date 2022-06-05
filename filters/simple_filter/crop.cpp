#include "crop.h"

Crop::Crop(uint32_t height, uint32_t width) : height_(height), width_(width) {
}

void Crop::Apply(Image& image) {
    size_t new_height = std::min(static_cast<size_t>(height_), image.Height());
    size_t new_width = std::min(static_cast<size_t>(width_), image.Width());

    if (new_height != image.Height() || new_width != image.Width()) {
        Image new_image(new_height, new_width);
        for (uint32_t i = 0; i < new_height; ++i) {
            for (uint32_t j = 0; j < new_width; ++j) {
                new_image.At(i, j) = image.At(i + image.Height() - new_height, j);
            }
        }
        image = std::move(new_image);
    }
}
