#pragma once

class Pixel {
public:
    Pixel();
    Pixel(uint8_t red, uint8_t green, uint8_t blue);
    uint8_t Red() const;
    uint8_t Green() const;
    uint8_t Blue() const;

private:
    uint8_t red_;
    uint8_t green_;
    uint8_t blue_;
};
