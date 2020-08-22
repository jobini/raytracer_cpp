#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "tuple.h"

TEST_CASE("A tuple with w = 1.0 is a point, and with w = 0.0 is a vector."){
    GIVEN ("A tuple with w = 1.0"){
        Tuple a = Tuple(4.3, -4.2, 3.1, 1.0);

        REQUIRE(a.x == Approx(4.3).margin(1e-12));
        REQUIRE(a.y == Approx(-4.2).margin(1e-12));
        REQUIRE(a.z == Approx(3.1).margin(1e-12));
        REQUIRE(a.w == Approx(1.0).margin(1e-12));
        REQUIRE(a.isPoint() == true);
        REQUIRE(a.isVector() == false);
    }

    GIVEN("A tuple with w = 0.0"){
        Tuple a = Tuple(4.3, -4.2, 3.1, 0.0);

        REQUIRE(a.x == Approx(4.3).margin(1e-12));
        REQUIRE(a.y == Approx(-4.2).margin(1e-12));
        REQUIRE(a.z == Approx(3.1).margin(1e-12));
        REQUIRE(a.w == Approx(0.0).margin(1e-12));
        REQUIRE(a.isPoint() == false);
        REQUIRE(a.isVector() == true);
    }
}

TEST_CASE("point() creates tuples with w = 1.0"){
    GIVEN("A point created using the point function"){
        Tuple a = point(4, -4, 3);
        REQUIRE(a == Tuple(4, -4, 3, 1));
    }
}

TEST_CASE("vector() creates tuples with w = 0.0"){
    GIVEN("A vector created using the vector function"){
        Tuple a = vector(4, -4, 3);
        REQUIRE(a == Tuple(4, -4, 3, 0));
    }
}

TEST_CASE("Adding two tuples"){
    GIVEN ("Two tuples a1 = (3, -2, 5, 1) and a2 = (-2, 3, 1, 0)"){
        Tuple a1 = Tuple(3, -2, 5, 1);
        Tuple a2 = Tuple(-2, 3, 1, 0);

        REQUIRE((a1 + a2) == Tuple(1, 1, 6, 1));
        REQUIRE((a1 += a2) == Tuple(1, 1, 6, 1));
    }
}

TEST_CASE("Subtracting two points"){
    GIVEN ("Two points p1 = (3, 2, 1) and p2 = (5, 6, 7)"){
        Tuple p1 = point(3, 2, 1);
        Tuple p2 = point(5, 6, 7);

        REQUIRE((p1 - p2) == vector(-2, -4, -6));
        REQUIRE((p1 -= p2) == vector(-2, -4, -6));
    }
}