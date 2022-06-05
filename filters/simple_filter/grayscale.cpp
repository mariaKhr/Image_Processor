#include "grayscale.h"

void Grayscale::Apply(Image& image) {
    Image new_image(image.Height(), image.Width());
    for (uint32_t i = 0; i < image.Height(); ++i) {
        for (uint32_t j = 0; j < image.Width(); ++j) {
            unsigned char red = image.At(i, j).Red();
            unsigned char green = image.At(i, j).Green();
            unsigned char blue = image.At(i, j).Blue();
            unsigned char gray = red * 0.299 + green * 0.587 + blue * 0.114;
            new_image.At(i, j) = Pixel(gray, gray, gray);
        }
    }
    image = std::move(new_image);
}
