#include <catch.hpp>

#include "../image/image.h"

TEST_CASE("Constructor") {
    Pixel p1(0, 27, 192);
    Pixel p2(166, 1, 255);
    Pixel p3(12, 200, 101);
    Image image1({{p1}, {p2}, {p3}});
    REQUIRE(image1.Height() == 3);
    REQUIRE(image1.Width() == 1);

    Image image2(7, 23);
    REQUIRE(image2.Height() == 7);
    REQUIRE(image2.Width() == 23);

    Image image3(100, 0);
    REQUIRE(image3.Height() == 0);
    REQUIRE(image3.Width() == 0);
}

TEST_CASE("At") {
    Image image2(1, 3);
    Pixel p1(0, 27, 192);
    Pixel p2(166, 1, 255);
    image2.At(0, 0) = p1;
    image2.At(0, 2) = p2;

    REQUIRE(image2.At(0, 0).Red() == 0);
    REQUIRE(image2.At(0, 0).Green() == 27);
    REQUIRE(image2.At(0, 0).Blue() == 192);
    REQUIRE(image2.At(0, 1).Red() == 0);
    REQUIRE(image2.At(0, 1).Green() == 0);
    REQUIRE(image2.At(0, 1).Blue() == 0);
    REQUIRE(image2.At(0, 2).Red() == 166);
    REQUIRE(image2.At(0, 2).Green() == 1);
    REQUIRE(image2.At(0, 2).Blue() == 255);
}
