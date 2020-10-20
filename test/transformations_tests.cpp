#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "tuple.h"
#include "transformations.h"

using TransformationsClass::translation;
using TransformationsClass::scaling;
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

