#include <catch.hpp>

#include "image/pixel.h"

TEST_CASE("PixelConstructor") {
    Pixel p1;
    REQUIRE(p1.Red() == 0);
    REQUIRE(p1.Green() == 0);
    REQUIRE(p1.Blue() == 0);

    Pixel p2(255, 0, 239);
    REQUIRE(p2.Red() == 255);
    REQUIRE(p2.Green() == 0);
    REQUIRE(p2.Blue() == 239);

    Pixel p3 = Pixel(179.0, 232.0, 3.0);
    REQUIRE(p3.Red() == 179);
    REQUIRE(p3.Green() == 232);
    REQUIRE(p3.Blue() == 3);
}

TEST_CASE("PixelAssignment") {
    Pixel p1;
    p1 = Pixel(32, 255, 0);
    REQUIRE(p1.Red() == 32);
    REQUIRE(p1.Green() == 255);
    REQUIRE(p1.Blue() == 0);

    Pixel p2(255, 0, 239);
    p1 = p2;
    REQUIRE(p1.Red() == 255);
    REQUIRE(p1.Green() == 0);
    REQUIRE(p1.Blue() == 239);
}
