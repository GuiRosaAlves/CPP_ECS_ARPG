#include <catch2/catch_test_macros.hpp>
#include "core/state/game_state.hpp"

TEST_CASE("GameState: create entities and validates component storage size")
{
    GameState gs(1u);

    const EntityId e1 = gs.create_entity();
    REQUIRE(e1 == 1);
    REQUIRE(gs.valid(e1));

    const EntityId e2 = gs.create_entity();
    REQUIRE(e2 == 2);
    REQUIRE(gs.valid(e2));

    REQUIRE(gs.health.size() == 2);
    REQUIRE(gs.mana.size() == 2);
    REQUIRE(gs.pos.size() == 2);
    REQUIRE(gs.skill.size() == 2);
    REQUIRE(gs.buff.size() == 2);
}

TEST_CASE("GameState: indexof returns a 0 based index")
{
    GameState gs(1u);
    const EntityId e1 = gs.create_entity();
    const EntityId e2 = gs.create_entity();

    REQUIRE(gs.index_of(e1) == 0);
    REQUIRE(gs.index_of(e2) == 1);
}

TEST_CASE("GameState: rejects invalid entity ids")
{
    GameState gs(1u);

    REQUIRE_FALSE(gs.valid(kInvalidEntity));
    REQUIRE_FALSE(gs.valid(1)); // no entities yet

    const EntityId e = gs.create_entity();
    REQUIRE(gs.valid(e));

    REQUIRE_FALSE(gs.valid(9999));
}
