#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "tuple.h"
#include "transformations.h"

using TransformationsClass::translation;
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

