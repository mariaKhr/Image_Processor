#include <catch.hpp>

#include "../matrix/matrix.h"

TEST_CASE("Constructor") {
    Matrix<int> m1;
    REQUIRE(m1.Height() == 0);
    REQUIRE(m1.Width() == 0);

    Matrix<float> m2(0, 10000);
    REQUIRE(m2.Height() == 0);
    REQUIRE(m2.Width() == 0);

    Matrix<double> m3(0, 0);
    REQUIRE(m3.Height() == 0);
    REQUIRE(m3.Width() == 0);

    Matrix<int> m4(2, 4);
    REQUIRE(m4.Height() == 2);
    REQUIRE(m4.Width() == 4);

    std::vector<std::vector<int>> v = {{}, {}, {}};
    Matrix<int> m5(v);
    REQUIRE(m5.Height() == 0);
    REQUIRE(m5.Width() == 0);

    v = {{2, 5}, {-23, 7}, {31, -7}};
    Matrix<int> m6(v);
    REQUIRE(m6.Height() == 3);
    REQUIRE(m6.Width() == 2);

    v.clear();
    Matrix<int> m7(v);
    REQUIRE(m7.Height() == 0);
    REQUIRE(m7.Width() == 0);

    v = {{}, {2}, {-5}, {8}};
    REQUIRE_THROWS(Matrix<int>(v));
}

TEST_CASE("At") {
    Matrix<int> m({{2, 5}, {-23, 7}, {0, -7}});
    REQUIRE(m.At(0, 0) == 2);
    REQUIRE(m.At(0, 1) == 5);
    REQUIRE(m.At(1, 0) == -23);
    REQUIRE(m.At(1, 1) == 7);
    REQUIRE(m.At(2, 0) == 0);
    REQUIRE(m.At(2, 1) == -7);

    REQUIRE_THROWS(m.At(0, 2));
    REQUIRE_THROWS(m.At(4, 1));

    m.At(2, 0) = 15;
    REQUIRE(m.At(2, 0) == 15);
}

TEST_CASE("Transposed") {
    Matrix<int> m({{2, 5}, {-23, 7}, {0, -7}});
    Matrix<int> expected({{2, -23, 0}, {5, 7, -7}});

    REQUIRE(m.Transposed().Height() == 2);
    REQUIRE(m.Transposed().Width() == 3);

    for (size_t i = 0; i < 2; ++i) {
        for (size_t j = 0; j < 3; ++j) {
            REQUIRE(m.Transposed().At(i, j) == expected.At(i, j));
        }
    }
}

TEST_CASE("CoefSum") {
    Matrix<int> m1({{2, 5}, {-23, 7}, {0, -7}});
    REQUIRE(m1.CoefSum() == -16);

    Matrix<float> m2(3, 8);
    REQUIRE(m2.CoefSum() == 0);
}
