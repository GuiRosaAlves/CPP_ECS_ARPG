#include <catch2/catch_test_macros.hpp>
#include "core/state/entity.hpp"

TEST_CASE("Entity: false for invalid id, true for valid id")
{
    Entity a{};
    REQUIRE_FALSE(a.valid());

    Entity b{1};
    REQUIRE(b.valid());
}
