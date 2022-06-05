#include <cstdint>
#include "pixel.h"

Pixel::Pixel() : red_(0), green_(0), blue_(0) {
}

Pixel::Pixel(uint8_t red, uint8_t green, uint8_t blue) : red_(red), green_(green), blue_(blue) {
}

uint8_t Pixel::Red() const {
    return red_;
}

uint8_t Pixel::Green() const {
    return green_;
}

uint8_t Pixel::Blue() const {
    return blue_;
}
