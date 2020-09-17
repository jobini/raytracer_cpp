#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "matrix.h"
#include "consts.h"
#include "tuple.h"

using TupleClass::Tuple;

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

TEST_CASE("Matrix equality with identical matrices"){
    GIVEN("Two matrices A and B"){
        Matrix A = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 8, 7, 6}, {5, 4, 3, 2}};
        Matrix B = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 8, 7, 6}, {5, 4, 3, 2}};

        REQUIRE(A == B);
    }
}

TEST_CASE("Matrix equality with different matrices"){
    GIVEN("Two matrices A and B"){
        Matrix A = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 8, 7, 6}, {5, 4, 3, 2}};
        Matrix B = {{2, 3, 4, 5}, {6, 7, 8, 9}, {8, 7, 6, 5}, {4, 3, 2, 1}};

        REQUIRE(A != B);
    }
}

TEST_CASE("Matrix equality with matrices having different number of rows"){
    GIVEN("Two matrices A and B"){
        Matrix A = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 8, 7, 6}, {5, 4, 3, 2}};
        Matrix B = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 8, 7, 6}};

        REQUIRE(A != B);
    }
}

TEST_CASE("Matrix equality with matrices having different number of columns"){
    GIVEN("Two matrices A and B"){
        Matrix A = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 8, 7, 6}, {5, 4, 3, 2}};
        Matrix B = {{1, 2, 3}, {5, 6, 7}, {9, 8, 7}, {5, 4, 3}};
        REQUIRE(A != B);
    }
}

TEST_CASE("Multiplying two matrices"){
    GIVEN("Two matrices A and B"){
        Matrix A = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 8, 7, 6}, {5, 4, 3, 2}};
        Matrix B = {{-2, 1, 2, 3}, {3, 2, 1, -1}, {4, 3, 6, 5}, {1, 2, 7, 8}};
        Matrix C = A.mm(B);
        REQUIRE(A.mm(B) == Matrix({{20, 22, 50, 48}, {44, 54, 114, 108}, {40, 58, 110, 102}, {16, 26, 46, 42}}));
    }
}

TEST_CASE("Multiplying two matrices (uneven dimensions)"){
    GIVEN("Two matrices A and B"){
        Matrix A = {{1, 2, 3}, {-4, -5, -6}};
        Matrix B = {{7, 8}, {-9, -10}, {11, 12}};
        REQUIRE(A.mm(B) == Matrix({{22, 24}, {-49, -54}}));
    }
}

TEST_CASE("Multiplying a matrix with a tuple"){
    GIVEN("A matrices A and a Tuple t"){
        Matrix A = {{1, 2, 3, 4}, {2, 4, 4, 2}, {8, 6, 4, 1}, {0, 0, 0, 1}};
        Tuple t(1, 2, 3, 1);
        REQUIRE(A.mm(t) == Tuple(18, 24, 33, 1));
    }
}

TEST_CASE("Multiplying a matrix with the identity matrix"){
    GIVEN("A matrices A and the identity matrix"){
        Matrix A = {{0, 1, 2, 4}, {1, 2, 4, 8}, {2, 4, 8, 16}, {4, 8, 16, 32}};
        Matrix identity_matrix = {{1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 0},{0, 0, 0, 1}};
        REQUIRE(A.mm(identity_matrix) == A);
    }
}

TEST_CASE("Transposing a matrix"){
    GIVEN("A matrices A"){
        Matrix A = {{0, 9, 3, 0}, {9, 8, 0, 8}, {1, 8, 5, 3}, {0, 0, 5, 8}};
        REQUIRE(A.transpose() == Matrix({{0, 9, 1, 0}, {9, 8, 8, 0}, {3, 0, 5, 5}, {0, 8, 3, 8}}));
    }
}

TEST_CASE("Transposing the identity matrix"){
    GIVEN("The identity matrix"){
        Matrix identity_matrix = {{1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 0},{0, 0, 0, 1}};
        REQUIRE(identity_matrix.transpose() == identity_matrix);
    }
}

TEST_CASE("Calculating the determinant of a 2x2 matrix"){
    GIVEN("A 2x2 matrix"){
        Matrix A = {{1, 5}, {-3, 2}};
        REQUIRE(determinant(A) == 17);
    }
}

TEST_CASE("A submatrix of a 3x3 matrix is a 2x2 matrix"){
    GIVEN("A 3x3 matrix"){
        Matrix A = {{1, 5, 0}, {-3, 2, 7}, {0, 6, -3}};
        REQUIRE(A.submatrix(0, 2) == Matrix({{-3, 2}, {0, 6}}));
    }
}
