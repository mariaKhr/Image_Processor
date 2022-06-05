#include "negative.h"

void Negative::Apply(Image& image) {
    Image new_image(image.Height(), image.Width());
    for (uint32_t i = 0; i < image.Height(); ++i) {
        for (uint32_t j = 0; j < image.Width(); ++j) {
            unsigned char red = 255 - image.At(i, j).Red();
            unsigned char green = 255 - image.At(i, j).Green();
            unsigned char blue = 255 - image.At(i, j).Blue();
            new_image.At(i, j) = Pixel(red, green, blue);
        }
    }
    image = std::move(new_image);
}