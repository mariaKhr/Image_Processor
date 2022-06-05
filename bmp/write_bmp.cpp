#include "write_bmp.h"
#include <fstream>

void WriteUInt16(std::ofstream& output, uint16_t num) {
    char buffer[2];
    buffer[0] = num >> 0u % 256;
    buffer[1] = num >> 8u % 256;
    output.write(buffer, 2);
}

void WriteUInt32(std::ofstream& output, uint32_t num) {
    char buffer[4];
    buffer[0] = num >> 0u % 256;
    buffer[1] = num >> 8u % 256;
    buffer[2] = num >> 16u % 256;
    buffer[3] = num >> 24u % 256;
    output.write(buffer, 4);
}

void WriteBMP(const std::string& output_path, const Image& image) {
    std::ofstream output(output_path, std::ios::binary);

    uint32_t bi_width = image.Width();
    uint32_t bi_height = image.Height();
    uint8_t padding = bi_width % 4;
    uint32_t bi_size_image = (bi_width + padding) * bi_height * 3;
    uint32_t bf_size = 54 + bi_size_image;

    const uint16_t bm = 19778;
    uint16_t bf_type = bm;
    uint16_t bf_reserved_1 = 0;
    uint16_t bf_reserved_2 = 0;
    uint32_t bf_off_bits = 54;
    uint32_t bi_size = 40;
    uint16_t bi_planes = 1;
    uint16_t bi_bit_count = 24;
    uint32_t bi_compression = 0;
    uint32_t bi_x_pix_per_metre = 11811;
    uint32_t bi_y_pix_per_metre = 11811;
    uint32_t bi_number_clr = 0;
    uint32_t bi_clr_important = 0;

    WriteUInt16(output, bf_type);
    WriteUInt32(output, bf_size);
    WriteUInt16(output, bf_reserved_1);
    WriteUInt16(output, bf_reserved_2);
    WriteUInt32(output, bf_off_bits);
    WriteUInt32(output, bi_size);
    WriteUInt32(output, bi_width);
    WriteUInt32(output, bi_height);
    WriteUInt16(output, bi_planes);
    WriteUInt16(output, bi_bit_count);
    WriteUInt32(output, bi_compression);
    WriteUInt32(output, bi_size_image);
    WriteUInt32(output, bi_x_pix_per_metre);
    WriteUInt32(output, bi_y_pix_per_metre);
    WriteUInt32(output, bi_number_clr);
    WriteUInt32(output, bi_clr_important);

    for (uint32_t i = 0; i < bi_height; ++i) {
        for (uint32_t j = 0; j < bi_width; ++j) {
            char blue = static_cast<char>(image.At(i, j).Blue());
            char green = static_cast<char>(image.At(i, j).Green());
            char red = static_cast<char>(image.At(i, j).Red());

            output.write(&blue, 1);
            output.write(&green, 1);
            output.write(&red, 1);
        }

        for (uint8_t j = 0; j < padding; ++j) {
            char zero = 0;
            output.write(&zero, 1);
        }
    }
}
