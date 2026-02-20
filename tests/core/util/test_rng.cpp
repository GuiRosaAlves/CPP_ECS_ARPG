#include <catch2/catch_test_macros.hpp>
#include "core/util/rng.hpp"

TEST_CASE("Rng: same seed produces same sequence")
{
    Rng r1(123u);
    Rng r2(123u);

    for (int i = 0; i < 100; ++i)
    {
        REQUIRE(r1.next_u32() == r2.next_u32());
    }
}

TEST_CASE("Rng: different seeds produce different sequences")
{
    Rng r1(123u);
    Rng r2(124u);
    REQUIRE(r1.next_u32() != r2.next_u32());
}

TEST_CASE("Rng: range_int produces values within the specified range")
{
    Rng r(1u);
    for (int i = 0; i < 200; ++i)
    {
        const int v = r.range_int(-3, 7);
        REQUIRE(v >= -3);
        REQUIRE(v <= 7);
    }
}

TEST_CASE("Rng: range_int with max < min returns min")
{
    Rng r(1u);
    REQUIRE(r.range_int(10, 2) == 10);
}
