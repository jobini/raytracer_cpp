#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "tuple.h"
#include <cmath>

TEST_CASE("A tuple with w = 1.0 is a point."){
    GIVEN ("A tuple with w = 1.0"){
        Tuple a = Tuple(4.3, -4.2, 3.1, 1.0);

        REQUIRE(a.x == Approx(4.3).margin(1e-6));
        REQUIRE(a.y == Approx(-4.2).margin(1e-6));
        REQUIRE(a.z == Approx(3.1).margin(1e-6));
        REQUIRE(a.w == Approx(1.0).margin(1e-6));
        REQUIRE(a.isPoint() == true);
        REQUIRE(a.isVector() == false);
    }
}

TEST_CASE("A tuple with w = 0.0 is a vector."){
    GIVEN("A tuple with w = 0.0"){
        Tuple a = Tuple(4.3, -4.2, 3.1, 0.0);

        REQUIRE(a.x == Approx(4.3).margin(1e-6));
        REQUIRE(a.y == Approx(-4.2).margin(1e-6));
        REQUIRE(a.z == Approx(3.1).margin(1e-6));
        REQUIRE(a.w == Approx(0.0).margin(1e-6));
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

TEST_CASE("Subtracting a vector from a point"){
    GIVEN ("A point p = (3, 2, 1) and a vector v = (5, 6, 7)"){
        Tuple p = point(3, 2, 1);
        Tuple v = vector(5, 6, 7);

        REQUIRE((p - v) == point(-2, -4, -6));
    }
}

TEST_CASE("Subtracting two vectors"){
    GIVEN ("Two vectors v1 = (3, 2, 1) and v2 = (5, 6, 7)"){
        Tuple v1 = vector(3, 2, 1);
        Tuple v2 = vector(5, 6, 7);

        REQUIRE((v1 - v2) == vector(-2, -4, -6));
    }
}

TEST_CASE("Subtracting a vector from the zero vector"){
    GIVEN ("A vector v = (1, -2, 3)"){
        Tuple zero = vector(0, 0, 0);
        Tuple v = vector(1, -2, 3);

        REQUIRE((zero - v) == vector(-1, 2, -3));
    }
}

TEST_CASE("Negating a tuple"){
    GIVEN ("A tuple a = (1, -2, 3, -4)"){
        Tuple a = Tuple(1, -2, 3, -4);

        REQUIRE(-a == Tuple(-1, 2, -3, 4));
    }
}

TEST_CASE("Multiplying a tuple by a scalar"){
    GIVEN ("A tuple a = (1, -2, 3, -4)"){
        Tuple a = Tuple(1, -2, 3, -4);
        REQUIRE(a * 3.5 == Tuple(3.5, -7, 10.5, -14));
    }
}

TEST_CASE("Multiplying a tuple by a fraction"){
    GIVEN ("A tuple a = (1, -2, 3, -4)"){
        Tuple a = Tuple(1, -2, 3, -4);
        REQUIRE(a * 0.5 == Tuple(0.5, -1, 1.5, -2));
    }
}

TEST_CASE("Dividing a tuple by a scalar"){
    GIVEN ("A tuple a = (1, -2, 3, -4)"){
        Tuple a = Tuple(1, -2, 3, -4);
        REQUIRE(a / 2 == Tuple(0.5, -1, 1.5, -2));
    }
}

TEST_CASE("Computing the magnitude of (1, 0, 0)"){
    GIVEN ("A vector a = (1, 0, 0)"){
        Tuple a = vector(1, 0, 0);
        REQUIRE(magnitude(a) == Approx(1).margin(1e-6));
    }
}

TEST_CASE("Computing the magnitude of (0, 1, 0)"){
    GIVEN ("A vector a = (0, 1, 0)"){
        Tuple a = vector(0, 1, 0);
        REQUIRE(magnitude(a) == Approx(1).margin(1e-6));
    }
}

TEST_CASE("Computing the magnitude of (0, 0, 1)"){
    GIVEN ("A vector a = (0, 0, 1)"){
        Tuple a = vector(0, 0, 1);
        REQUIRE(magnitude(a) == Approx(1).margin(1e-6));
    }
}

TEST_CASE("Computing the magnitude of (1, 2, 3)"){
    GIVEN ("A vector a = (1, 2, 3)"){
        Tuple a = vector(1, 2, 3);
        REQUIRE(magnitude(a) == Approx(sqrt(14)).margin(1e-6));
    }
}

TEST_CASE("Computing the magnitude of (-1, -2, -3)"){
    GIVEN ("A vector a = (-1, -2, -3)"){
        Tuple a = vector(-1, -2, -3);
        REQUIRE(magnitude(a) == Approx(sqrt(14)).margin(1e-6));
    }
}

TEST_CASE("Normalizing vector (4, 0, 0)"){
    GIVEN ("A vector v = (4, 0, 0)"){
        Tuple v = vector(4, 0, 0);
        REQUIRE(normalize(v) == vector(1, 0, 0));
    }
}

TEST_CASE("Normalizing vector (1, 2, 3)"){
    GIVEN ("A vector v = (1, 2, 3)"){
        Tuple v = vector(1, 2, 3);
        REQUIRE(normalize(v) == vector(1./sqrt(14), 2/sqrt(14), 3/sqrt(14)));
    }
}

TEST_CASE("The magnitude of a normalized vector"){
    GIVEN ("A vector v = (1, 2, 3)"){
        Tuple v = vector(1, 2, 3);
        WHEN("v is normalized"){
            Tuple norm = normalize(v);
            THEN("the magnitude of norm = 1"){
                REQUIRE(magnitude(norm) == Approx(1).margin(1e-6));
            }
        }
    }
}