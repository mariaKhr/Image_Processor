#include "read_bmp.h"
#include <fstream>
#include <ios>

uint16_t ReadUInt16(std::ifstream& input) {
    unsigned char buffer[2];
    input.read(reinterpret_cast<char*>(buffer), 2);
    return (static_cast<uint16_t>(buffer[0]) << 0u) + (static_cast<uint16_t>(buffer[1]) << 8u);
}

uint32_t ReadUInt32(std::ifstream& input) {
    unsigned char buffer[4];
    input.read(reinterpret_cast<char*>(buffer), 4);
    return (static_cast<uint32_t>(buffer[0]) << 0u) + (static_cast<uint32_t>(buffer[1]) << 8u) +
           (static_cast<uint32_t>(buffer[2]) << 16u) + (static_cast<uint32_t>(buffer[3]) << 24u);
}

Image ReadBMP(const std::string& path_file) {
    std::ifstream input(path_file, std::ios::binary);

    uint16_t bf_type = ReadUInt16(input);

    const uint16_t bm = 19778;
    if (bf_type != bm) {
        throw std::invalid_argument("Not a BMP file!");
    }

    uint32_t bf_size = ReadUInt32(input);
    input.ignore(4);
    uint32_t bf_off_bits = ReadUInt32(input);
    uint32_t bi_size = ReadUInt32(input);
    uint32_t bi_width = ReadUInt32(input);
    uint32_t bi_height = ReadUInt32(input);
    uint16_t bi_planes = ReadUInt16(input);
    uint16_t bi_bit_count = ReadUInt16(input);
    uint32_t bi_compression = ReadUInt32(input);
    uint32_t bi_size_image = ReadUInt32(input);
    input.ignore(16);

    if (bi_bit_count != 24 || bf_off_bits != 54 || bi_size != 40 || bf_size != 54 + bi_size_image ||
        bi_compression != 0 || bi_planes != 1 || bi_width < 1 || bi_height < 1) {
        throw std::invalid_argument("Invalid BMP file");
    }

    uint8_t padding = bi_width % 4;
    Image image = Image(bi_height, bi_width);

    for (uint32_t i = 0; i < bi_height; ++i) {
        for (uint32_t j = 0; j < bi_width; ++j) {

            uint8_t blue;
            uint8_t green;
            uint8_t red;

            input.read(reinterpret_cast<char*>(&blue), 1);
            input.read(reinterpret_cast<char*>(&green), 1);
            input.read(reinterpret_cast<char*>(&red), 1);

            image.At(i, j) = Pixel(red, green, blue);
        }
        input.ignore(padding);
    }
    return image;
}
