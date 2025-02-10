#include "vector.hpp"

#include "catch_amalgamated.hpp"
// #include <catch2/matchers/catch_matchers_floating_point.hpp>

using geometry::Vector;

// for comparing floating point values
static const double EPSILON = 0.00001;  // absolute difference
static const double MARGIN = 0.001;  // 0.1% relative difference


TEST_CASE("...", "[tag]") {
  CHECK(true);

  SECTION("ChildAccount cannot be overdrawn") {
    REQUIRE(true);
  }
}


TEST_CASE("Construction", "[vector]") {
    Vector v1;
    REQUIRE(v1.x == 0);
    REQUIRE(v1.y == 0);
    REQUIRE(v1.z == 0);
    REQUIRE_THAT(v1.x, Catch::Matchers::WithinRel(0, MARGIN) ||
                       Catch::Matchers::WithinAbs(0, EPSILON) );
    REQUIRE_THAT(v1.y, Catch::Matchers::WithinRel(0, MARGIN) ||
                       Catch::Matchers::WithinAbs(0, EPSILON) );
    REQUIRE_THAT(v1.z, Catch::Matchers::WithinRel(0, MARGIN) ||
                       Catch::Matchers::WithinAbs(0, EPSILON) );

    Vector v2(1, -2.55, 3);
    REQUIRE_THAT(v1.x, Catch::Matchers::WithinRel(1, MARGIN) ||
                       Catch::Matchers::WithinAbs(1, EPSILON) );
    REQUIRE_THAT(v1.y, Catch::Matchers::WithinRel(-2.55, MARGIN) ||
                       Catch::Matchers::WithinAbs(-2.55, EPSILON) );
    REQUIRE_THAT(v1.z, Catch::Matchers::WithinRel(3, MARGIN) ||
                       Catch::Matchers::WithinAbs(3, EPSILON) );
}

TEST_CASE("Vector Addition", "[vector]") {
    Vector a(1, 2, 3);
    Vector b(4, 5, 6);
    Vector c = a + b;
    REQUIRE(c.getX() == 5);
    REQUIRE(c.getY() == 7);
    REQUIRE(c.getZ() == 9);
}

TEST_CASE("Vector Subtraction", "[vector]") {
    Vector a(4, 5, 6);
    Vector b(1, 2, 3);
    Vector c = a - b;
    REQUIRE(c.getX() == 3);
    REQUIRE(c.getY() == 3);
    REQUIRE(c.getZ() == 3);
}

TEST_CASE("Scalar Multiplication", "[vector]") {
    Vector a(1, 2, 3);
    Vector b = a * 2.5;
    REQUIRE(b.getX() == 2.5);
    REQUIRE(b.getY() == 5);
    REQUIRE(b.getZ() == 7.5);
}

TEST_CASE("Dot Product", "[vector]") {
    Vector a(1, 2, 3);
    Vector b(4, 5, 6);
    double dot_product = a * b;
    REQUIRE(dot_product == 32);
}

TEST_CASE("Cross Product", "[vector]") {
    Vector a(1, 0, 0);
    Vector b(0, 1, 0);
    Vector c = a.crossProduct(b);
    REQUIRE(c.getX() == 0);
    REQUIRE(c.getY() == 0);
    REQUIRE(c.getZ() == 1);

    Vector d(1, 2, 3);
    Vector e(4, 5, 6);
    Vector f = d.crossProduct(e);
    REQUIRE(f.getX() == -3);
    REQUIRE(f.getY() == 6);
    REQUIRE(f.getZ() == -3);
}

TEST_CASE("Magnitude", "[vector]") {
    Vector a(3, 4, 0);
    REQUIRE(a.magnitude() == 5);

    Vector b(1, 2, 2);
    REQUIRE(std::abs(b.magnitude() - 3) < 0.00001); // Account for floating-point errors
}

TEST_CASE("Output Stream Operator", "[vector]") {
    Vector a(1, 2, 3);
    std::stringstream ss;
    ss << a;
    REQUIRE(ss.str() == "(1, 2, 3)");
}


TEST_CASE("Zero Vector Operations", "[vector]") {
    Vector zero;
    Vector a(1, 2, 3);

    Vector sum = zero + a;
    REQUIRE(sum == a); // Check for component-wise equality

    Vector diff = a - zero;
    REQUIRE(diff == a);

    double dot = zero * a;
    REQUIRE(dot == 0);

    Vector cross = zero.crossProduct(a);
    REQUIRE(cross == zero);

    REQUIRE(zero.magnitude() == 0);
}

TEST_CASE("Parallel Vectors Cross Product", "[vector]") {
    Vector a(1, 2, 3);
    Vector b = a * 2.0; // b is parallel to a

    Vector cross = a.crossProduct(b);
    REQUIRE(cross.magnitude() == 0); // Cross product of parallel vectors is zero
}

TEST_CASE("Large Vector Operations", "[vector]") {
    Vector a(1000, 2000, 3000);
    Vector b(4000, 5000, 6000);

    Vector sum = a + b;
    REQUIRE(sum.getX() == 5000);
    REQUIRE(sum.getY() == 7000);
    REQUIRE(sum.getZ() == 9000);

    double dot = a * b;
    REQUIRE(dot == 32000000);
}

// Comparison operator overloading (add to Vector class)
bool operator==(const Vector& a, const Vector& b) {
    return a.getX() == b.getX() && a.getY() == b.getY() && a.getZ() == b.getZ();
}

TEST_CASE("Vector Equality", "[vector]") {
    Vector a(1, 2, 3);
    Vector b(1, 2, 3);
    Vector c(4, 5, 6);

    REQUIRE(a == b);
    REQUIRE(a != c); // Assuming you also implement !=
}
