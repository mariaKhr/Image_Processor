#include <catch.hpp>

#include "../bmp/read_bmp.h"
#include "../bmp/write_bmp.h"

namespace {
bool ImagesAreEqual(const Image& image1, const Image& image2) {
    if (image1.Width() != image2.Width() || image1.Height() != image2.Height()) {
        return false;
    }
    for (size_t i = 0; i < image1.Height(); ++i) {
        for (size_t j = 0; j < image1.Width(); ++j) {
            if (image1.At(i, j).Red() != image2.At(i, j).Red() || image1.At(i, j).Green() != image2.At(i, j).Green() ||
                image1.At(i, j).Blue() != image2.At(i, j).Blue()) {
                return false;
            }
        }
    }
    return true;
}
}  // namespace

TEST_CASE("WritingAndReading") {
    const Image image({{Pixel(0, 10, 20), Pixel(30, 40, 50), Pixel(60, 70, 80)},
                       {Pixel(90, 100, 110), Pixel(120, 130, 140), Pixel(150, 160, 170)},
                       {Pixel(180, 190, 200), Pixel(210, 220, 230), Pixel(240, 250, 0)}});
    std::string path = "output.bmp";
    WriteBMP(path, image);
    Image new_image = ReadBMP(path);
    REQUIRE(ImagesAreEqual(image, new_image));
}