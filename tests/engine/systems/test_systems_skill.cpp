#include <catch2/catch_test_macros.hpp>
#include "core/state/game_state.hpp"
#include "engine/systems/systems.hpp"

TEST_CASE("Systems_skill: decrements cooldownRemaining when greater than 0")
{
    GameState gs(1u);
    const EntityId e = gs.create_entity();
    auto &s = gs.skill[gs.index_of(e)];

    s.cooldownRemaining = 3;
    systems::skill_system(gs);
    REQUIRE(s.cooldownRemaining == 2);

    systems::skill_system(gs);
    REQUIRE(s.cooldownRemaining == 1);

    systems::skill_system(gs);
    REQUIRE(s.cooldownRemaining == 0);

    systems::skill_system(gs);
    REQUIRE(s.cooldownRemaining == 0);
}
