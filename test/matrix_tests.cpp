#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "matrix.h"
#include "consts.h"

TEST_CASE("Constructing and inspecting a 4x4 matrix"){
    GIVEN("A 4x4 matrix M"){
        Matrix M = {{1, 2, 3 ,4}, {5.5, 6.5, 7.5, 8.5}, {9, 10, 11, 12}, {13.5, 14.5, 15.5, 16.5}};

        REQUIRE(M[0][0] == Approx(1).margin(EPSILON));
        REQUIRE(M[0][3] == Approx(4).margin(EPSILON));
        REQUIRE(M[1][0] == Approx(5.5).margin(EPSILON));
        REQUIRE(M[1][2] == Approx(7.5).margin(EPSILON));
        REQUIRE(M[2][2] == Approx(11).margin(EPSILON));
        REQUIRE(M[3][0] == Approx(13.5).margin(EPSILON));
        REQUIRE(M[3][2] == Approx(15.5).margin(EPSILON));
    }
}

TEST_CASE("A 2x2 matrix ought to be representable"){
    GIVEN("A 2x2 matrix M"){
        Matrix M = {{-3, 5}, {1, -2}};

        REQUIRE(M[0][0] == Approx(-3).margin(EPSILON));
        REQUIRE(M[0][1] == Approx(5).margin(EPSILON));
        REQUIRE(M[1][0] == Approx(1).margin(EPSILON));
        REQUIRE(M[1][1] == Approx(-2).margin(EPSILON));
    }
}

TEST_CASE("A 3x3 matrix ought to be representable"){
    GIVEN("A 3x3 matrix M"){
        Matrix M = {{-3, 5, 0}, {1, -2, -7}, {0, 1, 1}};

        REQUIRE(M[0][0] == Approx(-3).margin(EPSILON));
        REQUIRE(M[1][1] == Approx(-2).margin(EPSILON));
        REQUIRE(M[2][2] == Approx(1).margin(EPSILON));
    }
}
