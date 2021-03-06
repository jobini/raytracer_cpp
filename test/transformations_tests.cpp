#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "tuple.h"
#include "transformations.h"

using TransformationsClass::translation;
using TransformationsClass::scaling;
using TransformationsClass::rotation_x;
using TransformationsClass::rotation_y;
using TransformationsClass::rotation_z;
using TransformationsClass::shearing;
using TupleClass::point;
using TupleClass::vector;
using TupleClass::Tuple;
using MatrixClass::inverse;
using MatrixClass::Matrix;

TEST_CASE("Multiplying by a translation matrix"){
    GIVEN("A translation and a point"){
        Matrix transform = translation(5, -3, 2);
        Tuple p = point(-3, 4, 5);
        REQUIRE(transform.mm(p) == point(2, 1, 7));
    }
}

TEST_CASE("Multiplying by the inverse of a translation matrix"){
    GIVEN("A translation, its inverse, and a point"){
        Matrix transform = translation(5, -3, 2);
        Matrix inv = inverse(transform);
        Tuple p = point(-3, 4, 5);
        REQUIRE(inv.mm(p) == point(-8, 7, 3));
    }
}

TEST_CASE("Translation does not affect vectors"){
    GIVEN("A translation and a vector"){
        Matrix transform = translation(5, -3, 2);
        Tuple v = vector(-3, 4, 5);
        REQUIRE(transform.mm(v) == v);
    }
}


TEST_CASE("A scaling matrix applied to a point"){
    GIVEN("A scaling matrix and a point"){
        Matrix transform = scaling(2, 3, 4);
        Tuple p = point(-4, 6, 8);
        REQUIRE(transform.mm(p) == point(-8, 18, 32));
    }
}

TEST_CASE("A scaling matrix applied to a vector"){
    GIVEN("A scaling matrix and a vector"){
        Matrix transform = scaling(2, 3, 4);
        Tuple v = vector(-4, 6, 8);
        REQUIRE(transform.mm(v) == vector(-8, 18, 32));
    }
}

TEST_CASE("Multiplying by the inverse of a scaling matrix"){
    GIVEN("A scaling matrix, its inverse, and a vector"){
        Matrix transform = scaling(2, 3, 4);
        Matrix inv = inverse(transform);
        Tuple v = vector(-4, 6, 8);
        REQUIRE(inv.mm(v) == vector(-2, 2, 2));
    }
}

TEST_CASE("Reflection is scaling by a negative value"){
    GIVEN("A scaling matrix for reflection and a point"){
        Matrix transform = scaling(-1, 1, 1);
        Tuple p = point(2, 3, 4);
        REQUIRE(transform.mm(p) == point(-2, 3, 4));
    }
}

TEST_CASE("Rotating a point around the x-axis"){
    GIVEN("A point and two rotation matrices"){
        Tuple p = point(0, 1, 0);
        Matrix half_quarter = rotation_x(M_PI/4);
        Matrix full_quarter = rotation_x(M_PI/2);

        REQUIRE(half_quarter.mm(p) == point(0, sqrt(2)/2, sqrt(2)/2));
        REQUIRE(full_quarter.mm(p) == point(0, 0, 1));
    }
}

TEST_CASE("The inverse of an x-rotation rotates in the opposite direction"){
    GIVEN("A point and a rotation matrix"){
        Tuple p = point(0, 1, 0);
        Matrix half_quarter = rotation_x(M_PI/4);
        Matrix inv = inverse(half_quarter);

        REQUIRE(inv.mm(p) == point(0, sqrt(2)/2, -sqrt(2)/2));
    }
}

TEST_CASE("Rotating a point around the y-axis"){
    GIVEN("A point and two rotation matrices"){
        Tuple p = point(0, 0, 1);
        Matrix half_quarter = rotation_y(M_PI/4);
        Matrix full_quarter = rotation_y(M_PI/2);

        REQUIRE(half_quarter.mm(p) == point(sqrt(2)/2, 0, sqrt(2)/2));
        REQUIRE(full_quarter.mm(p) == point(1, 0, 0));
    }
}

TEST_CASE("Rotating a point around the z-axis"){
    GIVEN("A point and two rotation matrices"){
        Tuple p = point(0, 1, 0);
        Matrix half_quarter = rotation_z(M_PI/4);
        Matrix full_quarter = rotation_z(M_PI/2);

        REQUIRE(half_quarter.mm(p) == point(-sqrt(2)/2, sqrt(2)/2, 0));
        REQUIRE(full_quarter.mm(p) == point(-1, 0, 0));
    }
}

TEST_CASE("A shearing transformation moves x in proportion to y"){
    GIVEN("A point and a shearing matrix"){
        Tuple p = point(2, 3, 4);
        Matrix transform = shearing(1, 0, 0, 0, 0, 0);

        REQUIRE(transform.mm(p) == point(5, 3, 4));
    }
}

TEST_CASE("A shearing transformation moves x in proportion to z"){
    GIVEN("A point and a shearing matrix"){
        Tuple p = point(2, 3, 4);
        Matrix transform = shearing(0, 1, 0, 0, 0, 0);

        REQUIRE(transform.mm(p) == point(6, 3, 4));
    }
}

TEST_CASE("A shearing transformation moves y in proportion to x"){
    GIVEN("A point and a shearing matrix"){
        Tuple p = point(2, 3, 4);
        Matrix transform = shearing(0, 0, 1, 0, 0, 0);

        REQUIRE(transform.mm(p) == point(2, 5, 4));
    }
}

TEST_CASE("A shearing transformation moves y in proportion to z"){
    GIVEN("A point and a shearing matrix"){
        Tuple p = point(2, 3, 4);
        Matrix transform = shearing(0, 0, 0, 1, 0, 0);

        REQUIRE(transform.mm(p) == point(2, 7, 4));
    }
}

TEST_CASE("A shearing transformation moves z in proportion to x"){
    GIVEN("A point and a shearing matrix"){
        Tuple p = point(2, 3, 4);
        Matrix transform = shearing(0, 0, 0, 0, 1, 0);

        REQUIRE(transform.mm(p) == point(2, 3, 6));
    }
}

TEST_CASE("A shearing transformation moves z in proportion to y"){
    GIVEN("A point and a shearing matrix"){
        Tuple p = point(2, 3, 4);
        Matrix transform = shearing(0, 0, 0, 0, 0, 1);

        REQUIRE(transform.mm(p) == point(2, 3, 7));
    }
}

TEST_CASE("Individual transformations are applied in sequence"){
    GIVEN("A point and three transformation matrices"){
        Tuple p = point(1, 0, 1);
        Matrix A = rotation_x(M_PI/2);
        Matrix B = scaling(5, 5, 5);
        Matrix C = translation(10, 5, 7);

        Tuple p2 = A.mm(p);
        REQUIRE(p2 == point(1, -1, 0));

        Tuple p3 = B.mm(p2);
        REQUIRE(p3 == point(5, -5, 0));

        Tuple p4 = C.mm(p3);
        REQUIRE(p4 == point(15, 0, 7));
    }
}

TEST_CASE("Chained transformations must be applied in reverse order"){
    GIVEN("A point and three transformation matrices"){
        Tuple p = point(1, 0, 1);
        Matrix A = rotation_x(M_PI/2);
        Matrix B = scaling(5, 5, 5);
        Matrix C = translation(10, 5, 7);

        Matrix T = C.mm(B.mm(A));
        REQUIRE(T.mm(p) == point(15, 0, 7));
    }
}