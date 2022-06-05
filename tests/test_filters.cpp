#include <catch.hpp>

#include "../image/image.h"
#include "../filters/matrix_filter/blur.h"
#include "../filters/matrix_filter/sharpening.h"
#include "../filters/other_filter/edge.h"
#include "../filters/simple_filter/crop.h"
#include "../filters/simple_filter/grayscale.h"
#include "../filters/simple_filter/negative.h"

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

const Image image({{Pixel(0, 10, 20), Pixel(30, 40, 50), Pixel(60, 70, 80)},
                   {Pixel(90, 100, 110), Pixel(120, 130, 140), Pixel(150, 160, 170)},
                   {Pixel(180, 190, 200), Pixel(210, 220, 230), Pixel(240, 250, 0)}});
}  // namespace

TEST_CASE("Crop") {
    Image image1 = image;
    Crop crop1(4, 2);
    crop1.Apply(image1);
    Image expected1({{Pixel(0, 10, 20), Pixel(30, 40, 50)},
                     {Pixel(90, 100, 110), Pixel(120, 130, 140)},
                     {Pixel(180, 190, 200), Pixel(210, 220, 230)}});
    REQUIRE(ImagesAreEqual(image1, expected1));

    Image image2 = image;
    Crop crop2(2, 2);
    crop2.Apply(image2);
    Image expected2({{Pixel(90, 100, 110), Pixel(120, 130, 140)}, {Pixel(180, 190, 200), Pixel(210, 220, 230)}});
    REQUIRE(ImagesAreEqual(image2, expected2));
}

TEST_CASE("Grayscale") {
    Image image1 = image;
    Grayscale gs;
    gs.Apply(image1);
    Image expected1({{Pixel(8, 8, 8), Pixel(38, 38, 38), Pixel(68, 68, 68)},
                     {Pixel(98, 98, 98), Pixel(128, 128, 128), Pixel(158, 158, 158)},
                     {Pixel(188, 188, 188), Pixel(218, 218, 218), Pixel(218, 218, 218)}});
    REQUIRE(ImagesAreEqual(image1, expected1));
}

TEST_CASE("Negative") {
    Image image1 = image;
    Negative neg;
    neg.Apply(image1);
    Image expected1({{Pixel(255, 245, 235), Pixel(225, 215, 205), Pixel(195, 185, 175)},
                     {Pixel(165, 155, 145), Pixel(135, 125, 115), Pixel(105, 95, 85)},
                     {Pixel(75, 65, 55), Pixel(45, 35, 25), Pixel(15, 5, 255)}});
    REQUIRE(ImagesAreEqual(image1, expected1));
}

TEST_CASE("Sharpening") {
    Image image1 = image;
    Sharpening sharp;
    sharp.Apply(image1);
    Image expected1({{Pixel(0, 0, 0), Pixel(0, 0, 0), Pixel(0, 10, 20)},
                     {Pixel(60, 70, 80), Pixel(120, 130, 140), Pixel(180, 190, 255)},
                     {Pixel(240, 250, 255), Pixel(255, 255, 255), Pixel(255, 255, 0)}});
    REQUIRE(ImagesAreEqual(image1, expected1));
}

TEST_CASE("Edge") {
    Image image1 = image;
    Edge edge(0.05);
    edge.Apply(image1);
    Image expected1({{Pixel(0, 0, 0), Pixel(0, 0, 0), Pixel(0, 0, 0)},
                     {Pixel(0, 0, 0), Pixel(0, 0, 0), Pixel(255, 255, 255)},
                     {Pixel(255, 255, 255), Pixel(255, 255, 255), Pixel(255, 255, 255)}});
    REQUIRE(ImagesAreEqual(image1, expected1));
}

TEST_CASE("Blur") {
    Image image1 = image;
    Blur blur(1);
    blur.Apply(image1);
    Image expected1({{Pixel(62, 72, 74), Pixel(76, 87, 80), Pixel(91, 101, 81)},
                     {Pixel(104, 114, 109), Pixel(119, 130, 107), Pixel(134, 144, 94)},
                     {Pixel(147, 157, 138), Pixel(162, 172, 122), Pixel(176, 186, 87)}});
    REQUIRE(ImagesAreEqual(image1, expected1));
}
